#!/usr/bin/python3

import sys


def findFactores(num):
    """Finds the factors of a number
    
    args:
        num: the number to find its factors
        Return: array of integers
    """
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return [i, num // i]


if __name__ == "__main__":
    """Reads the input file and stores it in a list.
    """

    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        exit()

    test_f = sys.argv[1]

    try:
        with open(test_f, "r") as file:
            lines = file.readlines()
            list_of_num = []
            for line in lines:
                list_of_num.append(int(line))
    except FileNotFoundError:
        print("File Not Found")
        exit()
    finally:
        file.close()

    """ iterat on a list of numbers to find their factors
    """
    for num in list_of_num:
        factors = findFactores(num)
        if factors:
            print("{}={}*{}".format(num, factors[0], factors[1]))
        else:
            print("{} is a Prime number".format(num))
