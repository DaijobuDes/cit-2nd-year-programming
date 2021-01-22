public class Runner1 {
    public static void main(String[] args) {
        // Test 1
        Account account = new Account("Acct-001","Juan dela Cruz", 5000.0);
        account.withdraw(5500.0);
        System.out.println("Balance: "+account.getBalance());

        // Test 2
        Account account2 = new Account("Acct-001","Juan dela Cruz", 5000.0);
        account2.withdraw(500.0);
        System.out.println("Balance: "+account2.getBalance());
    }
}
