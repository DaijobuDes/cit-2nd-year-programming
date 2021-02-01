public class Mobile {
    private String mobilenumber;

    public Mobile() {}

    public Mobile(String mobilenumber) {
        this.mobilenumber = mobilenumber;
    }

    // toString()
    public String toString() {
        return "Enter account number: " + mobilenumber;
    }

    // GETTERS
    public String getMobileNumber() {
        return mobilenumber;
    }

    // SETTERS
    public void setMobileNumber(String mobilenumber) {
        this.mobilenumber = mobilenumber;
    }

}
