/**
 * Задача 1:
0 1
0 2
0 4
0 5
1 4
1 3
2 4
2 3
3 4
3 5
 * Задача 2:
0 1
0 2
1 2
1 3
1 4
2 4
2 5
3 6
4 6
5 4
5 7
6 7
6 8
7 8
8 8
 */

#include <map>
#include <list>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

/**
 * Выводит Эйлеров путь или Эйлеров цикл при его наличии.
 */
void find_euler_path(std::map<int, std::list<int>> g) {
    int v1 = -1;
    int v2 = -1;

    for (const auto& p : g) {
        if (p.second.size() % 2 != 0) {
            if (v1 == -1) {
                v1 = p.first;
            }
            else if (v2 == -1) {
                v2 = p.first;
            }
            else {
                std::cout << "No Euler cycles found.\n";
            }
        }
    }

    if (v1 != -1) {
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    std::vector<int> res;
    std::stack<int> s;
    s.push(v1);
    while (!s.empty()) {
        int v = s.top();
        if (g[v].size() != 0) {
            int x = *g[v].begin();
            s.push(x);
            g[v].erase(g[v].begin());
            auto it = std::find(g[x].begin(), g[x].end(), v);
            g[x].erase(it);
        }
        else {
            res.push_back(v);
            s.pop();
        }
    }

    if (v1 != -1) {
        for (size_t i = 0; i < res.size() - 1; i++) {
            if (res[i] == v1 && res[i + 1] == v2 || res[i] == v1 && res[i + 1] == v2) {
                std::vector<int> upd_res;
                upd_res.reserve(upd_res.size());
                for (size_t j = i + 1; j < res.size(); j++) {
                    upd_res.push_back(res[j]);
                }
                for (size_t j = 1; j <= i; j++) {
                    upd_res.push_back(res[j]);
                }
                res = std::move(upd_res);
            }
        }
    }

    if (std::any_of(g.begin(), g.end(), [](std::pair<int, std::list<int>> p){ return !p.second.empty(); }))
    {
        std::cout << "The graph is not coherent, so there are no Euler cycles.\n";
    }

    std::cout << "Euler path: ";
    for (size_t i = 0; i < res.size() - 1; i++) {
        std::cout << res[i] << " -> ";
    }
    std::cout << res[res.size() - 1] << '\n';
}

void topological_sort_rec(const std::map<int, std::list<int>>& g,
                          int x,
                          std::set<int>& visited,
                          std::vector<int>& res)
{
    visited.insert(x);
    for (auto v : g.at(x)) {
        if (visited.find(v) == visited.end()) {
            topological_sort_rec(g, v, visited, res);
        }
    }
    res.push_back(x);
}

/**
 * Выполняет топологическую сортировку.
 */
void topological_sort(const std::map<int, std::list<int>>& g) {
    std::set<int> visited;
    std::vector<int> res;
    for (auto& p : g) {
        if (visited.find(p.first) == visited.end()) {
            topological_sort_rec(g, p.first, visited, res);
        }
    }

    for (size_t i = 0; i < res.size() - 1; i++) {
        std::cout << res[res.size() - 1 - i] << " -> ";
    }
    std::cout << res[0] << '\n';
}

int main()
{
    // ввод для первой задачи: неориентированный граф
    std::map<int, std::list<int>> g1;
    std::cout << "Define an *undirected graph* - enter the connections between vertices.\n";
    std::string input;
    while (true) {
        std::cin >> input;
        if (input == "end")
            break;
        int a, b;
        a = atoi(input.c_str());
        std::cin >> b;
        g1[a].push_back(b);
        g1[b].push_back(a);
    }

    find_euler_path(g1);

    // ввод для второй задачи: ориентированный граф
    std::map<int, std::list<int>> g2;
    std::cout << "\nDefine a *directed graph* - enter the connections between vertices.\n";
    while (true) {
        std::cin >> input;
        if (input == "end")
            break;
        int a, b;
        a = atoi(input.c_str());
        std::cin >> b;
        g2[a].push_back(b);
    }

    topological_sort(g2);
}