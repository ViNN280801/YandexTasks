#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <array>   // For "std::array"
#include <iomanip> // For "std::fixed" and "std::setprecision"

/// @brief Describes dishes
typedef struct
{
    std::string name;                                  // Name of the dish (max len = 20 letters)
    ushort friends_count;                              // Count of friends which are want this dish (1 <= val <= 100)
    ushort ingr_count;                                 // Count of ingredients in this dish (1 <= val <= 100)
    std::vector<std::pair<std::string, ushort>> ingrs; // Name of the ingredient and it's amount
    std::array<double, 4ul> nutr_val;                  // The content of proteins (pr), fats (f), carbohydrates (ch) and the
                                                       // energy value (fv) of the ingredient, respectively, given by real
                                                       // numbers with no more than six decimal places
                                                       // (0 <= pr,f,ch <= 1000; 0 <= fv <= 10000)
} dishes_desc_t;

/// @brief Describes ingredients
typedef struct
{
    ushort amount;                    // Amount of ingredient (1 <= val <= 1000)
    ushort amount_to_buy;             // Amount of ingredients to buy them
    ushort cost;                      // Cost of the ingredient (1 <= val <= 1000)
    ushort quantity_in_package;       // Quantity of ingredient in a package in units (1 <= val <= 1000)
    std::array<double, 4ul> nutr_val; // The content of proteins (pr), fats (f), carbohydrates (ch) and the
                                      // energy value (fv) of the ingredient, respectively, given by real
                                      // numbers with no more than six decimal places
                                      // (0 <= pr,f,ch <= 1000; 0 <= fv <= 10000)
} ingr_desc_t;

/**
 * @brief Gets amount of ingredients and it's measurement unit
 * @return Amount of ingredients
 */
ushort get_ingr_props()
{
    ushort amount{};
    std::string measr_unit;

    // Get amount of ingredient and it's measurement unit
    std::cin >> amount >> measr_unit;

    // Changing amount if it's necessary
    if (measr_unit == "kg" || measr_unit == "l")
        amount *= 1000;
    if (measr_unit == "tens")
        amount *= 10;

    return amount;
}

int main()
{
    // Count of dishes (1 <= val <= 1000)
    ushort n{};
    std::cin >> n;

    // Variable to store description of 'n' dishes
    std::vector<dishes_desc_t> dishesDesc(n);

    // Variable to store description of ingridients (key is name of the ingridient (max len = 20 letters))
    std::unordered_map<std::string, ingr_desc_t> ingr_map;

    // Filling description of each dish
    for (ushort i{}; i < n; i++)
    {
        // Filling name of the dish, count of friends and count of ingredients
        std::cin >> dishesDesc.at(i).name >> dishesDesc.at(i).friends_count >> dishesDesc.at(i).ingr_count;

        // Reserving space to store ingredients in future
        dishesDesc.at(i).ingrs.resize(dishesDesc.at(i).ingr_count);

        // Filling name of the ingredient, it's amount and measurent unit
        for (int j{}; j < dishesDesc.at(i).ingr_count; j++)
        {
            std::cin >> dishesDesc.at(i).ingrs.at(j).first;
            dishesDesc.at(i).ingrs.at(j).second = get_ingr_props();
        }
    }

    // Count of ingredients in the price list (1 <= val <= 1000)
    ushort k{};
    std::cin >> k;

    // Variable to store description of ingredients in the price list
    std::vector<ingr_desc_t> ingrDesc(k);

    // Filling ingredients description in the price list
    for (ushort i{}; i < k; i++)
    {
        // Filling name of the ingredient and it's cost
        std::string name;
        ushort cost{};
        std::cin >> name >> cost;

        // Filling map of ingredients with current ingredient to avoid repetitions
        ingr_desc_t &ingr{ingr_map[name]};
        ingr.cost = cost;

        // Get amount of ingredient and it's measurement unit
        ingr.amount = get_ingr_props();
    }

    // Count of ingredients in the food catalogue (1 <= val <= 1000)
    ushort m{};
    std::cin >> m;

    // Filling ingredients description in the food catalogue
    for (ushort i{}; i < m; ++i)
    {
        // Getting name of the ingredient
        std::string name;
        std::cin >> name;

        // Filling map of ingredients with current ingredient to avoid repetitions
        ingr_desc_t &ingr{ingr_map[name]};

        // Getting quantity in package and it's measurement unit
        ingr.quantity_in_package = get_ingr_props();

        // Filling nutririon values (proteins, fats, carbohydrates and the energy value)
        for (char j{}; j < 4; j++)
            std::cin >> ingr.nutr_val.at(j);

        // If count of ingredients is nil -> erase this ingredient as unnecessary
        if (ingr.amount == 0)
            ingr_map.erase(name);
    }

    for (ushort i{}; i < n; i++)
    {
        for (size_t j{}; j < dishesDesc.at(i).ingrs.size(); j++)
        {
            ingr_desc_t &ingr{ingr_map.at(dishesDesc.at(i).ingrs.at(j).first)};
            ingr.amount_to_buy += dishesDesc.at(i).friends_count * dishesDesc.at(i).ingrs.at(j).second;
            for (char k{}; k < 4; k++)
                dishesDesc.at(i).nutr_val.at(k) +=
                    (static_cast<double>(dishesDesc.at(i).ingrs.at(j).second) /
                     static_cast<double>(ingr.quantity_in_package)) *
                    ingr.nutr_val.at(k);
        }
    }

    // How much Vasya would spent money to prepare for it's birthday
    ulong money{};

    // Iterating by all non-repeating ingredients
    // Taking info about the ingredient from the catalog,
    // multiply by it's quantity in the dish and divide by
    // the quantity specified in the catalogue,
    // and adding this calculation to the total amount
    for (auto &ingr : ingr_map)
    {
        ingr.second.amount_to_buy = (ingr.second.amount_to_buy + ingr.second.amount - 1) / ingr.second.amount;
        money += static_cast<ulong>(ingr.second.amount_to_buy) * static_cast<ulong>(ingr.second.cost);
    }

    // Outputting money to prepare for holiday
    std::cout << money << '\n';

    // Outputting ingredients and their's costs
    for (auto const &ingr : ingr_map)
        std::cout << ingr.first << ' ' << ingr.second.amount_to_buy << '\n';

    // Iterating by dishes
    for (ushort i{}; i < n; i++)
    {
        // Outputting name of the dish
        std::cout << dishesDesc.at(i).name << ' ';
        for (char j{}; j < 4; j++)
        {
            // Outputting nutrition values of each dish (with certain precision of floating point)
            std::cout << std::fixed << std::setprecision(10) << dishesDesc.at(i).nutr_val.at(j) << ' ';

            // Moving to the next line when loop enumerates all of nutrition values
            if (j == 3)
                std::endl(std::cout);
        }
    }

    return EXIT_SUCCESS;
}
