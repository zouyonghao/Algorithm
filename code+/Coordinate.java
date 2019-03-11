import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int m = s.nextInt();
        s.nextLine();
        while (s.hasNext()) {
            String query = s.nextLine();
            int num = Integer.parseInt(query.substring(2));
            int length = (int) (Math.pow(2, n));
            if (query.charAt(0) == 'Z') {
                int x = 0, y = 0;
                while (num > 0) {
                    length /= 2;
                    int r = num / (length * length);
                    switch (r) {
                    case 0:
                        break;
                    case 1: {
                        y += length;
                        break;
                    }
                    case 2: {
                        x += length;
                        break;
                    }
                    case 3: {
                        x += length;
                        y += length;
                        break;
                    }
                    }
                    num = num % (length * length);
                }

                length = (int) (Math.pow(2, n));
                System.out.println(x * length + y);
            } else {
                int x = num / length;
                int y = num % length;
                int result = 0;
                int temp = length / 2;
                while (temp > 0) {
                    if (x >= temp && y >= temp) {
                        result += 3 * temp * temp;
                        x -= temp;
                        y -= temp;
                    } else if (x < temp && y >= temp) {
                        result += temp * temp;
                        y -= temp;
                    } else if (x >= temp && y < temp) {
                        result += 2 * temp * temp;
                        x -= temp;
                    }
                    temp /= 2;
                }
                System.out.println(result);
            }
        }
    }
}