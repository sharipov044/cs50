from cs50 import get_string


def main():
    number = get_card_number()
    checksum = check_card(number)
    check_card_type(number, checksum)


def get_card_number():
    while True:
        count = 0
        card_number = input("CC Number: ")
        if card_number.isnumeric():
            break
    return card_number


def check_card(number):
    even_sum = 0
    odd_sum = 0
    number = reversed([int(digit) for digit in number])
    for i, digit in enumerate(number):
        if (i + 1) % 2 == 0:
            odd_digit = digit * 2
            if odd_digit > 9:
                odd_sum = odd_sum + int(odd_digit / 10) + (odd_digit % 10)
            else:
                odd_sum = odd_sum + odd_digit
        else:
            even_sum = even_sum + digit
    checksum = even_sum + odd_sum
    return checksum


def check_card_type(number, checksum):
    start_number = int(number[0:2])
    card_length = len(number)
    card_last_digit = checksum % 10

    if card_last_digit == 0:
        if start_number in [34, 37] and card_length == 15:
            print("AMEX")
        elif (int(number[0]) == 4) and card_length in [13, 16]:
            print("VISA")
        elif (start_number in range(51, 56)) and card_length == 16:
            print("MASTERCARD")
        else:
            print("INVALID")
    else:
        print("INVALID")


main()