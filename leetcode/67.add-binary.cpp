/*
 * [67] Add Binary
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (41.15%)
 * Total Accepted:    4.4K
 * Total Submissions: 10.7K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1, j = b.length() - 1;
        int proceed = 0;
        while (i >= 0 && j >= 0) {
            int tmp = a[i] + b[j] - '0' - '0' + proceed;
            cout << tmp << endl;
            proceed = tmp / 2;
            result += char(tmp % 2 + '0');
            i--;
            j--;
        }
        while(i >= 0) {
            int tmp = a[i] - '0' + proceed;
            proceed = tmp / 2;
            result += char(tmp % 2 + '0');
            i--;
        }
        while(j >= 0) {
            int tmp = b[j] - '0' + proceed;
            proceed = tmp / 2;
            result += char(tmp % 2 + '0');
            j--;
        }
        while (proceed > 0) {
            result += char(proceed % 2 + '0');
            proceed /= 2;
        }
        for (int k = 0; k < result.length() / 2; k++) {
            swap(result[k], result[result.length() - k - 1]);
        }
        return result;
    }
};
