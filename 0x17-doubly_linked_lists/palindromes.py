#!/usr/bin/python3
def is_palindrome(num):
    return str(num) == str(num)[::-1]


largest_palindrome = 0

for i in range(100, 1000):
    for j in range(100, 1000):
        product = i * j
        if is_palindrome(product) and product > largest_palindrome:
            largest_palindrome = product

result_filename = "102-result"

with open(result_filename, "w") as result_file:
    result_file.write(str(largest_palindrome))

print("Result saved in", result_filename)
