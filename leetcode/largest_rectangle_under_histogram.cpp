#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> s;
        int maxArea = 0;
        int i = 0;
        while (i < heights.size()) {
            if (s.empty() || heights[s.top()] <= heights[i])
                s.push(i++);
            else {
                int tp = s.top();
                s.pop();
                int area = heights[tp] * (s.empty() ? i : i - s.top() - 1);
                if (maxArea < area)
                    maxArea = area;
            }
        }
        while (!s.empty()) {
            int tp = s.top();
            s.pop();
            int area = heights[tp] * (s.empty() ? i : i - s.top() - 1);
            if (maxArea < area)
                maxArea = area;
        }
        return maxArea;
    }
};