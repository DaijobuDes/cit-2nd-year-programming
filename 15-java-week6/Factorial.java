import java.util.*;

public class Factorial {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = 0;
        try {
            t = sc.nextInt();

            if (t < 0) {
                System.out.println("Invalid Input");
            }
            else {
                int out = 1;
                for (int i = 1; i <= t; i++)
                    out *= i;
                System.out.println(out);
            }

        } catch (Exception e) {
            System.out.println("InputMismatchException");
        }
        sc.close();
    }    
}