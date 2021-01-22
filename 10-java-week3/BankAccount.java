import java.util.*;

public class BankAccount
{
    protected String accountNumber;
    protected String accountName;
    protected double balance;

    public BankAccount()
    {
        accountNumber = "0";
        accountName = "John Doe";
        balance = 0;
    }

    public BankAccount(String acctNum, String acctName, double balance)
    {
        accountNumber = acctNum;
        accountName = acctName;
        this.balance = balance;
    }

    public void deposit(double amount)
    {
        if(amount >= 0)
            balance += amount;
    }

    public boolean withdraw(double amount)
    {
        if(amount > balance)
            return false;
        
        balance -= amount;

        return true;
    }

    public void fundTransfer(BankAccount obj, double amount)
    {
        if(amount > balance)
            return;
        
        obj.deposit(amount);
        balance -= amount;
    }

    public String toString()
    {
        return String.format("%s, %s, %.1f", accountNumber, accountName, balance);
    }

    public void setAccountName(String acctName)
    {
        Scanner sc = new Scanner(acctName);

        int word = 0;
        accountName = "";
        do {
            accountName += (" " + sc.next());
            word++;
        } while(sc.hasNext());
        
        // Remove trailing spaces
        accountName = accountName.trim();

        if(word < 2)
        accountName = "John Doe";

        sc.close(); 
    }

    public void setAccountNumber(String accountNum)
    {
        accountNumber = accountNum;
    }

    public void setBalance(double amount)
    {
        balance = amount;
    }

    public String getAccountName()
    {
        return accountName;
    }

    public String getAccountNumber()
    {
        return accountNumber;
    }
    
    public double getBalance()
    {
        return balance;
    }
}