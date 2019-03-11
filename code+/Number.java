import java.io.BufferedInputStream;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner (new BufferedInputStream(System.in));
        int n = s.nextInt();
        boolean haveFunNumber = false;
        for (int i = 10; i <= n; i++) {
            if (fun(i)) {
                System.out.println(i);
                haveFunNumber = true;
            }
        }
        if (!haveFunNumber) {
            System.out.print(-1);
        }
        s.close();

    }

    private static boolean fun(int i) {
        while (i > 0) {
            if (i % 10 < i / 10) {
                break;
            }
            i /= 10;
        }
        return i <= 0;
    }
}