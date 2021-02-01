public class ATMCard {
    private float balance;
    private String cardNumber;
    private Name name;

    public ATMCard() {}

    public ATMCard(String card, Name name, float balance) {
        cardNumber = card;
        this.name = name;
        this.balance = balance;
    }

    public float checkBalance() {
        return balance;
    }

    public float depositMoney(float amount) {
        return balance += amount;
    }

    boolean withdrawMoney(float amount) {
        if (amount > balance) { return false; }
        balance -= amount;
        return true;
    }

    public float interest(float rate) {
        this.balance = this.balance + ((rate / 100) * this.balance);
        return this.balance;
    }

    // toString()
    public String toString() {
        return name.toString() + "\nEnter Account Number: " + cardNumber + "\nEnter beginning balance: " + balance + "\n";
    }

    // GETTERS
    public float getBalance() {
        return balance;
    }

    public String getCardNumber() {
        return cardNumber;
    }

    public Name getName() {
        return name;
    }
    
    // SETTERS
    public void setBalance(float balance) {
        this.balance = balance;
    }

    public void setCardNumber(String card) {
        cardNumber = card;
    }

    public void setName(Name name) {
        this.name = name;
    }

}
