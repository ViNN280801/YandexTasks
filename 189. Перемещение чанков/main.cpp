#include <iostream>
#include <vector>
#include <limits>

static std::vector<int> mins; // Segment tree with dereffered modification on min
static std::vector<int> maxs; // Segment tree with dereffered modification on max
static std::vector<int> temp;

/* Each of trees contains server's numbers on which each chunks is located */

/**
 * @brief Changes values in trees
 * @param i value to be replaced with
 */
constexpr void update_trees(int i)
{
    if (temp.at(i))
    {
        int l{i * 2}, r{l xor 1};
        mins.at(l) = temp.at(i);
        mins.at(r) = temp.at(i);
        maxs.at(l) = temp.at(i);
        maxs.at(r) = temp.at(i);
        temp.at(l) = temp.at(i);
        temp.at(r) = temp.at(i);
        temp.at(i) = 0;
    }
}

constexpr std::pair<int, int> get_query_from_server(int i, int l, int r, int ll, int rr)
{
    if (r <= ll || rr <= l)
        return std::make_pair(std::numeric_limits<int>::max(), -1);
    if (ll <= l && r <= rr)
        return std::make_pair(mins.at(i), maxs.at(i));

    update_trees(i);

    int m{(l + r) / 2};
    auto a{get_query_from_server(i * 2, l, m, ll, rr)}, b{get_query_from_server((i * 2) xor 1, m, r, ll, rr)};

    return std::make_pair(std::min(a.first, b.first), std::max(a.second, b.second));
}

constexpr void change_values(int i, int l, int r, int ll, int rr, int v)
{
    if (r <= ll || rr <= l)
        return;
    if (ll <= l && r <= rr)
    {
        mins.at(i) = v;
        maxs.at(i) = v;
        temp.at(i) = v;
        return;
    }

    update_trees(i);

    int m{(l + r) / 2}, a{i * 2}, b{(i * 2) xor 1};
    change_values(a, l, m, ll, rr, v);
    change_values(b, m, r, ll, rr, v);
    mins.at(i) = std::min(mins.at(a), mins.at(b));
    maxs.at(i) = std::max(maxs.at(a), maxs.at(b));
}

int main()
{
    // Count of chunks in clusters (n), count of serverms (m), count of queries (q)
    int n{}, m{}, q{};
    std::cin >> n >> m >> q;

    int p{1};
    while (p < n)
        p *= 2;

    mins.resize(p * 2);
    maxs.resize(p * 2);
    temp.resize(p * 2);

    // Filling descriptions of chunk movement requests in chronological order
    for (int i{}; i < n; i++)
    {
        std::cin >> mins.at(i + p);
        maxs.at(i + p) = mins.at(i + p);
    }

    for (int i{p - 1}; i > 0; i--)
    {
        mins.at(i) = std::min(mins.at(i * 2), mins.at((i * 2) xor 1));
        maxs.at(i) = std::max(maxs.at(i * 2), maxs.at((i * 2) xor 1));
    }

    for (int i{}; i < q; i++)
    {
        int a{}, b{}, l{}, r{};
        std::cin >> a >> b >> l >> r;

        auto t{get_query_from_server(1, 0, p, --l, r)};

        // If we get query from server and that min and max on interval [l;r] eq to 'a'
        if (t.first == a && t.second == a)
        {
            // It is necessary to postpone changing all values on this segment to 'b'
            change_values(1, 0, p, l, r, b);
            std::cout << 1 << '\n';
        }
        else
            std::cout << 0 << '\n';
    }

    return EXIT_SUCCESS;
}
