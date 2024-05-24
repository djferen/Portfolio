
# Import libraries
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Conv2D, MaxPooling2D, Flatten, Dense

# Define data paths
train_data_dir = 'path/to/your/training/data'
validation_data_dir = 'path/to/your/validation/data'
test_image_path = 'path/to/your/test/image.jpg'

# Set image dimensions
img_width, img_height = 150, 150

# Data preprocessing
train_datagen = ImageDataGenerator(rescale=1./255, shear_range=0.2, zoom_range=0.2, horizontal_flip=True)
validation_datagen = ImageDataGenerator(rescale=1./255)

train_generator = train_datagen.flow_from_directory(
    train_data_dir,
    target_size=(img_width, img_height),
    batch_size=32,
    class_mode='categorical'
)

validation_generator = validation_datagen.flow_from_directory(
    validation_data_dir,
    target_size=(img_width, img_height),
    batch_size=32,
    class_mode='categorical'
)

# Define model architecture
model = Sequential()
model.add(Conv2D(32, (3, 3), activation='relu', input_shape=(img_width, img_height, 3)))
model.add(MaxPooling2D(pool_size=(2, 2)))
model.add(Flatten())
model.add(Dense(128, activation='relu'))
model.add(Dense(len(train_generator.classes), activation='softmax'))

model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy'])

# Train the model
model.fit(
    train_generator,
    epochs=20,
    validation_data=validation_generator
)

# Load the test image
from tensorflow.keras.preprocessing import image
test_image = image.load_img(test_image_path, target_size=(img_width, img_height))
test_image = image.img_to_array(test_image)
test_image = test_image / 255.0
test_image = np.expand_dims(test_image, axis=0)

# Predict class of test image
prediction = model.predict(test_image)
predicted_class = train_generator.class_indices[np.argmax(prediction[0])]

# Print the predicted class
print(f"Predicted class: {predicted_class}")
