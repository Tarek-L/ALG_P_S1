#ifndef STROP_H
#define STROP_H

int stringLength(char *str);

void stringCopy(char *dest,const char *src);

void stringConcat(char* dest,const char* src);

int stringCompare(const char* str1,const char* str2);

bool isEmpty(char* str);

void reverseString(char* str);

void toUpperCase(char* str);

void toLowerCase(char* str);

bool isPalindrome(char* str);

void countVowelsConst(char* str,int* vow,int* cons);

int findSubString(const char* str,const char* sub);

void removeWhitespaces(char* str);

void charFrequency(char* str,int* freq);

bool isAnagram(char* str1,char* str2);

int countWords(char* str);

void removeDuplicates(char* str);

void intToString(int num, char* str);

void compressString(char* str, char* result);

void longestWord(char* str, char* result);

bool isRotation(char* str1, char* str2);

#endif
