import cv2

def detect_face(image_path, dst_path):

    image = cv2.imread(image_path)

     # Load a pre-trained object detection cascade classifier
    face_cascade = cv2.CascadeClassifier('python/haarcascade_frontalface_default.xml')

    # Detect faces in the image
    faces = face_cascade.detectMultiScale(image, scaleFactor=1.1, minNeighbors=5)

    # Draw rectangles around detected faces (optional)
    for (x, y, w, h) in faces:
        cv2.rectangle(image, (x, y), (x+w, y+h), (255, 0, 0), 2)

    cv2.imgwrite(image, dst_path)

    # Print number of detected faces
    print(image_path)
    print(f"Number of faces detected: {len(faces)}")

detect_face('test/dog.jpg', 'test/dog-answer.jpg')
detect_face('test/face.jpg', 'test/face-answer.jpg')
detect_face('test/faces.jpg', 'test/faces-answer.jpg')
