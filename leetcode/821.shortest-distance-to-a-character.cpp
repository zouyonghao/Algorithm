/*
 * [841] Shortest Distance to a Character
 *
 * https://leetcode.com/problems/shortest-distance-to-a-character/description/
 *
 * algorithms
 * Easy (60.80%)
 * Total Accepted:    14.7K
 * Total Submissions: 24.1K
 * Testcase Example:  '"loveleetcode"\n"e"'
 *
 * Given a string S and a character C, return an array of integers representing
 * the shortest distance from the character C in the string.
 * 
 * Example 1:
 * 
 * 
 * Input: S = "loveleetcode", C = 'e'
 * Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S string length is in [1, 10000].
 * C is a single character, and guaranteed to be in string S.
 * All letters in S and C are lowercase.
 * 
 * 
 */

#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> order;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == C) {
                order.push_back(i);
            }
        }
        vector<int> result;
        for (int i = 0; i < S.length(); i++) {
            int length = -1;
            for (int j = 0; j < order.size(); j++) {
                if (i <= order[j]) {
                    if (j > 0) {
                        length = min(i - order[j - 1], order[j] - i);
                    } else {
                        length = order[j] - i;
                    }
                    break;
                }
            }
            if (length > -1)
                result.push_back(length);
            else
                result.push_back(i - order[order.size() - 1]);
        }
        return result;
    }
};
