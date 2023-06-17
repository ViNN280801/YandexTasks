#include <iostream>
#include <algorithm>

#include "json.hpp"

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, m;
    std::cin >> n >> m;
    nlohmann::json feed;
    feed["offers"] = nlohmann::json::array();
    auto &offers = feed["offers"];

    std::string s;
    std::getline(std::cin, s);
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::getline(std::cin, s);
        nlohmann::json parsed = nlohmann::json::parse(s);
        for (const auto &offer : parsed["offers"])
        {
            if (offers.size() < m)
            {
                offers.push_back(offer);
            }
        }
    }

    std::cout << feed << std::endl;
    return 0;
}