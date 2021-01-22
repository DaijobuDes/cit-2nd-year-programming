public class Account{
    private String accntNumber;
    private String accntName;
    private double balance;
    
    public Account() {}
    public Account(String num, String name, double bal) {
        accntNumber = num;
        accntName = name;
        balance = bal;
    }
    
    public double getBalance() { return balance; }

    public void withdraw(double amount) {
        try {
            if (amount > balance)
                throw new Exception("Insufficient funds.");
            balance -= amount;
        } catch (Exception e) {
            System.out.println("Insufficient: "+e.getMessage());
        }
    }
}