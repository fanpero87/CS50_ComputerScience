def main():
    text = input("Text: ")
    l = average_number_letters(text)
    w = average_number_words(text)
    s = average_number_sentences(text)

#Calculate the Coleman-Liau index of a text
    average_letters = (l / w) * 100
    average_sentences = (s / w) * 100
    index = round(0.0588 * average_letters - 0.296 * average_sentences - 15.8)
    if (index > 16):
        print("Grade 16+");
    elif (index > 1 and index <= 16):
        print("Grade", index)
    else:
        print("Before Grade 1")

#Function that counts the number of letters that show up in the text
def average_number_letters(text):
    lenght = len(text)
    count = 0
    for i in range(lenght):
        if ((text.lower()[i] >= 'a') and (text.lower()[i] <= 'z')):
            count += 1
    return count

#Function that counts the number of words that show up in the text
def average_number_words(text):
    lenght = len(text)
    count = 0
    for i in range(lenght):
        if (text[i] == ' '):
            count += 1
    return count + 1

#Function that counts the number of senences that show up in the text
def average_number_sentences(text):
    lenght = len(text)
    count = 0
    for i in range(lenght):
        if ((text[i] == '.') or (text[i] == '!') or (text[i] == '?')):
            count += 1
    return count

main()