#include <iostream>
#include <string>
#include <set>
#include <vector>

int main()
{
    // Count of words (1 <= n <= 100'000)
    uint n{};
    std::cin >> n;

    if (n < 1 || n > 100'000)
        return EXIT_FAILURE;

    // Count of pushes on keyboard
    uint count{};
    std::vector<std::string> vec(n);
    std::set<std::string> words;

    size_t lenOfAllWords{};

    // Filling 'n' words
    for (uint i{}; i < n; i++)
    {
        std::string word;
        std::cin >> word;
        vec.emplace_back(word);

        if (word.empty() || word.length() > 1'000)
            return EXIT_FAILURE;

        lenOfAllWords += word.length();

        // Adding first word to the set and adding length of this word to count of pushes
        if (words.empty() || words.find(word) == words.cend())
        {
            count += word.length();
            words.insert(word);
        }
        else if (words.find(word) != words.cend())
        {
            uint max{};

            for (auto const &tmp_word : words)
            {
                uint temp{};
                if (tmp_word == word)
                    count++;
                if (tmp_word.length() > word.length())
                {
                    for (uint j{}; j < word.length(); j++)
                    {
                        if (tmp_word.at(j) == word.at(j))
                            temp++;
                        else
                            break;
                    }
                    if (temp > max)
                        max = temp;
                }
                else if (tmp_word.length() <= word.length() && tmp_word != word)
                {
                    for (uint j{}; j < tmp_word.length(); j++)
                    {
                        if (tmp_word.at(j) == word.at(j))
                            temp++;
                        else
                            break;
                    }
                    if (temp > max)
                        max = temp;
                }
            }
            count += max;
        }
        else
            return EXIT_FAILURE;
    }

    if (lenOfAllWords > 1'000'000)
        return EXIT_FAILURE;

    std::cout << count << '\n';

    return EXIT_SUCCESS;
}
