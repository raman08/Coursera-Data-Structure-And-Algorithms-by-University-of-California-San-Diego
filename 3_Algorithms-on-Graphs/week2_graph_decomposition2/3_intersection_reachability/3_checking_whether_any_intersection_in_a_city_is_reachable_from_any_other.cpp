#include <algorithm>
#include <iostream>
#include <set>
#include <stdexcept>
#include <vector>

// Class for directed Graphs
class DiGraph
{

    vector<vector<int>> adj;
    vector<vector<int>> _reverseadj;

    size_t _size{0};

    void _explore(const int node, set<int> &visited)
    {

        visited.insert(node);
        for (auto a : this->adj[node])
        {

            if (visited.find(a) == visited.end())
                this->_explore(a, visited);
        }
    }

    void _reverse_explore(const int node, set<int> &visited, vector<int> &ordering)
    {

        visited.insert(node);
        for (auto a : this->_reverseadj[node])
        {
            if (visited.find(a) == visited.end())
            {
                this->_reverse_explore(a, visited, ordering);
            }
        }

        ordering.push_back(node);
    }

public:
    DiGraph(size_t size)
        : adj(size, vector<int>()), _reverseadj(size, vector<int>()), _size(size) {}

    void add_edges(const size_t m)
    {
        for (size_t j = 0; j < m; ++j)
        {
            size_t s, t;
            cin >> s >> t;

            this->adj[s - 1].push_back(t - 1);

            this->_reverseadj[t - 1].push_back(s - 1);
        }
    }

    void display()
    {
        cout << "# nodes = " << this->_size << endl;
        cout << "Adjacencies: " << endl;

        for (size_t node = 0; node < this->_size; ++node)
        {
            cout << node + 1 << " -> ";
            for (auto a : this->adj[node])
            {
                cout << a + 1 << " ";
            }

            cout << endl;
        }
    }

    vector<int> get_reverse_post_order()
    {

        vector<int> ordering;
        set<int> visited;

        for (int node = 0; node < this->_size; ++node)
        {

            if (visited.find(node) == visited.end())
            {
                this->_reverse_explore(node, visited, ordering);
            }
        }

        reverse(ordering.begin(), ordering.end());

        return ordering;
    }

    size_t number_of_strong_components()
    {
        if (this->_size == 0)
        {
            return 0;
        }
        set<int> visited;
        size_t ncomponents = 0;

        auto node_list = get_reverse_post_order();
        for (auto node : node_list)
        {

            if (visited.find(node) == visited.end())
            {
                this->_explore(node, visited);
                ncomponents++;
            }
        }

        return ncomponents;
    }
};

int main()
{
    size_t n, m;
    cin >> n >> m;

    DiGraph graph(n);

    graph.add_edges(m);

    cout << graph.number_of_strong_components() << endl;
}