#include <iostream>
#include <vector>
#include <algorithm>
#include <concepts>
#include <ranges>
#include <span>

/**
 * @brief Generates new array that contains only unique elems
 * @tparam rangeA 1st range of elems
 * @tparam rangeB 2nd range of elems
 * @return Vector of an unique elems got from 2 sequences
 */
template <std::integral T>
constexpr std::vector<T> getUniqueElementsFromTwoSequences(std::span<T const> rangeA, std::span<T const> rangeB)
{
    // Copying all elements from the both of ranges to one vector
    std::vector<T> uniqVec(rangeA.begin(), rangeA.end());
    std::ranges::copy(rangeB, std::back_inserter(uniqVec));

    // Sorting vector
    std::ranges::sort(uniqVec);

    // Removing all non-unique elems
    auto it = std::remove_if(uniqVec.begin(), uniqVec.end(), [&uniqVec](T const &val)
                             { return std::ranges::count(uniqVec, val) > 1; });

    // Erase the removed elements
    uniqVec.erase(it, uniqVec.end());

    return uniqVec;
}

int main()
{
    // Count of cards that have player A (N) and player B (M), and count of changes (Q)
    int N{}, M{}, Q{};
    std::cin >> N >> M >> Q;

    // Player A's card values
    std::vector<unsigned> playerA_cards(N);
    for (int i{}; i < N; i++)
        std::cin >> playerA_cards.at(i);

    // Player B's card values
    std::vector<unsigned> playerB_cards(M);
    for (int i{}; i < M; i++)
        std::cin >> playerB_cards.at(i);

    for (int i{}; i < Q; i++)
    {
        short type{};    // Type of the change
        char player{};   // Player A or B
        unsigned card{}; // Value of a card to change

        std::cin >> type >> player >> card;

        if (type == 1)
        {
            if (player == 'A')
                playerA_cards.push_back(card);
            else if (player == 'B')
                playerB_cards.push_back(card);
            else
                return EXIT_FAILURE;
        }
        else if (type == -1)
        {
            if (player == 'A')
                playerA_cards.erase(std::remove(std::begin(playerA_cards), std::end(playerA_cards), card));
            else if (player == 'B')
                playerB_cards.erase(std::remove(std::begin(playerB_cards), std::end(playerB_cards), card));
            else
                return EXIT_FAILURE;
        }
        else
            return EXIT_FAILURE;

        // Array for unique elems
        std::vector<unsigned> uniqueElems(getUniqueElementsFromTwoSequences<unsigned>(playerA_cards, playerB_cards));
        std::cout << uniqueElems.size() << ' ';
    }
    std::endl(std::cout);

    return EXIT_SUCCESS;
}
