import cv2

# Define video path (or camera index for live video)
video_path = 'path/to/your/video.mp4'  # Replace with camera index for live video (e.g., 0)

# Background subtraction algorithm (MOG2 is common, adjust if needed)
algo = 'MOG2' 

# Create background subtractor object
fgbg = cv2.createBackgroundSubtractorMOG2() 

def main():
  # Open video capture
  cap = cv2.VideoCapture(video_path)

  if not cap.isOpened():
      print("Error opening video stream or file")
      return

  while True:
      # Capture frame-by-frame
      ret, frame = cap.read()

      if not ret:
          print("No frame captured from the video source")
          break

      # Apply background subtraction
      fgmask = fgbg.apply(frame)

      # Apply thresholding (optional, adjust value if needed)
      ret, thresh = cv2.threshold(fgmask, 127, 255, cv2.THRESH_BINARY)

      # Find contours in the foreground mask (potential objects)
      contours, _ = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

      # Draw contours around detected objects (optional)
      for cnt in contours:
          cv2.drawContours(frame, [cnt], 0, (0, 255, 0), 2)

      # Display the frame with foreground mask or contours (optional)
      # You can choose between displaying the original frame, foreground mask, or frame with contours
      # cv2.imshow('Original Frame', frame)
      # cv2.imshow('Foreground Mask', fgmask)
      cv2.imshow('Frame with Contours', frame)

      # Exit loop on 'q' key press
      if cv2.waitKey(1) == ord('q'):
          break

  # Release capture resources
  cap.release()
  cv2.destroyAllWindows()

if __name__ == "__main__":
  main()
