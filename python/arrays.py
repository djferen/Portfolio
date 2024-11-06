
def print_elements(A, N):
    for i in range(N):
        if i == 0:
            print('[', end='')
        print(A[i], end='')
        if i < N-1:
            print(',', end='')
        if i == N-1:
            print(']', end='')
    print()

def search_element(A, N, x):
  """Searches for an element x in array A of size N.

  Args:
    A: The input array.
    N: The size of the array.
    x: The element to search for.

  Returns:
    True if x is found, False otherwise.
  """

  for i in range(N):
    if A[i] == x:
      return True
  return False

def insert_element(A, N, x, pos):
  """Inserts an element x at position pos in array A of size N.

  Assumes the array has enough capacity to accommodate the insertion.

  Args:
    A: The input array.
    N: The size of the array.
    x: The element to insert.
    pos: The position to insert the element.

  Returns:
    True if insertion is successful, False otherwise.
  """

  if pos < 0 or pos > N:
    return False

  # Shift elements to the right to make space for the new element
  A.append(0)

  for i in range(N-1, pos-1, -1):
    A[i+1] = A[i]

  A[pos] = x
  return True

def delete_element(A, N, x):
  """Deletes the first occurrence of element x in array A of size N.

  Args:
    A: The input array.
    N: The size of the array.
    x: The element to delete.

  Returns:
    True if deletion is successful, False otherwise.
  """

  for i in range(N):
    if A[i] == x:
      # Shift elements to the left to fill the gap
      for j in range(i, N-1):
        A[j] = A[j+1]
      A.pop(N-1)
      return True
  return False


A = [1, 2, 3, 4, 5]
N = len(A)

x = 3
found = search_element(A, N, x)
print("Element found:", found)

print_elements(A, N)

x = 6
pos = 2
inserted = insert_element(A, N, x, pos)
print("Element inserted:", inserted)

N = len(A)
print_elements(A, N)

x = 4
deleted = delete_element(A, N, x)
print("Element deleted:", deleted)

N = len(A)
print_elements(A, N)
