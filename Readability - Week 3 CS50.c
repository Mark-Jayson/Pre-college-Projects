#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Prototypes of the functions that count the number of letters, words, and sentences, respectively, on the text provided by the user

int comp_letters(string words);
int comp_words(string words);
int comp_sentences(string words);

int main(void)
{   // Get text from the user
    string text = get_string("Text: ");

    // This three lines of code call the value stored in the functions comp_words(), compt_letters(), and comp_sentences(), in order to compute the average letters per 100 words (stored in the variable L) and average sentences per 100 words (stored in the variable S) of the text inputed by the user

    float w = 100 / (float)comp_words(text);
    float L =  w * (float)comp_letters(text);
    float S = w * (float) comp_sentences(text);

    // This line of code uses the value of variable L and S and plug it in the Coleman-Liau Index. The resulting value is then rounded to produce grade reading level of that set of text

    int grade = round(0.0588 * L - 0.296 * S - 15.8);

// This set of conditional statements evaluates the output being projected to the user based on the grade produced by the codes before it.
    if (grade < 16 && grade >= 1)
    {
        printf("Grade %i\n", grade);
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
}
    //This helper function named comp_letters use the text from the user as input and count only the letters of the alphabet on that text, ignoring all other symbols. When the letter is uppercase it will be counted to the first conditional statement, while if it is lowercase it will be counted on the second conditonal statement. Since the variable used in counting both lowercase and uppercase letters are the same, when we get the return value of that variable, the combined number of uppercase and lowercase letter is what we will acquire

int comp_letters(string words)
{
    int letter_count = 0;
    for (int i = 0, len = strlen(words); i < len; i++)
    {
        if (isupper(words[i]))
        {
            letter_count++;
        }
        else if (islower(words[i]))
        {
            letter_count++;
        }
    }
    return letter_count;

}
    //This function named comp_words computes the number of words in the text inputed by the user. This function uses other function called isspace() which identify whether or not a particular character is a space. Since the number of space is 1 more than the value of words in the text, we place 1 as the starting value to the counter variable, word_count, instead of 0.
int comp_words(string words)
{
    int word_count = 1;
    for (int i = 0, len = strlen(words); i < len; i++)
    {
        if (isspace(words[i]))
        {
            word_count++;
        }
        else
        {
            word_count += 0;
        }
    }
    return word_count;
}
    //This function named comp_sentences computes the number of sentences in text inputed by the user. It uses period, exclamation point, and question mark as an indicator that there is a sencetence. When the function sense that the character is one of those three indicators, it will fall either of the three conditional statements and adds 1 to the value of counter variable sent_count.
int comp_sentences(string words)
{
    int sent_count = 0;
    for (int i = 0, len = strlen(words); i < len; i++)
    {
        if (words[i] == '.')
        {
            sent_count++;
        }
        else if (words[i] == '!')
        {
            sent_count++;
        }
        else if (words[i] == '?')
        {
            sent_count++;
        }
    }
    return sent_count;
}