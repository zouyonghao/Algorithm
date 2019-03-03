import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<String> readBinaryWatch(int num) {
        List<String> results = new LinkedList<String>();
        for (int i = 0; i <= num; i++) {
            results.addAll(readBinaryWatch(i, num - i));
        }
        return results;
    }

    int testbits(int i) {
        int count = 0;
        while (i > 0) {
            if (1 == (i & 1)) {
                count++;
            }
            i >>= 1;
        }
        return count;
    }

    public List<String> readBinaryWatch(int hours, int minutes) {
        List<String> results = new LinkedList<>();
        for (int i = 0; i < 12; i++) { // hours
            if (testbits(i) != hours)
                continue;
            for (int j = 0; j < 60; j++) {
                if (testbits(j) != minutes)
                    continue;
                StringBuilder result = new StringBuilder().append(String.valueOf(i)).append(":");
                if (j < 10) {
                    result.append("0");
                }
                result.append(String.valueOf(j));
                results.add(result.toString());
            }
        }
        return results;
    }

    // public static void main(String[] args) {
    //     Solution s = new Solution();
    //     for (String ss : s.readBinaryWatch(1)) {
    //         System.out.println(ss);
    //     }
    //     // System.out.println("hello");
    // }
}
