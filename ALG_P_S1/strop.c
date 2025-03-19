#include<stdio.h>
#include<stdbool.h>

int stringLength(const char* str)
{
    int length = 0;
    
    while (str[length] != '\0')
        length ++;

    return length;
}

void stringCopy(char* dest,const char* src)
{
    
    while (*src){
        *dest = *src;
        dest ++;
	src ++;
    }

    *dest = '\0';
}

void stringConcat(char* dest, const char* src)
{
    while (*dest)
	dest ++;

    while (*src){
	*dest = *src;
	dest ++;
	src ++;
    }

    *dest = '\0';

}

int stringCompare(const char* str1, const char* str2)
{
    while(*str1 && *str2){
    
        if (*str1 != *str2)
            return *str1 - *str2;
    
        str1 ++; str2 ++;
    }
    
    return *str1 - *str2;
}

bool isEmpty(char* str){

    return str[0] == '\0';

}

void reverseString(char* str){

    char tmp;
    int i = 0, j = stringLength(str) - 1;

    while (j > i){

        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;

        i ++; j--;

        }
    
}

void toUpperCase(char* str){

    while (*str){

        if (*str < 123 && *str > 96)
            *str = *str - 32;

        str ++;

        }
}

void toLowerCase(char* str){

    while (*str){

        if (*str < 91 && *str > 64)
            *str = *str + 32;

        str ++;

        }
}

bool isPalindrome(char* str){

    char start = 0,end= stringLength(str) - 1;

    while (start < end){
    
        if (str[start] != str[end])
            return false;

        start ++;
        end --;

        }

    return true;

}

void countVowelsConst(char* str, int* vow, int* cons) {
    // Initialize the counts to 0
    *vow = 0; 
    *cons = 0;

    // Ensure the string is processed in lowercase
    toLowerCase(str);

    // Loop through each character of the string
    while (*str) {
        // Check if the character is alphabetic (lowercase a-z)
        if (*str >= 'a' && *str <= 'z') {
            switch (*str) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    // Increment vowel count
                    (*vow)++;
                    break;
                default:
                    // Increment consonant count
                    (*cons)++;
                    break;
            }
        }
        // Move to the next character
        str++;
    }
}

int findSubString(const char* str, const char* sub) {
    // Calculate the lengths of the main string and the substring
    int lenStr = stringLength(str), lenSub = stringLength(sub),j;

    // If the main string is shorter than or equal to the substring, return -1 (not found)
    if (lenStr < lenSub)
        return -1;

    // Loop through the main string, stopping early to avoid overflow
    for (int i = 0; i <= lenStr; i++) {
        // Check if the substring matches starting at the current position
        for (j = 0; j < lenSub; j++) {
            // If characters don't match, exit the inner loop
            if (str[i + j] != sub[j])
                break;
        }

        // If the inner loop completed (all characters matched), return the start index
        if (j == lenSub)
            return i;
    }

    // If no match is found, return -1
    return -1;
}

void removeWhitespaces(char* str) {
    int i = 0, j = 0;

    // Traverse the string
    while (str[j] != '\0') {
    // If the current character is not a space, copy it to the current position of `i`
        if (str[j] != ' ') {
            str[i] = str[j];
            i ++;
        }
        j++;
    }

    // Null-terminate the modified string
    str[i] = '\0';
}

void charFrequency(char* str,int* freq) {

    toLowerCase(str);

    // Calculate frequency of each character
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 96 && str[i] < 123)
            freq[str[i] - 'a']++;
    }

}

bool isAnagram(char* str1, char* str2) {
    // Remove whitespaces and convert both strings to lowercase
    removeWhitespaces(str1);
    removeWhitespaces(str2);
    toLowerCase(str1);
    toLowerCase(str2);

    // If lengths are not equal, they cannot be anagrams
    if (stringLength(str1) != stringLength(str2))
        return false;

    // Frequency arrays for 26 letters (assuming only lowercase alphabets)
    int freq1[26] = {0};
    int freq2[26] = {0};

    // Calculate frequency of characters in both strings
    charFrequency(str1, freq1);
    charFrequency(str2, freq2);

    // Compare frequency arrays
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) return false;
    }

    return true;
}

int countWords(char* str){

    int count = 0; // Word count
    bool word = false; // track if we are inside a word

    // Iterate through each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        // If the current character is not a space and we are not already in a word,
        // increment the word count and set the Word flag to true
        if (str[i] != ' ' && !word) {
            count++;
            word = true;
        }
        // If the current character is a space, set the Word to false
        else if (str[i] == ' ') {
            word = false;
        }
    }

    return count;
}

void removeDuplicates(char* str){
	int i = 0, j = 0; // Indexs for tracking positions in the string
    bool seen[26] = {false}; // Array to track seen characters (ASCII assumption)
	toLowerCase(str);
    // Iterate through the string
    while (str[j] != '\0') {
        // If the current character has not been seen before
        if (!seen[str[j] - 'a']) {
            // Mark the character as seen
            seen[str[j] - 'a'] = true;
            // Copy the character to the current position of `i`
            str[i] = str[j];
            i++; // Move `i` to the next position
        }
        j++; // Move `j` to the next character
    }

    // Null-terminate the modified string
    str[i] = '\0';
}

void intToString(int num, char* str) {
    int i = 0;
    if (num == 0) {
        str[i++] = '0'; // Handle the case where the count is 0
    } else {
        // Convert the number to a string in reverse order
        while (num > 0) {
            str[i++] = '0' + (num % 10); // Get the last digit
            num /= 10; // Remove the last digit
        }
    }
    str[i] = '\0'; // Null-terminate the string

    // Reverse the string to get the correct order
    reverseString(str);
}

// Function to compress a string using Run-Length Encoding (RLE)
void compressString(char* str, char* result) {
    int i = 0, j = 0;
    int count; // Counter for consecutive characters

    // Iterate through the input string
    while (str[i] != '\0') {
        // Start counting consecutive characters
        count = 1;
        while (str[i] == str[i + 1]) {
            count++;
            i++;
        }

        // Append the character to the result
        result[j++] = str[i];

        // If the count is greater than 1, append the count as a string
        if (count > 1) {
            char countStr[10]; // hold the count as a string
            intToString(count, countStr); // Convert count to a string
            for (int k = 0; countStr[k] != '\0'; k++) {
                result[j++] = countStr[k]; // Append each digit of the count
            }
        }

        i++; // Move to the next character
    }

    // Null-terminate the result string
    result[j] = '\0';
}

void longestWord(char* str, char* result){
    int maxLength = 0; // Length of the longest word
    int currentLength = 0; // Length of the current word
    int start = 0; // Starting index of the longest word
    int end = 0; // Ending index of the longest word

    // Iterate through the string
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            // If the current character is not a space, increment the current word length
            currentLength++;
        } else {
            // If the current character is a space, check if the current word is the longest
            if (currentLength > maxLength) {
                maxLength = currentLength;
                start = i - currentLength; // Update the start index of the longest word
                end = i; // Update the end index of the longest word
            }
            currentLength = 0; // Reset the current word length
        }
    }

    // Check the last word in case it is the longest
    if (currentLength > maxLength) {
        maxLength = currentLength;
        start = stringLength(str) - currentLength; // Update the start index of the longest word
        end = stringLength(str); // Update the end index of the longest word
    }

    // Copy the longest word to the result buffer
    int j = 0;
    for (int i = start; i < end; i++) {
        result[j++] = str[i];
    }
    result[j] = '\0'; // Null-terminate the result string
}

bool isRotation(char* str1, char* str2){

    // If the lengths are different, str2 cannot be a rotation of str1
    if (stringLength(str1) != stringLength(str2)) return false;

    // Create a new string by concatenating str1 with itself
    char K[stringLength(str1) * 2 + 1]; // +1 for null terminator
    stringCopy(K, str1);
    stringConcat(K, str1);

    // Check if str2 is a substring of K
    return (findSubString(K, str2) != -1);
}

int countChar(char* str, char ch){

    int count = 0; // Counter for the character occurrences

    // Iterate through the string
    while (*str) {
        if (*str == ch)
            count++; // Increment the counter if the character matches
    
        str++; // Move to the next character
    }

    return count; // Return the total count

}


