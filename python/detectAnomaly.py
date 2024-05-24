import cv2
import numpy as np

def detect(image_path, dst_path):
    # Load the image
    image = cv2.imread(image_deviating_color)

    # Define the reference color (e.g., blue in BGR format)
    reference_color = [0, 0, 255]  # Adjust values for B, G, R based on your desired color

    # Define tolerance range for color variation (adjust values if needed)
    tolerance = 20

    # Convert image to HSV color space for easier color matching
    hsv_image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

    # Define the lower and upper bounds of the reference color in HSV space
    lower_color = np.array([reference_color[0] - tolerance, 100, 100])
    upper_color = np.array([reference_color[0] + tolerance, 255, 255])

    # Create a mask to isolate pixels within the reference color range
    mask = cv2.inRange(hsv_image, lower_color, upper_color)

    # Find contours in the mask (potential objects deviating from the pattern)
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # Draw contours around potential anomalies (optional)
    for cnt in contours:
        cv2.drawContours(image, [cnt], 0, (0, 255, 0), 2)

    cv2.imwrite(dst_path, image)

    # Print the number of detected anomalies (contours)
    print(f"Number of potential anomalies detected: {len(contours)}")

detect('test/dog.jpg', 'test/dog-answer2.jpg')
detect('test/face.jpg', 'test/face-answer2.jpg')
detect('test/faces.jpg', 'test/faces-answer2.jpg')