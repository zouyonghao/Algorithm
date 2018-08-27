/*
 * [171] Excel Sheet Column Number
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (59.56%)
 * Total Accepted:    3.1K
 * Total Submissions: 5.2K
 * Testcase Example:  '"A"'
 *
 * 给定一个Excel表格中的列名称，返回其相应的列序号。
 * 
 * 例如，
 * 
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: "A"
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: "AB"
 * 输出: 28
 * 
 * 
 * 示例 3:
 * 
 * 输入: "ZY"
 * 输出: 701
 * 
 * 致谢：
 * 特别感谢 @ts 添加此问题并创建所有测试用例。
 * 
 */
class Solution {
public:
    int titleToNumber(string s) {
        map<char, int> m;
        for(int i = 0; i < 26 ; i ++) {
            m['A' + i] = i + 1;
        }
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            result *= 26;
            result += m[s[i]];
        }
        return result;
    }
};
