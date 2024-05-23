import cv2
import random

img = cv2.imread('test/test.jpg')

print(img)

print(img.shape)

# img is numpy array, HxWxChannels

cv2.imwrite('test/new1.jpg', img)

tag = img[1:20, 1:200]
img[21:40, 101:300] = tag

cv2.imwrite('test/new2.jpg', img)

cv2.imwrite('test/new3.jpg', tag)
