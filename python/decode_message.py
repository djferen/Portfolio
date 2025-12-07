import sys

DEBUG = False

def dprint(message = ""):
    if DEBUG:
        print(message)

# get_header - This method returns the header portion of the input line.
def get_header(line: str):
    header = ""
    for achar in line:        
        if achar in ['0', '1']:
            break
        header += achar
    return header

# get_message - This method returns the encoded portion of the message.
def get_message(line: str):
    message = ""
    for achar in line:        
        if achar not in ['0', '1']:
            continue
        message += achar
    return message

# get_header - This method returns "all" valid keys.
def get_keys(header: str):
    ALL_KEYS=["0","00","01","10","000","001","010","011","100","101","110","0000"] # This is a temporary shortcut not accounting for arbitrary lengths of keys
    keys = []
    for i, _ in enumerate(header, 0):
        keys.append(ALL_KEYS[i])
    return keys

# get_header_key_map - This method builds a header key map.
def get_header_key_map(header, keys):
    key_map = dict()
    for i, achar in enumerate(header, 0):
        key_map[achar] = keys[i]
    return key_map

# get_segment_length - This method returns the length of the keys in the segment
def get_segment_length(message):
    return int(message[:3], 2)

# get_length_segments - This method obtains segments of segment_length until the terminaing 1(s)
def get_length_segments(message, segment_length):
    segments = []
    count = 0
    for i in range(0, len(message), segment_length):
        segment = ""
        for j in range(segment_length):
            if i+j >= len(message):
                break
            dprint(f"{i+j}:{message[i+j]}")                
            segment += message[i+j]
            count += 1
        if len(segment) == segment_length and '0' not in segment:
            break
        dprint()
        segments.append(segment)
    return segments, count

# get_all_segment_keys - This method obtains all the keys from the segments.
#
# The encoded message contains only 0's and 1's and possibly carriage returns, which are to be ignored. 
# The message is divided into segments. 
# The first 3 digits of a segment give the binary representation of the length of the keys in the segment. 
# For example, if the first 3 digits are 010, then the remainder of the segment consists of keys of length 2 (00, 01, or 10).
# The end of the segment is a string of 1's which is the same length as the length of the keys in the segment. 
# So a segment of keys of length 2 is terminated by 11. The entire encoded message is terminated by 000 (which would signify a segment in which the keys have length 0).
# The message is decoded by translating the keys in the segments one-at-a-time into the header characters to which they have been mapped.
# 
# Input Example:
# Message: 0100000101101100011100101000
# Message: 010 00 00 10 11 011 000 111 001 01 000
# Result Example:
# Segments: 00 00 10 000 01
#      
def get_all_segment_keys(message, header, key_map):
    count = 0
    all_segment_keys = []
    while True:
        segment_length = get_segment_length(message)
        if segment_length == 0: # exit when no more segments
            break
        message = message[3:] # remove the segment length from message
        dprint(f"segment_length = {segment_length}")
        segments, count = get_length_segments(message, segment_length)
        message = message[count:]  # remove the segments from the message
        for segment in segments:
            all_segment_keys.append(segment)
        dprint(segments)
        dprint(count)
    return all_segment_keys

# decode_message - This method takes a line of input and parses out all components, processes them and returns the decoded message.
#
# Encoded Message: $#**\0100000101101100011100101000
# Header: $#**\
# Message: 0100000101101100011100101000
#
# Decoded Message: ##*\$
def decode_message(line: str):
    decoded_message = ""    
    header = get_header(line)
    keys = get_keys(header)
    message = get_message(line)
    key_map = get_header_key_map(keys, header)
    decodeds = get_all_segment_keys(message, header, key_map)
    for decoded in decodeds:
        if decoded not in key_map:
            print(f"ERROR: {decoded} not in {key_map}")
        decoded_message += key_map[decoded]
    dprint(line)
    dprint(header)
    dprint(message)
    dprint(keys)
    dprint(key_map)
    dprint(decodeds)
    return decoded_message    

input_messages = []
try:
    with open("python/encoded_messages.txt", "r") as file:
        lines = file.readlines()
        for line in lines:
            input_messages.append(line.strip())
except FileNotFoundError:
    print("Error: The file 'encoded_messages.txt' was not found.")
except Exception as e:
    print(f"An error occurred: {e}")

expected_messages = []
try:
    with open("python/expected_messages.txt", "r") as file:
        lines = file.readlines()
        for line in lines:
            expected_messages.append(line.strip())
except FileNotFoundError:
    print("Error: The file 'expected_messages.txt' was not found.")
except Exception as e:
    print(f"An error occurred: {e}")

PASS_RESULTS = []
FAIL_RESULTS = []

for i, input in enumerate(input_messages, 0):
    expected_output = expected_messages[i]
    actual_output = decode_message(input)
    if actual_output != expected_output:
        print(f"Test failed for input: {input}"
              f"\nExpected: {expected_output}"
              f"\nActual:   {actual_output}\n")
        FAIL_RESULTS.append(input)
    else:
        PASS_RESULTS.append(input)

print(f"Passed {len(PASS_RESULTS)} tests!")
for result in PASS_RESULTS:
    print(f"Passed: {result}")

print(f"Failed {len(FAIL_RESULTS)} tests!")
for result in FAIL_RESULTS:
    print(f"Failed: {result}")
