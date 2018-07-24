struct Queen { //皇后类
   int x, y; //皇后在棋盘上的位置坐标
   Queen ( int xx = 0, int yy = 0 ) : x ( xx ), y ( yy ) {};
   bool operator== ( Queen const& q ) const { //重载判等操作符，以检测不同皇后之间可能的冲突
      return    ( x == q.x ) //行冲突（这一情况其实并不会发生，可省略）
                || ( y == q.y ) //列冲突
                || ( x + y == q.x + q.y ) //沿正对角线冲突
                || ( x - y == q.x - q.y ); //沿反对角线冲突
   }
   bool operator!= ( Queen const& q ) const { return ! ( *this == q ); } //重载不等操作符 /*DSA*/可否写成：return *this != q？
};
void placeQueens ( int N ) { //N皇后算法（迭代版）：采用试探/回溯的策略，借助栈记录查找的结果
   Stack<Queen> solu; //存放（部分）解的栈
   Queen q ( 0, 0 ); //从原点位置出发
   do { //反复试探、回溯
      if ( N <= solu.size() || N <= q.y ) { //若已出界，则
         q = solu.pop(); q.y++; //回溯一行，并继续试探下一列
      } else { //否则，试探下一行
         while ( ( q.y < N ) && ( 0 <= solu.find ( q ) ) ) //通过与已有皇后的比对
            /*DSA*///while ((q.y < N) && (solu.find(q))) //（若基于List实现Stack，则find()返回值的语义有所不同）
            { q.y++; nCheck++; } //尝试找到可摆放下一皇后的列
         if ( N > q.y ) { //若存在可摆放的列，则
            solu.push ( q ); //摆上当前皇后，并
            if ( N <= solu.size() ) nSolu++; //若部分解已成为全局解，则通过全局变量nSolu计数
            q.x++; q.y = 0; //转入下一行，从第0列开始，试探下一皇后
         }
      }/*DSA*/if ( Step == runMode ) displayProgress ( solu, N );
   } while ( ( 0 < q.x ) || ( q.y < N ) ); //所有分支均已或穷举或剪枝之后，算法结束
}