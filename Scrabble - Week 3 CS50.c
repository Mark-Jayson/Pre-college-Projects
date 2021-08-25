#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
     if (score1 > score2)
        {
            printf ("Player 1 wins! \n");
        }
   else if (score1 < score2)
        {
            printf("Player 2 wins! \n");
        }
    else 
       {
        printf("Tie! \n");
         }
}
//Helper Function named "compute_score"
int compute_score(string word)
{
    // TODO: Compute and return score for string
    int dog = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
        {
        // the if - else statement identify whether the character on the ith element of the array called word is lowercase or uppercase. If it is uppercase it will be processed on the first function, and if lowercase, to the second function. 
            if (isupper (word[i]))
            {
                // This line of code does the following:
                    // 1) It subracts the ASCII value of 'A' to the ASCII value of the character on the ith element of the array called word in order to establish the value of each character that is allign to the indexing in the array POINTS (Ex. A-A = 0, so 'A' matches to the element in the Oth position in the array POINTS. It is the same with other letters) 
                    // 2) It uses that value (Charater in the ith position of the array called word - 'A') as the index of in the array POINT. Remember that array POINT is has its own list of elements indicated in the top of the program. 
                    // 3) It uses the value on that element of the array POINT as the number being added to the value of variable "dog" in every increment. 
                 dog += POINTS[word[i] - 'A'];
            }
            else if (islower (word[i]))
            {
                // This line of code does exactly as the first one but the only difference is on the number one; it works in lowercase characters and substracts 'a' to them instead of 'A' to establish a value that is align to the indexing of the array POINTS
                dog += POINTS[word[i] - 'a'];
            }
        }
    return dog;

}