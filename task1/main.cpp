#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <map>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <numeric>

// Returns "true" if value 'val' is in the bounds
bool isValueInBounds(const int &val)
{
    return ((val >= 1) and (val <= 10000));
}

// Returns "true" if string 'str' has [1;15] symbols
// and all of symbols are alphabetic letters
bool isValidString(const std::string &str)
{
    if (not((str.length() >= 1) and (str.length() <= 15)))
        return false;

    for (auto ch : str)
    {
        if (not isalpha(ch))
            return false;
    }
    return true;
}

// Returns vector of strings which is gets from the 'str' separated by delimeter 'delim'
std::vector<std::string> splitVecStringBy(std::string &str, const char &delim) noexcept
{
    std::vector<std::string> vec;
    std::stringstream ss(str);
    while (std::getline(ss, str, delim))
    {
        vec.push_back(str);
    }
    return vec;
}

// Returns count of unique symbols in the string 'str'
int countOfUniqueSymbols(const std::string &str)
{
    std::map<char, int> m;
    size_t i{0UL};

    while (i < str.length())
    {
        m[str[i]]++;
        i++;
    }

    return m.size();
}

int main()
{
    // '.' is used because letter 'a' in this string is in 0 index, but
    // letter 'a' is not 0, it's 1st letter of letter
    std::string alphabet{".abcdefghijklmnopqrstuvwxyz"};

    // Disables synchronization with printf/scanf and synchronization of cin/cout streams with each other.
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Count of people
    int n{0};
    std::cin >> n;

    // Checking that count of people is in bounds
    if (not isValueInBounds(n))
    {
        std::cerr << "Value invalid!. Exiting" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Creating csv with vector of string
    std::vector<std::string> csv;
    for (int i{0}; i < n; i++)
    {
        std::string str{""};
        std::cin >> str;
        csv.push_back(str);
    }

    // Iterating by csv lines
    for (size_t i{0UL}; i < csv.size(); i++)
    {
        std::vector<std::string> person{splitVecStringBy(csv.at(i), ',')};
        std::string fullName{person.at(0UL) + person.at(1UL) + person.at(2UL)};
        int countOfUniqueInFullName{countOfUniqueSymbols(fullName)};

        std::string dayMonth{person.at(3UL) + person.at(4UL)};
        // Expression in the brackets {} returns sum of only digits in the string
        int sum{
            std::accumulate(std::begin(dayMonth), std::end(dayMonth), 0, [](unsigned i, char &ch)
                            { return std::isdigit(ch) ? i + (ch - '0') : i; })};

        // Getting alphabetic index of the first letter from lastname
        size_t indexOfLetterInAlphabet{alphabet.find(std::tolower(*(std::cbegin(fullName))))};

        // From task:
        // For the first (by position in the word) letter of the surname,
        // its number in the alphabet (in 1-indexing) multiplied by 256 is
        // determined (the letter case is not important).
        // The resulting numbers are summed up.
        size_t resDec{countOfUniqueInFullName + sum * 64 + indexOfLetterInAlphabet * 256};

        // Using stringstream object to convert recieved "size_t" value 'resDec'
        // from decimal to hexadecimal
        std::stringstream ss;
        ss << std::uppercase << std::hex << resDec;
        std::string resHex{ss.str()};

        // Saving only 3 last (minor) digits
        if (resHex.size() >= 3UL)
        {
            std::cout << resHex.substr(resHex.size() - 3UL) << " ";
        }
        // If there are fewer significant digits, then the cipher
        // is supplemented up to 3 digits with leading zeros
        else if (resHex.size() < 3UL)
        {
            while (resHex.size() < 3UL)
            {
                resHex += '0';
            }
            std::cout << resHex << " ";
        }
    }
    // Using ADL (argument dependent lookup) to transfer '\n' to output stream
    std::endl(std::cout);

    return EXIT_SUCCESS;
}
