
def print_img(img, start_point=None):
    for i, row in enumerate(img):
        for j, element in enumerate(row):
            if start_point and i == start_point[0] and j == start_point[1]:
                print("X", end='')
            else:
                print(img[i][j], end='')
        print()
    print()

def dfs_fill(img, start_point):
    visited = set()
    stack = [start_point]

    while stack:
        point = stack.pop()
        if point not in visited:
            visited.add(point)
            if img[point[0]][point[1]] == 0:
                img[point[0]][point[1]] = 1
            if point[0] > 0:
                if img[point[0]-1][point[1]] == 0:
                    stack.extend([(point[0]-1, point[1])])
            if point[0] < len(img)-1:
                if img[point[0]+1][point[1]] == 0:
                    stack.extend([(point[0]+1, point[1])])
            if point[1] > 0:
                if img[point[0]][point[1]-1] == 0:
                    stack.extend([(point[0], point[1]-1)])
            if point[1] < len(img[0])-1:
                if img[point[0]][point[1]+1] == 0:                
                    stack.extend([(point[0], point[1]+1)])

    print(f"Visited {len(visited)} pixels")
    print()

img = [[0, 0, 0, 0, 0, 0, 0],
       [0, 1, 1, 1, 1, 1, 0],
       [0, 1, 0, 0, 0, 1, 0],
       [0, 1, 0, 0, 0, 1, 0],
       [0, 1, 0, 0, 0, 1, 0],
       [0, 1, 1, 1, 1, 1, 0],
       [0, 0, 0, 0, 0, 0, 0]]

start_point = (4, 4)

print("Before:")
print_img(img, start_point)

dfs_fill(img, start_point)

print("After:")
print_img(img)

img = [[0, 0, 0, 0, 0, 0, 0],
       [0, 1, 1, 1, 1, 1, 0],
       [0, 1, 0, 0, 0, 1, 0],
       [0, 1, 0, 0, 0, 1, 0],
       [0, 1, 0, 0, 0, 1, 0],
       [0, 1, 1, 1, 1, 1, 0],
       [0, 0, 0, 0, 0, 0, 0]]

start_point = (4, 6)

print("Before:")
print_img(img, start_point)

dfs_fill(img, start_point)

print("After:")
print_img(img)

