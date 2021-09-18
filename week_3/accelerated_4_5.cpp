// Write a function that reads words from an input stream and stores them in a vector. 
// Use that function both to write programs that count the number of words in the input, 
// and to count how many times each word occurred.

#include <iostream>
#include <vector>
#include <limits>
#include <bits/stdc++.h>

/**
 * @brief Get the Words object. Asks for list of words to be entered. Prints the total number of words entered and the number of times each word appeared in the list.
 * 
 * @return std::vector<std::string> Stored list of words.
 */
std::vector<std::string> GetWords()
{
    
    std::cout<<"Please enter a word. Press 'Enter' to input the next word. Enter 'f' when finished: " << std::endl;

    std::vector<std::string> words;

    std::string x;

    while (true)
        {
            std::cin >> x;
            if (x == "f")
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear(); 
                break;
            }
            else
            {
                words.push_back(x);
            }
            
        }

    int total_words = words.size();
    std::cout<< "There were " << total_words << " words entered." << std::endl;

    for(std::string word : words)
    {

        int cnt = std::count(words.begin(), words.end(), word);
        std::cout<< word << ": " << cnt << std::endl;

    }

    return words;

}

int main()
{

    GetWords();

}