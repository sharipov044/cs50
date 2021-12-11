from cs50 import get_string


text = get_string("Text: ")

letter_count = 0
word_count = 1
sentence_count = 0

lenght = len(text)
for i in range(lenght):
    if (text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= "Z"):
        letter_count += 1
    elif (text[i] == " "):
        word_count += 1
    elif (text[i] == '.') or (text[i] == '!') or (text[i] == '?'):
        sentence_count += 1

grade = (0.0588 * (100 * letter_count / word_count)) - (0.296 * (100 * sentence_count / word_count)) - 15.8

if grade < 16 and grade >= 0:
    print(f"Grade {round(grade)}")
elif grade > 16:
    print("Grade 16+")
else:
    print("Before Grade 1")
