""" cal_size.py
calcute the size n that cause fibonacci array value more than 4byte signed value
"""
VALUE = 1 << 31
print "VALUE =", VALUE

size, value = 1, 1
left, right = (0, 1)

while value < VALUE:
    print size, value
    size = size + 1
    value = left + right
    left = right
    right = value

# we can get that 48 value that will more than 2147483648
