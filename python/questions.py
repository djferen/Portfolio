
def size_of_longest_contiguous_sequence(numbers: list) -> int:
    max_size = cur_size = 0
    prev = None

    for n in numbers:
        if prev == None or prev != n:
            cur_size = 0
        cur_size += 1
        max_size = max(max_size, cur_size)
        prev = n
    
    return max_size

print(size_of_longest_contiguous_sequence([1, 1, 2, 3, 3, 3, 2, 1]))
