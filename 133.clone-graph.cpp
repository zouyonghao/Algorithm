/*
 * [133] Clone Graph
 *
 * https://leetcode.com/problems/clone-graph/description/
 *
 * algorithms
 * Medium (25.15%)
 * Total Accepted:    160.2K
 * Total Submissions: 636.9K
 * Testcase Example:  '{}'
 *
 * 
 * Clone an undirected graph. Each node in the graph contains a label and a
 * list of its neighbors.
 * 
 * 
 * 
 * 
 * OJ's undirected graph serialization:
 * 
 * 
 * Nodes are labeled uniquely.
 * 
 * 
 * We use # as a separator for each node, and , as a separator for node label
 * and each neighbor of the node.
 * 
 * 
 * 
 * 
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 * 
 * 
 * 
 * The graph has a total of three nodes, and therefore contains three parts as
 * separated by #.
 * 
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming
 * a self-cycle.
 * 
 * 
 * 
 * 
 * Visually, the graph looks like the following:
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    /   \
 * ⁠   0 --- 2
 * ⁠        / \
 * ⁠        \_/
 * 
 * 
 * 
 * 
 */
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    // try dfs
    vector<UndirectedGraphNode *> nodes;
    UndirectedGraphNode *root;
    void cloneGraph(UndirectedGraphNode *parent, UndirectedGraphNode* node) {
        UndirectedGraphNode *tmp = new UndirectedGraphNode(node->label);
        nodes.push_back(tmp);
        parent->neighbors.push_back(tmp);
        
        for (int i = 0; i < node->neighbors.size(); i++) {
            bool finded = false;
            for (int j = 0; j < nodes.size(); j++) {
                if (nodes[j]->label == node->neighbors[i]->label) {
                    tmp->neighbors.push_back(nodes[j]);
                    finded = true;
                    break;
                }
            }
            if (!finded) {
                cloneGraph(tmp, node->neighbors[i]);   
            }
        }

    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        root = new UndirectedGraphNode(node->label);
        nodes.push_back(root);
        for (int i = 0; i < node->neighbors.size(); i++) {
            bool finded = false;
            for (int j = 0; j < nodes.size(); j++) {
                if (nodes[j]->label == node->neighbors[i]->label) {
                    root->neighbors.push_back(nodes[j]);
                    finded = true;
                    break;
                }
            }
            if (!finded) {
                cloneGraph(root, node->neighbors[i]);   
            }
        }
        return root;
    }
};
