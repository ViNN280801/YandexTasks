#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < n; i++)

// Returns "true" if value 'val' is in the bounds
bool isValueInBounds(const int &val, const int &min, const int &max)
{
    return ((val >= min) and (val <= max));
}

// Returns "true" if ID is in the bounds
bool isIDInBounds(const size_t &id)
{
    return (id <= 1000000000UL);
}

// Returns vector of symbols in the string 'str', except any 'delim'eters
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

void print2dVector(const std::vector<std::vector<std::string>> &vec)
{
    for (size_t i{0UL}; i < vec.size(); i++)
    {
        for (size_t j{0UL}; j < vec.at(i).size(); j++)
        {
            std::cout << vec.at(i).at(j) << '\t';
        }
        std::endl(std::cout);
    }
}

bool multipleCompareData(const std::vector<std::string> &a, const std::vector<std::string> &b)
{
    return ((a.at(0UL) < b.at(0UL)) or (a.at(1UL) < b.at(1UL)) or
            ((a.at(2UL) < b.at(2UL))) or (a.at(4UL) < b.at(4UL)));
}

int main()
{
    // Entering count of the logs
    int n{0};
    std::cin >> n;

    // Checking that count of logs is in bounds
    if (not isValueInBounds(n, 2, 200000))
    {
        std::cerr << "Value invalid!. Exiting" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Filling the vector
    std::vector<std::string> vec;
    getchar();
    forn(i, n)
    {
        std::string str{""};
        std::getline(std::cin, str);
        vec.push_back(str);
    }

    std::vector<std::vector<std::string>> mainVec;

    // Checking validity of all data in the vector
    for (size_t i{0UL}; i < vec.size(); i++)
    {
        std::vector<std::string> checkVec{splitVecStringBy(vec.at(i), ' ')};
        if ((not isValueInBounds(std::stoi(checkVec.at(0UL)), 1, 365)) or
            (not isValueInBounds(std::stoi(checkVec.at(1UL)), 0, 24)) or
            (not isValueInBounds(std::stoi(checkVec.at(2UL)), 0, 60)) or
            (not isIDInBounds(std::stoul(checkVec.at(3UL)))) or
            ((checkVec.at(4UL).at(0UL) not_eq 'A') and (checkVec.at(4UL).at(0UL) not_eq 'B') and
             (checkVec.at(4UL).at(0UL) not_eq 'C') and (checkVec.at(4UL).at(0UL) not_eq 'S')))
        {
            std::cerr << "Error. Entered values are not in the bounds. Exiting...\n";
            exit(EXIT_FAILURE);
        }

        mainVec.push_back(checkVec);
    }

    std::sort(
        std::begin(mainVec), std::end(mainVec),
        [](const std::vector<std::string> &a, const std::vector<std::string> &b)
        {
            return multipleCompareData(a, b);
        });
    print2dVector(mainVec);

    return EXIT_SUCCESS;
}
