public class Name {
    private String firstname;
    private String middlename;
    private String lastname;
    
    private Mobile number;

    public Name() {}

    public Name(String firstname, String middlename, String lastname) {
        this.firstname = firstname;
        this.middlename = middlename;
        this.lastname = lastname;
    }

    public Name(String firstname, String middlename, String lastname, Mobile number) {
        this.firstname = firstname;
        this.middlename = middlename;
        this.lastname = lastname;
        this.number = number;
    }

    public String toString() {
        return "Enter name: <<" + firstname + " " + middlename + " " + lastname + ">>";
    }

    // GETTERS
    public String getFirstName() {
        return firstname;
    }

    public String getMiddleName() {
        return middlename;
    }

    public String getLastName() {
        return lastname;
    }

    // SETTERS
    public void setFirstName(String fname) {
        firstname = fname;
    }

    public void setMiddleName(String mname) {
        middlename = mname;
    }

    public void setLastName(String lname) {
        lastname = lname;
    }
}
