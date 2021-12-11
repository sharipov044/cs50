# import module form cs50 library
from cs50 import get_int


def main():
    p = get_positive_int()
    k = p

    for i in range(p):
        for j in range(k - 1):
            print(" ", end="")
        k = k - 1
        for m in range(p-k):
            print("#", end="")
        print()


def get_positive_int():
    while True:
        n = get_int("Height: ")
        if n > 0 and n < 9:
            break
    return n


main()