public class CheckingAccount extends BankAccount
{
    private double minimum;
    private double charge;
    
    public CheckingAccount()
    {
        super();
        minimum = 0;
        charge = 0;
    }

    public CheckingAccount(String acctNum, String acctName, double balance, double minimum, double charge)
    {
        super(acctNum, acctName, balance);
        this.minimum = minimum;
        this.charge = charge;
    }

    public void cashCheck(String payee, double amount)
    {
        if(amount > balance)
            return;
        
        balance -= amount;

        if(balance < minimum)
            balance -= charge;
    }

    public String toString()
    {
        return String.format("%s, %.1f, %.1f", super.toString(), minimum, charge);
    }

    public void setMinimum(double minimum)
    {
        this.minimum = minimum;
    }

    public void setCharge(double charge)
    {
        this.charge = charge;
    }

    public double getMinimum()
    {
        return minimum;
    }

    public double getCharge()
    {
        return charge;
    }
}