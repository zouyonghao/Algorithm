#include <iostream>
// #include <pair>
#include <string>
#include <vector>
using namespace std;

enum NodeStatus { UNDISCOVERED, DISCOVERED, FINISHED };

struct Node {
    NodeStatus status;
    int dtime = 0;
    int ftime = 0;
};

class Solution {
  public:
    int num;
    int **Graph;
    bool backward = false;
    vector<Node *> nodes;
    int clock = 0;
    void init() {
        Graph = new int *[num];
        backward = false;
    }
    void dfs(int i) {
        nodes[i]->status = DISCOVERED;
        nodes[i]->dtime = clock++;
        for (int j = 0; j < num; j++) {
            if (Graph[i][j] == 1) {
                Node *neighbour = nodes[j];
                switch (neighbour->status) {
                case UNDISCOVERED: {
                    dfs(j);
                    break;
                }
                case DISCOVERED:
                    backward = true;
                    return;
                case FINISHED:
                    break;
                }
            }
        }
        nodes[i]->status = FINISHED;
        nodes[i]->ftime = clock++;
    }
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        num = numCourses;
        init();
        for (int i = 0; i < numCourses; i++) {
            Graph[i] = new int[numCourses];
            for (int j = 0; j < numCourses; j++) {
                Graph[i][j] = 0;
            }
            Node *node = new Node;
            node->status = UNDISCOVERED;
            nodes.push_back(node);
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            int node1 = prerequisites[i].first;
            int node2 = prerequisites[i].second;
            Graph[node2][node1] = 1;
        }
        for (int i = 0; i < numCourses; i++) {
            if (nodes[i]->status == UNDISCOVERED) {
                dfs(i);
                if (backward)
                    return false;
            }
        }
        return true;
    }
};

// 10
// [[5,6],[0,2],[1,7],[5,9],[1,8],[3,4],[0,6],[0,7],[0,3],[8,9]]
int main() {
    vector<pair<int, int>> v;
    v.push_back(pair<int, int>(5, 6));
    v.push_back(pair<int, int>(0, 2));
    v.push_back(pair<int, int>(1, 7));
    v.push_back(pair<int, int>(5, 9));
    v.push_back(pair<int, int>(1, 8));
    v.push_back(pair<int, int>(3, 4));
    v.push_back(pair<int, int>(0, 6));
    v.push_back(pair<int, int>(0, 7));
    v.push_back(pair<int, int>(0, 3));
    v.push_back(pair<int, int>(8, 9));
    Solution s;
    bool result = s.canFinish(10, v);
    if (result) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}