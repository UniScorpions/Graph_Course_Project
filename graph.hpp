#pragma once

#include <map>
#include <set>
#include <deque>

using namespace std;

class Graph {
    map<int, set<int>> adj_list;
public:
    Graph() = default;
    Graph(map<int, set<int>>);
    void add_vertex$edge(int, int);
    void add_vertex$edge(int);
    bool is_cyclic(int, int, deque<bool>&);
    bool is_tree();
    void print();
};

Graph::Graph(map<int, set<int>> a) : adj_list(a) {}

void Graph::add_vertex$edge(int u, int v) {
    adj_list[u].insert(v);
    adj_list[v].insert(u);
}

bool Graph::is_cyclic(int i, int parent, deque<bool>& v) {
    v[i] = true;
    for (auto it = adj_list[i].begin(); it != adj_list[i].end(); it++)
        if (!v[*it]) {
            if (is_cyclic(*it, i, v))
                return true;
        }
        else if (*it != parent)
            return true;
    return false;
}

bool Graph::is_tree() {
    deque<bool> visa(adj_list.size(), false);
    if (is_cyclic(0, -1, visa))
        return false;
    for (int i = 0; i < adj_list.size(); i++)
        if (!visa[i])
            return false;
    return true;
}

void Graph::print() {
    for (const auto& x : adj_list) {
        cout << x.first << " |";
        for (const auto& y : x.second)
            cout << " " << y;
        cout << endl;
    }
}
