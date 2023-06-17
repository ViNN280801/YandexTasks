#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    std::array<int, 3ul> arr = {};
    for (int i{}; i < 3; i++)
        std::cin >> arr[i];
    std::sort(arr.begin(), arr.end());
    std::cout << arr.at(1) << '\n';

    return EXIT_SUCCESS;
}
