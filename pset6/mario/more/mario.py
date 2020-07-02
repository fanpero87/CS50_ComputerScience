from cs50 import get_int

def main():
    height = positiveInt()
    for i in range(height):
        for j in range(i, height-1):
            print(" ", end="")
        for k in range (i+1):
            print("#", end="")
        print("  ", end="")
        for l in range (i+1):
            print("#", end="")
        print()

def positiveInt():
    while True:
        h = get_int("Height: ")

        if h > 0 and h <= 8:
            break
    return h

main()