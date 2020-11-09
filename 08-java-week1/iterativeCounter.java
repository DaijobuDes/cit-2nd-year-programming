import java.util.Scanner;

public class iterativeCounter {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        float totalGrade = 0, grade = 0;
        String str;

        for (int i = 0; i < 7; i++) {
            System.out.printf("Enter grade %d: ", i + 1);

            grade = sc.nextFloat();
            totalGrade += grade;
        }

        float avg = totalGrade / 7;

        if (avg >= 3)
            str = "Passed";
        else
            str = "Failed";

        System.out.printf("Average is %.1f and has %s", avg, str);

        sc.close();
    }
}
