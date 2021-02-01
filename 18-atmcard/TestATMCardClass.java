// import java.io.*;
import java.util.Scanner;

public class TestATMCardClass {

    static void displayMenu() {
        System.out.println("DEBIT CARD TRANSACTION");
        System.out.println("[1] Deposit Cash");
        System.out.println("[2] Withdraw Cash");
        System.out.println("[3] Inquire Balance");
        System.out.println("[4] Calculate Interest Rate");
        System.out.println("[5] Exit");
        System.out.print("\nYour choice: ");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ATMCard atmcard = new ATMCard();
        float amount = 0;
        int c = 0;

        Name person = new Name("Juan", "dela", "Cruz");
        atmcard.setName(person);
        atmcard.setCardNumber("A101-1125");
        atmcard.setBalance((float)1000.00);

        System.out.println(atmcard);

        while (c != 5) {
            displayMenu();
            c = sc.nextInt();

            switch (c) {
                case 1:
                    System.out.print("Enter amount: ");
                    amount = sc.nextFloat();
                    atmcard.depositMoney(amount);
                    System.out.println(atmcard);
                    break;
                case 2:
                    System.out.print("Enter amount: ");
                    amount = sc.nextFloat();
                    if (!atmcard.withdrawMoney(amount))
                        System.out.println("\nINSUFFICIENT FUNDS\n");
                    else
                        // atmcard.withdrawMoney(amount);
                        System.out.println(atmcard);
                    break;
                case 3:
                    System.out.println("\n" + atmcard);
                    break;
                case 4:
                    System.out.print("\nEnter rate: ");
                    amount = sc.nextFloat();
                    System.out.println("\nNew Balance: " + atmcard.interest(amount));
                    break;
                case 5:
                    System.out.println("\nPRESS ANY KEY TO CONTINUE…");
                    break;
                default:
                    break;
            }
        }
        sc.close();
    }
}