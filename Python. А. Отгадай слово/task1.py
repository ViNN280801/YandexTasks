def write_test_data_to_file(test_data):
    ''' Writes test data into a file '''
    with open('input.txt', 'w') as input_file:
        input_file.write(test_data)


def read_words_from_file():
    ''' Returns two words from file '''
    with open('input.txt', 'r') as input_file:
        # Reading words from input file
        words = input_file.read()
    return words


def check_on_correctness():
    ''' Returns two words if they are valid '''
    # Reading words from file
    # Splitting recived string by character of the transition to another line '\n'
    words = list(read_words_from_file().split('\n'))

    # Checking interfals of length of both words
    if len(words[0]) >= 1 and len(words[0]) <= 10**6:
        # Checking equality of length of strings
        if len(words[0]) == len(words[1]):
            # Checking if strigs are upper case
            if words[0].isupper() and words[1].isupper():
                # Returning two words
                return words[0:2]
            else:
                raise ValueError('Symbols of string are not upper case')
        else:
            raise ValueError('Strings have different lengths')
    else:
        raise ValueError('Invalid interval for hidden word')


def guess_the_word():
    ''' Guesses the hidden word '''

    # Checking words on correctness
    words = check_on_correctness()
    print(words[0], words[1])

    # words[0] is S - hidden word
    # words[1] is Q - user's attempt

    # Compare symbols of words with 'for' loop with 'zip()' function
    for char_S, char_Q in zip(words[0], words[1]):
        # If there is equals symbols -> printing 'correct' then removing it symbol from attempt string
        if char_Q == char_S:
            print('correct')
            words[0] = words[0].replace(char_Q, '', 1)
        # If there is equals symbols but with different indeces -> printing 'present'
        elif char_Q in words[0]:
            print('present')
        # Else string doesn't contain that character -> printing 'absent'
        else:
            print('absent')
        # Then, at the end of loop removing it symbol from attempt string
        words[0] = words[0].replace(char_Q, '', 1)


# Writing test data to file. 1st example from task (read task1.pdf)
print('Example #1: ')
write_test_data_to_file('COVER\nCLEAR')
guess_the_word()
# Writing test data to file. 2nd example from task (read task1.pdf)
print('\nExample #2: ')
write_test_data_to_file('ABBA\nAAAA')
guess_the_word()
# Writing test data to file. 3rd example from task (read task1.pdf)
print('\nExample #3: ')
write_test_data_to_file('ABCBC\nBBACA')
guess_the_word()

# Random filling of file to provoke error
print('\nExample #4: ')
write_test_data_to_file('aABBC\nBBACA')
guess_the_word()
