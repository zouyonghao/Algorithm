/*
 * [168] Excel Sheet Column Title
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (26.95%)
 * Total Accepted:    1.6K
 * Total Submissions: 6.1K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 * 
 * 例如，
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "A"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 28
 * 输出: "AB"
 * 
 * 
 * 示例 3:
 * 
 * 输入: 701
 * 输出: "ZY"
 * 
 * 
 */
class Solution {
public:
    string convertToTitle(int n) {
        string s;
        map<int, char> m;
        for(int i = 0; i < 26 ; i ++) {
            m[i] = 'A'+i;
        }
        while(1) {
            s.insert(s.begin(), m[(n - 1) % 26]);
            if(n == 26) return s;
            if(n % 26 == 0) n--;
            n = n / 26;
            if(n == 0) return s;
        }
    }
};

