import cv2
import random

img = cv2.imread('test/test.jpg')

tag = img[1:20, 1:200]
img[21:40, 101:300] = tag

cv2.imwrite('test/new1.jpg', tag)

for i in range(40):
    for j in range(40):
        img[i][j] = [random.randint(0,255), random.randint(0,255), random.randint(0,255)]

cv2.imwrite('test/new2.jpg', img)
