n = 4

print('column major upper symmetric matrix (1-based)')
print('1  2 3  4 5 6  7 8 9 10\n')
for i in range(1, 5):
    for j in range(1, 5):
        print(i + j * (j - 1) // 2, end = ' ')
    print()
print()

print('column major lower symmetric matrix (1-based)')
print('1 2 3 4  5 6 7  8 9  10\n')
for i in range(1, 5):
    for j in range(1, 5):
        print(i + (2 * n - j) * (j - 1) // 2, end = ' ')
    print()
print()

print('column major upper symmetric matrix (0-based)')
print('0  1 2  3 4 5  6 7 8 9\n')
for i in range(4):
    for j in range(4):
        print(i + j * (j + 1) // 2, end = ' ')
    print()
print()

print('column major lower symmetric matrix (0-based)')
print('0 1 2 3  4 5 6  7 8  9\n')
for i in range(4):
    for j in range(4):
        print(i + j * (2 * n - j - 1) // 2, end = ' ')
    print()
print()

def f1(i, j, k):
    return i + j * (j + 1) // 2 + k * (k + 1) * (k + 2) // (2 * 3)

def f2(i, j, k, l):
    return i + j * (j + 1) // 2 + k * (k + 1) * (k + 2) // (2 * 3) + l * (l + 1) * (l + 2) * (l + 3) // (2 * 3 * 4)

def f3(n, i, j, k):
    return i + (j * (2 * n - j - 1)) // 2 + k * (2 * n - k - 1) * (2 * n - k) // (2 * 3)

def f4(n, i, j, k, l):
    return i + (j * (2 * n - j - 1)) // 2 + k * (2 * n - k - 1) * (2 * n - k) // (2 * 3) + l * (2 * n - l - 1) * (2 * n - l) * (2 * n - l + 1) // (2 * 3 * 4)

print('example (3, 3, 3) column major upper symmetric (0-based)')
print(f1(3, 3, 3))
print()

print('example (6, 6, 6, 6) column major upper symmetric (0-based)')
print(f2(6, 6, 6, 6))
print()

print('example (3, 3, 3) column major lower symmetric (0-based) (method 1)')
print(f3(4, 3, 3, 3))
print()

print('example (2, 0, 3) column major lower symmetric (0-based) (method 1)')
print(f3(4, 2, 0, 3))
print()

print('example (6, 6, 6, 6) column major lower symmetric (0-based) (method 1)')
print(f4(7, 6, 6, 6, 6))
print()
