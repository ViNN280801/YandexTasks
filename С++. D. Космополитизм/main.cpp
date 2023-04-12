#include <iostream>
#include <vector>
#include <unordered_map>

#define FOR_I(N) for (int i{}; i < N; i++)
#define FOR_J(N) for (int j{}; j < N; j++)

#define FOR_I_FROM1_TO_N(N) for (int i{1}; i <= N; i++)
#define FOR_J_FROM1_TO_N(N) for (int j{1}; j <= N; j++)

#define FOR_INPUT_MATRIX(N_I, N_J, mx) \
    FOR_I(N_I)                         \
    FOR_J(N_J)                         \
    std::cin >> mx[i][j];

int main()
{
    // Countries
    int N{};
    std::cin >> N;

    // Filling all properties of the countries (min salary,
    // availibility of the high education and availibility of moving
    // to another country)
    std::vector<std::vector<int>> countriesProps(3UL, std::vector<int>(N));
    FOR_INPUT_MATRIX(3, N, countriesProps)

    // Count of classmates
    int Q{};
    std::cin >> Q;

    // Filling all properties of the classmates (salary,
    // availibility of the high education and citizenship of the parents)
    std::vector<std::vector<int>> classmatesProps(3UL, std::vector<int>(Q));
    FOR_INPUT_MATRIX(3, Q, classmatesProps)

    std::unordered_map<int, std::vector<int>> countriesMap, classmatesMap;

    FOR_I(N)
    countriesMap[i + 1] = {countriesProps[0][i], countriesProps[1][i], countriesProps[2][i]};

    FOR_I(Q)
    classmatesMap[i + 1] = {classmatesProps[0][i], classmatesProps[1][i], classmatesProps[2][i]};

    std::vector<int> arr;

    FOR_I_FROM1_TO_N(Q)
    {
        int val{};

        FOR_J_FROM1_TO_N(N)
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

    std::string s("");
    FOR_I(static_cast<int>(arr.size()))
    s += std::to_string(arr[i]) + " ";
    std::cout << s << std::endl;

    return EXIT_SUCCESS;
}
