public class Runner {
    public static void main(String[] args) {
        /*
        // Test case 1 for BankAccount
        BankAccount  account1 = new BankAccount ("Acct-001","Maria Paz", 5000);
        BankAccount  account2 = new BankAccount ("Acct-002","Juan dela Cruz", 2000);
        System.out.println(account1);
        System.out.println(account2);
        account1.deposit(200);
        System.out.println(account1.withdraw(7000));
        account1.fundTransfer(account2, 2000);
        System.out.println(account1);
        System.out.println(account2);
        
        System.out.println();
        
        // Test case 2 for BankAccount
        BankAccount account3 = new BankAccount ();
        account1.setAccountName("YuleTulin");
        account1.setAccountNumber("Acct-001");
        account1.setBalance(1000);
        account1.deposit(-500);
        System.out.println(account3.getAccountNumber());
        System.out.println(account3.getAccountName());
        System.out.println(account3.getBalance());

        System.out.println();        
        */
        /*
        // Test case 1 for SavingsAccount
        SavingsAccount sa = new SavingsAccount("Acct-001", "Maria Paz", 5000.0, 0.2);
        System.out.println(sa);
        sa.deposit(200);
        sa.calculateInterest();
        System.out.println(sa);
        SavingsAccount sa2 = new SavingsAccount("Acct-002", "JuneMarch", 5000.0, 0.25);
        System.out.println(sa2);

        System.out.println();

        // Test case 2 for SavingsAccount
        SavingsAccount sa3 = new SavingsAccount("Acct-001", "Juan dela Cruz", 2000.0, 0.0);
        System.out.println(sa3.toString());
        sa3.deposit(200);
        sa3.setInterestRate(0.25);
        sa3.calculateInterest();
        System.out.println(sa3.getInterestRate());
        System.out.println(sa3);
        */
        // Test case 1 for CheckingAccount
        CheckingAccount ca = new CheckingAccount("Acct-001","Maria Paz",5000, 2000, 500);
        System.out.println(ca);
        ca.cashCheck("CIT",3500);
        System.out.println(ca);

        System.out.println();

        // Test case 2 for CheckingAccount
        CheckingAccount ca2 = new CheckingAccount("Acct-001","Maria Paz",5000, 2000, 500);
        System.out.println(ca2);
        ca2.cashCheck("CIT",7000);
        System.out.println(ca2);

        System.out.println();

        // Test case 3 for CheckingAccount
        CheckingAccount ca3 = new CheckingAccount("Acct-001","Maria Paz",5000, 2000, 500);
        System.out.println(ca3);
        ca3.cashCheck("CIT",5000);
        System.out.println(ca3);

        System.out.println();

        // Test case 4 for CheckingAccount
        CheckingAccount ca4 = new CheckingAccount();
        ca4.setAccountNumber("Acct-001");
        ca4.setAccountName("Maria Paz");
        ca4.setBalance(5000);
        ca4.setMinimum(2000);
        ca4.setCharge(500);
        System.out.println(ca4.getMinimum());
        System.out.println(ca4.getCharge());
        System.out.println(ca4.toString());
        */





    }
}
