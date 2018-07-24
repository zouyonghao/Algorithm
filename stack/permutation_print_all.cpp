#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int counts = 0;
// 输出所有栈混洗
void enumeratePermutationsAux(int rangeMax, int &pushCount, int &popCount) {
    static std::stack<int> st;
    static std::vector<int> output(rangeMax, 0);
    if (pushCount == rangeMax && popCount == rangeMax) {
        for (int i = 0; i < rangeMax; ++i)
            std::cout << output[i] << ' ';
        std::cout << "\n";
        counts ++;
    } else {
        if (pushCount < rangeMax) {
            st.push(pushCount + 1);
            pushCount++;
            enumeratePermutationsAux(rangeMax, pushCount, popCount);
            st.pop();
            pushCount--;
        }
        if (pushCount > popCount) {
        // if (popCount < rangeMax) {
            int tmp = st.top();
            output[popCount] = tmp;
            st.pop();
            popCount++;
            enumeratePermutationsAux(rangeMax, pushCount, popCount);
            st.push(tmp);
            popCount--;
        }
    }
}
void enumeratePermutations(int rangeMax) {
    int pushCount = 0, popCount = 0;
    enumeratePermutationsAux(rangeMax, pushCount, popCount);
}

int main() {
    int n = 4;
    enumeratePermutations(n);
    cout << counts << endl;
}