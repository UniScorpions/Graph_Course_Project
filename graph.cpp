#include <iostream>
#include <string>
#include <fstream>
#include "graph.hpp"

map<int, set<int>> input_from_file() {
    string str;
    cout << "Enter the file name: ";
    cin >> str;
    ifstream gif(str);
    if (!gif) exit(7);
    map<int, set<int>> a_l;
    int i = 0;
    gif.clear();
    gif.seekg(0, ios::beg);
    while (getline(gif, str)) {
        str = str.substr(3);
        while ((str.find(" ")) != string::npos) {
            str.erase(0, str.find(" ") + 1);
            string token = str.substr(0, str.find(" "));
            a_l[i].insert(stoi(token));
        }
        i++;
    }
    return a_l;
}

int main() {
    Graph g(input_from_file());
    g.is_tree() ?
        cout << "This graph from the file is a tree :)" << endl :
        cout << "This graph from the file is not a tree :(" << endl;

    Graph g1;
    g1.add_vertex$edge(0, 1);
    g1.add_vertex$edge(0, 2);
    g1.add_vertex$edge(0, 3);
    g1.add_vertex$edge(3, 4);
    g1.is_tree() ?
        cout << "This graph is a tree :)" << endl :
        cout << "This graph is not a tree :(" << endl;

    Graph g2;
    g2.add_vertex$edge(1, 0);
    g2.add_vertex$edge(0, 2);
    g2.add_vertex$edge(2, 1);
    g2.add_vertex$edge(0, 3);
    g2.add_vertex$edge(3, 4);
    g2.is_tree() ?
        cout << "This graph is a tree :)" << endl :
        cout << "This graph is not a tree :(" << endl;
}