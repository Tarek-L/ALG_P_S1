#include <stdbool.h>
#include <stdio.h>
#include "strop.h"

int main()
{
    //test stringLength
    printf("the length of \"string str\" is %d\n",stringLength("string str"));

    //test stringCopy
    char dest[20];
    stringCopy(dest,"foo bar");
    printf("%s \n",dest);

    //test stringConcat
    char hello[20] = "hello";
    stringConcat(hello," world");
    printf("%s\n",hello);

    //test stringCompare 
    printf("%d\n",stringCompare("blitz","foobar"));


    //test isEmpty
    printf("\"\" is empty : %s\n", isEmpty("") ? "True" : "False");
    printf("\"fizbuzz\" is empty : %s\n", isEmpty("fizzbuzz") ? "True" : "False");

    //reverseString 
    reverseString(dest);
    printf ("%s\n",dest);

    //toUpper
    toUpperCase(dest);
    printf ("%s\n",dest);

    //toLower
    toLowerCase(dest);
    printf ("%s\n",dest);

    //test isPalindrome
    printf("madam is palindrome : %s\n", isPalindrome("madam") ? "True" : "False");
    printf("\"fizbuzz\" is palindrome : %s\n", isPalindrome("fizzbuzz") ? "True" : "False");

    //test countVowConst
    int v,c;
    countVowelsConst(dest,&v,&c);
    printf("vowels are %d and const are %d in \"foo bar\"\n",v,c);

    // test findSubString
    printf("\"hello world\" contains \"world\" at index: %d (Expected: 6)\n", findSubString("hello world", "world"));
    printf("\"hello world\" contains \"hello\" at index: %d (Expected: 0)\n", findSubString("hello world", "hello"));
    printf("\"hello world\" contains \"test\" at index: %d (Expected: -1)\n", findSubString("hello world", "test"));
    printf("Empty string contains an empty string at index: %d (Expected: 0)\n", findSubString("", ""));

	//test removeWhitespaces
    char str1[] = "hello world";
    removeWhitespaces(str1);
    printf("\"hello world\" without spaces: \"%s\" (Expected: \"helloworld\")\n", str1);

    // Test charFreq
    char testStr[] = "hello";
    int freq[26] = {0};
    charFrequency(testStr, freq);
    printf("Frequency of characters in \"%s\":\n", testStr);
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", 'a' + i, freq[i]);
        }
    }

    // Test isAnagram
    char li[] ="listen",sl[] = "silent",debit[] = "debit card",credit[] = "bad credit",apple[] = "apple",pale[] = "pale";
    printf("\"listen\" and \"silent\" are anagrams: %s\n", isAnagram(li,sl) ? "True" : "False");
    printf("\"debit card\" and \"bad credit\" are anagrams: %s\n", isAnagram(debit,credit) ? "True" : "False");
    printf("\"apple\" and \"pale\" are anagrams: %s\n", isAnagram(apple,pale) ? "True" : "False");

    // Test countWords
    char str2[] = "   This is a test   ";
    printf("\"%s\" has %d words\n", str2, countWords(str2));

    char str3[] = ""; 
    printf("\"%s\" has %d words\n", str3, countWords(str3));

    // Test removeDuplicates
    char str11[] = "hello";
    removeDuplicates(str11);
    printf("\"hello\" after removing duplicates: \"%s\"\n", str11);

    char str12[] = "programming";
    removeDuplicates(str12);
    printf("\"programming\" after removing duplicates: \"%s\"\n", str12);

    char str13[] = "aabbcc";
    removeDuplicates(str13);
    printf("\"aabbcc\" after removing duplicates: \"%s\"\n", str13);






}
