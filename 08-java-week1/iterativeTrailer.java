import java.util.Scanner;

public class iterativeTrailer {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        int team1 = 0, team2 = 0, input = 1;
        String sequence = "";
        String won = "";

        while (input != 0) {
            System.out.print("Enter input (1~2, 0 to exit): ");
            input = sc.nextInt();
               
            if (input == 1) {
                team1++;
                sequence += String.valueOf(input) + " ";
            }
            else if (input == 2) {
                team2++;
                sequence += String.valueOf(input) + " ";
            }
            else if (input == 0) {
                sequence += String.valueOf(input) + " ";
                System.out.printf("Sequence: %s\n", sequence);
                System.out.printf("Team 1: %d\nTeam 2: %d\n", team1, team2);
                if (team1 > team2)
                    won = "Team 1 won";
                else if (team2 > team1)
                    won = "Team 2 won";
                else if (team1 == team2)
                    won = "Both tied";
                System.out.printf("%s", won);
            }
            else
                System.out.println("Not a valid number.");
        }
        sc.close();
    }
}
