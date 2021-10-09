/** Copyright 2021 Shon Cortes  
 *  @Authors
 * Shon Cortes 
 * From the following function printPosition(), extract a new function  
 * that  returns  the  position  of  the  beginning  of  a  given  string  
 * in  a given text.
 */


#include <iostream>
#include <string>
#include <limits>


void printPosition() {
    int i, j;
    char text[1024] = "1234567890";
    int text_length = 10;
    char array_to_search1[4]= "23";
    int array_to_search1_length = 2;
    int position1 = -1;

    for (i = 0; i < text_length - array_to_search1_length + 1; i++) {
        bool found = true;

        for (j = 0; j < array_to_search1_length; j++) {
            if (text[i + j] != array_to_search1[j]) {
                found = false;
            }

            if (found) {
                position1 = i;
                break;
            }
        }
    }

    std::cout << position1 << std::endl;
}

/**
 * @brief Searches a given text for a given string.
 * 
 * @param text Text to be searched
 * @param str String to search for
 * @return int Index at which the string begins
 */
int StrPosition(std::string text, std::string str) {
    int str_len = str.size();
    int txt_len = text.size();
    int j = 0;
    int pos = -1;

    for (int i = 0; i < txt_len - str_len + 1; i++) {
        bool found = true;

        for (int j = 0; j < str_len; j++) {
            if (text[i + j] != str[j]) {
                found = false;
            }
        }

        if (found) {
            pos = i;
            break;
        }
    }

    std::cout << "the word " + str + " begins at position: " << pos <<std::endl;
}

int main() {
    // printPosition();

    std::string text = "";
    std::string word = "";

    std::cout << "Please enter a sentence: ";
    std::getline(std::cin, text);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();

    std::cout << "Please enter a word to search for: ";
    std::getline(std::cin, word);

    StrPosition(text, word);
}
