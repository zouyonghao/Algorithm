// https://leetcode-cn.com/problems/n-queens-ii/description/

class Solution {
  public:
    int count;
    int *q;
    int totalNQueens(int n) {
        q = new int[n + 2];
        place(1, n);
        delete q;
        return count;
    }
    //检验第i行的k列上是否可以摆放皇后
    int find(int i, int k) {
        int j = 1;
        while (j < i) // j=1~i-1是已经放置了皇后的行
        {
            //第j行的皇后是否在k列或(j,q[j])与(i,k)是否在斜线上
            if (q[j] == k || abs(j - i) == abs(q[j] - k))
                return 0;
            j++;
        }
        return 1;
    }
    //放置皇后到棋盘上
    void place(int k, int n) {
        int j;
        if (k > n)
            count++;
        else {
            for (j = 1; j <= n; j++) //试探第k行的每一个列
            {
                if (find(k, j)) {
                    q[k] = j;
                    place(
                        k + 1,
                        n); //递归总是在成功完成了上次的任务的时候才做下一个任务
                }
            }
        }
    }
};