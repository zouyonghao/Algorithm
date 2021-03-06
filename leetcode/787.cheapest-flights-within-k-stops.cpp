/*
 * [803] Cheapest Flights Within K Stops
 *
 * https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
 *
 * algorithms
 * Medium (29.96%)
 * Total Accepted:    10.1K
 * Total Submissions: 33.8K
 * Testcase Example:  '3\n[[0,1,100],[1,2,100],[0,2,500]]\n0\n2\n1'
 *
 * There are n cities connected by m flights. Each fight starts from city u and
 * arrives at v with a price w.
 * 
 * Now given all the cities and fights, together with starting city src and the
 * destination dst, your task is to find the cheapest price from src to dst
 * with up to k stops. If there is no such route, output -1.
 * 
 * 
 * Example 1:
 * Input: 
 * n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
 * src = 0, dst = 2, k = 1
 * Output: 200
 * Explanation: 
 * The graph looks like this:
 * 
 * 
 * The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as
 * marked red in the picture.
 * 
 * 
 * Example 2:
 * Input: 
 * n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
 * src = 0, dst = 2, k = 0
 * Output: 500
 * Explanation: 
 * The graph looks like this:
 * 
 * 
 * The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as
 * marked blue in the picture.
 * 
 * Note:
 * 
 * 
 * The number of nodes n will be in range [1, 100], with nodes labeled from 0
 * to n - 1.
 * The size of flights will be in range [0, n * (n - 1) / 2].
 * The format of each flight will be (src, dst, price).
 * The price of each flight will be in the range [1, 10000].
 * k is in the range of [0, n - 1].
 * There will not be any duplicated flights or self cycles.
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int* ds = new int[n];
        for (int i = 0; i < n; i++) {
            ds[i] = INT_MAX;
        }
        ds[src] = 0;
        int ans = INT_MAX;
        for (int k = 0; k <= K; k++) {
            int* nds = new int[n];
            for (int i = 0; i < n; i++) {
                nds[i] = INT_MAX;
            }
            for (int i = 0; i < flights.size(); i++) {
                int x = flights[i][0];
                int y = flights[i][1];
                int w = flights[i][2];
                nds[y] = min(nds[y], ds[x] == INT_MAX ? INT_MAX : ds[x] + w);
            }
            ds = nds;
            ans = min(ans, ds[dst]);
        }
        return ans != INT_MAX ? ans : -1;
    }
};
