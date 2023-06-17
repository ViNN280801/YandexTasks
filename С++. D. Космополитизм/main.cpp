#include <iostream>
#include <unordered_map>
#include <array>
#include <vector>

int main()
{
    // Countries
    int N{};
    std::cin >> N;

    // Allocating memory for matrix
    int **countriesProps = new int *[3];
    for (int i{}; i < 3; i++)
        countriesProps[i] = new int[N];

    // Filling all properties of the countries (min salary,
    // availibility of the high education and availibility of moving
    // to another country)
    for (int i{}; i < 3; i++)
        for (int j{}; j < N; j++)
            std::cin >> countriesProps[i][j];

    // Count of classmates
    int Q{};
    std::cin >> Q;

    // Allocating memory for matrix
    int **classmatesProps = new int *[3];
    for (int i{}; i < 3; i++)
        classmatesProps[i] = new int[Q];

    // Filling all properties of the classmates (salary,
    // availibility of the high education and citizenship of the parents)
    for (int i{}; i < 3; i++)
        for (int j{}; j < Q; j++)
            std::cin >> classmatesProps[i][j];

    std::unordered_map<int, std::array<int, 3>> countriesMap, classmatesMap;

    for (int i{}; i < N; i++)
        countriesMap[i + 1] = {countriesProps[0][i], countriesProps[1][i], countriesProps[2][i]};

    for (int i{}; i < Q; i++)
        classmatesMap[i + 1] = {classmatesProps[0][i], classmatesProps[1][i], classmatesProps[2][i]};

    std::vector<int> arr;

    for (int i{1}; i <= Q; i++)
    {
        int val{};

        for (int j{1}; j <= N; j++)
        {
            if (classmatesMap[i][0] == 0 &&
                classmatesMap[i][1] == 0 &&
                classmatesMap[i][2] == 0)
            {
                if (countriesMap[j][0] == 0 && countriesMap[j][1] == 0 &&
                    (countriesMap[j][2] == 0 || countriesMap[j][2] == 1))
                {
                    val = j;
                    break;
                }
            }

            if (((classmatesMap[i][0] >= countriesMap[j][0]) &&
                 (classmatesMap[i][1] - countriesMap[j][1] >= 0)) ||
                ((classmatesMap[i][2] == j) &&
                 (countriesMap[j][2] == 1)))
            {
                val = j;
                break;
            }
        }

        (val == 0) ? arr.push_back(0) : arr.push_back(val);
    }

    // Deallocating memory
    for (int i{}; i < 3; i++)
        delete[] countriesProps[i];
    delete[] countriesProps;
    countriesProps = nullptr;

    for (int i{}; i < 3; i++)
        delete[] classmatesProps[i];
    delete[] classmatesProps;
    classmatesProps = nullptr;

    std::string s("");
    for (size_t i{}; i < arr.size(); i++)
        s += std::to_string(arr[i]) + " ";
    std::cout << s << std::endl;

    return EXIT_SUCCESS;
}
