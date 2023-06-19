#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <limits>

/* === Type aliases for graph and markups vector === */
using graph_type = std::vector<std::vector<std::pair<int, int>>>;
using markups_type = std::vector<int>;
/* ================================================= */

bool traverse(graph_type &graph, markups_type &markups, int final_vertex, int markup, int bound)
{
    // Mark final vertex with specified value
    markups.at(final_vertex) = markup;

    // Traverse graph verteces
    for (auto const &edge : graph.at(final_vertex))
    {
        // If right node of the edge bigger than limitation value -> pass it
        if (edge.second >= bound)
            continue;

        // If left node of the graph is in markups and it equals to markup returning false
        if (markups.at(edge.first) == markup)
            return false;

        // If left node of the graph is in markups and it equals to -1 traverse graph again
        // and if it returns false -> return false as a result
        if (markups.at(edge.first) == -1)
            if (!traverse(graph, markups, edge.first, 1 - markup, bound))
                return false;
    }
    return true;
}

bool check_bounds(graph_type &graph, markups_type &markups, int nodes, int bound)
{
    // Traversy graph by it's nodes
    for (int i{}; i < nodes; i++)
        // If vertex marked with value '-1'
        if (markups.at(i) == -1)
            // And if
            if (!traverse(graph, markups, i, 0, bound))
                return false;
    return true;
}

int main()
{
    // Count of nodes and count of edges of graph (3 <= val <= 10'000)
    int nodes{}, edges{};
    std::cin >> nodes >> edges;

    // Variable that represents graph
    graph_type graph(nodes);

    // Filling edges in format (u, v, w) (1 <= u,v <= nodes, u != v, 1 <= w <= 10^5)
    // u - initial vertex of th edge
    // v - final vertex of the edge
    // w - weight of the edge
    for (int i{}; i < edges; i++)
    {
        int u{}, v{}, w{};
        std::cin >> u >> v >> w;

        // Decreasing initial and final verteces
        u--;
        v--;

        // Adding final vertex and it's weight to the graph
        graph.at(u).emplace_back(v, w);

        // Adding initial vertex and it's weight to the graph
        graph.at(v).emplace_back(u, w);
    }

    // Initial and final verteces correspondingly
    int initial_vertex{}, final_vertex{std::numeric_limits<int>::max()};

    // Markup vector of graph
    markups_type markups;

    // Traverse of graph
    while (final_vertex - initial_vertex > 1)
    {
        int middle{(initial_vertex + final_vertex) / 2};

        // Replacing 'n' nodes with value -1
        markups.assign(nodes, -1);

        // If markup is '-1'
        if (!check_bounds(graph, markups, nodes, middle))
            final_vertex = middle;
        else
            initial_vertex = middle;
    }
    std::cout << initial_vertex << '\n';

    return EXIT_SUCCESS;
}
