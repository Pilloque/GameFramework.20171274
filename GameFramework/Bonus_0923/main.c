#include <stdio.h>

_Bool isAlphabet(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1;
    else
        return 0;
}

_Bool isNull(char c)
{
    if (c == '\0')
        return 1;
    else
        return 0;
}

void VeryLongWord(char* sen)
{
    int index = 0;
    int longestIndex = 0;
    int size;
    int longestSize = 0;

    while (!isNull(sen[index]))
    {
        size = 0;
        while (isAlphabet(sen[index]))
        {
            size++;
            index++;
        }
        if (size > longestSize)
        {
            longestSize = size;
            longestIndex = index - size;
        }
        index++;
    }

    for (int i = longestIndex; i < longestIndex + longestSize; i++)
    {
        printf("%c", sen[i]);
    }
}

void ChangeLetters(char* str)
{
    int index = 0;
    char temp;

    while (!isNull(str[index]))
    {
        temp = str[index];
        if (temp >= 'A' && temp < 'Z' || temp >= 'a' && temp < 'z')
        {
            temp++;
            if (temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u')
            {
                temp -= 32;
            }
        }
        else if (temp == 'Z' || temp == 'z')
        {
            temp = 'A';
        }

        printf("%c", temp);
        index++;
    }
}

void CapitalizeLetter(char* str)
{
    int index = 0;
    char temp;
    _Bool isFirst = 1;

    while (!isNull(str[index]))
    {
        temp = str[index];
        if (isFirst)
        {
            if (temp >= 'a' || temp <= 'z')
            {
                temp -= 32;
            }
            isFirst = 0;
        }
        if (temp == ' ')
        {
            isFirst = 1;
        }
        printf("%c", temp);
        index++;
    }
}

int main(void)
{
    VeryLongWord("Hello my name is Jason!");
    printf("\n");
    ChangeLetters("hello*3 fun times!");
    printf("\n");
    CapitalizeLetter("i am a boy");
    printf("\n");

    return 0;
}