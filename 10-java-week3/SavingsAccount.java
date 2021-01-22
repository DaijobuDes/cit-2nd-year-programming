public class SavingsAccount extends BankAccount
{
    private double interestRate;

    public SavingsAccount()
    {
        super();
        interestRate = 0;
    }

    public SavingsAccount(String acctNum, String acctName, double balance, double interest)
    {
        accountNumber = acctNum;
        accountName = "John Doe";
        String name[] = acctName.split(" ");

        if(name.length >= 2)
            accountName = String.join(" ", name);
        
        this.balance = balance;
        interestRate = interest;
    }
    
    public void calculateInterest()
    {
        balance *= (interestRate + 1);
    }

    public String toString()
    {
        return super.toString() + ", " + interestRate;
    }

    public void setInterestRate(double interest)
    {
        interestRate = interest;
    }

    public double getInterestRate()
    {
        return interestRate;
    }
}
