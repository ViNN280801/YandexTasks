#include <iostream>
#include <string>

int main()
{
    // J - jewelery; S - rocks
    std::string J, S;
    std::cin >> J >> S;

    int count{};
    for (auto const &s : S)
        if (J.find(s) != std::string::npos)
            count++;

    std::cout << count << '\n';

    return EXIT_SUCCESS;
}
