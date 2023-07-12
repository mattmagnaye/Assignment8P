/*
* Program: main.cpp (Assignment 8P: Chars and C-Strings)
* Author: Matt Aaron Magnaye
* Instructor: Professor David Harden
* Date: 07/12/2023
* Description: Implemented following functions tasked by Professor Harden.
*
*/

#include <iostream>

using namespace std;

// Function to find the last index of the target character in the string
int findLastIndex(const char* str, char target);

// Function to reverse a string in place
void reverseString(char* str);

// Function to replace all occurrences of the target character with the replacement character
int replaceCharacter(char* str, char target, char replacement);

// Function to check if a string is a palindrome
bool isPalindrome(const char* str);

// Function to convert a string to uppercase
void toUpperCase(char* str);

// Function to count the number of letters in a string
int countLetters(const char* str);

int main() {
    // Testing lastIndexOf()
    const char* str1 = "Hello World";
    char target1 = 'o';
    cout << "Last index of '" << target1 << "' in \"" << str1 << "\": " << findLastIndex(str1, target1) << endl;

    const char* str2 = "Hello World";
    char target2 = 'z';
    cout << "Last index of '" << target2 << "' in \"" << str2 << "\": " << findLastIndex(str2, target2) << endl;

    // Testing reverse()
    char str3[] = "flower";
    reverseString(str3);
    cout << "Reversed string: " << str3 << endl;

    // Testing replace()
    char str4[] = "Hello World";
    char target3 = 'o';
    char replacement1 = '*';
    int replacements = replaceCharacter(str4, target3, replacement1);
    cout << "Number of replacements: " << replacements << endl;
    cout << "Modified string: " << str4 << endl;

    // Testing isPalindrome()
    const char* str5 = "abba";
    cout << "\"" << str5 << "\" is a palindrome: " << boolalpha << isPalindrome(str5) << endl;

    const char* str6 = "abc ba";
    cout << "\"" << str6 << "\" is a palindrome: " << boolalpha << isPalindrome(str6) << endl;

    // Testing toupper()
    char str7[] = "Hello World";
    toUpperCase(str7);
    cout << "Uppercase string: " << str7 << endl;

    // Testing numLetters()
    const char* str8 = "Hello123World";
    cout << "Number of letters in \"" << str8 << "\": " << countLetters(str8) << endl;

    return 0;
}

// Function to find the last index of the target character in the string
int findLastIndex(const char* str, char target) {
    int lastIndex = -1;
    int index = 0;

    while (str[index] != '\0') {
        if (str[index] == target) {
            lastIndex = index;
        }
        index++;
    }

    return lastIndex;
}

// Function to reverse a string in place
void reverseString(char* str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    int start = 0;
    int end = length - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

// Function to replace all occurrences of the target character with the replacement character
int replaceCharacter(char* str, char target, char replacement) {
    int replacements = 0;
    int index = 0;

    while (str[index] != '\0') {
        if (str[index] == target) {
            str[index] = replacement;
            replacements++;
        }
        index++;
    }

    return replacements;
}

// Function to check if a string is a palindrome
bool isPalindrome(const char* str) {
    int start = 0;
    int end = 0;

    while (str[end] != '\0') {
        end++;
    }
    end--;

    while (start < end) {
        if (tolower(str[start]) != tolower(str[end])) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

// Function to convert a string to uppercase
void toUpperCase(char* str) {
    int index = 0;

    while (str[index] != '\0') {
        str[index] = toupper(str[index]);
        index++;
    }
}

// Function to count the number of letters in a string
int countLetters(const char* str) {
    int count = 0;
    int index = 0;

    while (str[index] != '\0') {
        if (isalpha(str[index])) {
            count++;
        }
        index++;
    }

    return count;
}
