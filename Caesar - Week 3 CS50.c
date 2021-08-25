#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int counter = 0;
    if (argc == 2) // Checks if the user inputed a command-line argument on argv [1]
    {
        for (int i = 0, len = strlen(argv[1]); i < len; i++)
        {
            if (isdigit(argv[1][i])) // Checking if each character in argv [1] is a digit
            {
                counter++;
                //Assigning a 'counter' variable here is a way to make the first 'if conditional' to complete first before performing the actions indicated in the next if-conditional

                if (counter ==
                    len) // The counter variable suppose to be the same sa the value of the string length if the user inputed only numerical digits on it.
                {
                    string plain = get_string("Plaintext: ");
                    printf("Ciphertext:");
                    for (int x = 0, len2 = strlen(plain); x < len2; x++)
                    {
                        if (isupper(plain[x]))
                        {
                            int letter = plain[x] + atoi(argv[1]) % 26;
                            if (letter > 90)
                            {
                                printf("%c", letter - 26);
                            }
                            else
                            {
                                printf("%c", letter);
                            }
                        }
                        else if (islower(plain[x]))
                        {
                            int letter2 = plain[x] + atoi(argv[1]) % 26;
                            if (letter2 > 122)
                            {
                                printf("%c", letter2 - 26);
                            }
                            else
                            {
                                printf("%c", letter2);
                            }
                        }
                        else
                        {
                            printf("%c", plain[x]);
                        }
                    }
                    printf("\n");
                    return 0;
                }
            }

            else // if the user place a non-digit character in the argument, the 'isdigit' function wont read it, hence the counter variable will be lacking as much as the number of non-digit character the user inputed.
            {
                printf("Usage: ./caesar key\n");  // printing error message
                i += strlen(argv[1]) - i; 
                // This line of code basically STOP the for loop for running if there is a non-number character in the argument
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");  // printing error message
        return 1;
    }
}

// More formally, if p is some plaintext (i.e., an unencrypted message),
//pi is the ith character in p, and k is a secret key (i.e., a non-negative integer),
// then each letter, ci, in the ciphertext, c, is computed as
// ci = (pi + k) % 26
// wherein % 26 here means “remainder when dividing by 26.”

//Check that program was run with one command-line argument
//Iterate over the provided argument to make sure all characters are digits
//Convert that command-line argument from a string to an int
//Prompt user for plaintext
//Iterate over each character of the plaintext:
//If it is an uppercase letter, rotate it, preserving case, then print out the rotated character
//If it is a lowercase letter, rotate it, preserving case, then print out the rotated character
//If it is neither, print out the character as is
//Print a newline

//printf("Score: %d\n", argv[1][i] + 3); this code is use for using a character in calculation
//New Fucking discovery: atoi is a function that translates a number in string into an int