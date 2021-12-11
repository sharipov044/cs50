from cs50 import get_float


def main():
    c = get_positive_float()
    f = round(c * 100)
    coins = 0
    while f > 0:
        if f >= 25:
            f = f - 25
        elif f >= 10:
            f = f - 10
        elif f >= 5:
            f = f - 5
        else:
            f = f - 1
        coins = coins + 1
    print(f"Coins: {coins}")


def get_positive_float():
    while True:
        cash = get_float("Cash: ")
        if cash > 0.0:
            break
    return cash


main()