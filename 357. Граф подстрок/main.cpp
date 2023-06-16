#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

int main()
{
    int T{}; // Кол-во слов
    std::cin >> T;

    std::unordered_map<std::string, int> e(T); // Ребра графа
    std::unordered_set<std::string> v(T);      // Вершины графа
    std::string S;                             // Слово
    for (int i{}; i < T; i++)
    {
        std::cin >> S;
        for (size_t j{}; j < S.length() - 3ul; j++)
        {
            std::string sub1(S.substr(j, 3ul)), sub2(S.substr(j + 1ul, 3ul)), subs(sub1 + sub2);
            v.insert(sub1);
            v.insert(sub2);
            e[subs]++;
        }
    }

    // Выводим кол-во вершин
    std::cout << v.size() << std::endl;

    // Выводим кол-во пар вершин 'e', между которыми есть ориентированные ребра
    std::cout << e.size() << std::endl;

    // Выводим слово w_s​, соответствующее началу ребра, затем слово
    // w_f​, соответствующее концу ребра, и вес ориентированного ребра из вершины w_s​ в w_f
    for (auto const &x : e)
        std::cout << x.first.substr(0ul, 3ul)
                  << ' ' << x.first.substr(3ul, 3ul)
                  << ' ' << x.second << '\n';

    return EXIT_SUCCESS;
}
