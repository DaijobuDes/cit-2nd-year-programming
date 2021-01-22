public class Runner {
    public static void main(String[] args) {
        // Test case 1
        CommissionEmployee c = new CommissionEmployee ("Yule Josef Ato","Cebu City",23,"Accenture",40000.0f, 550, 0.10f);
        System.out.println(c);
        System.out.println("\nEarnings: "+c.earnings());

        // Test case 2
        CommissionEmployee c2 = new CommissionEmployee ("Yule Josef Ato","Cebu City",23,"Accenture",40000.0f, 550, 0.10f);
        CommissionEmployee c3 = new CommissionEmployee ("Yule Josef Ato","Cebu City",23,"Accenture",40000.0f, 550, 0.10f);
        c2.display();
        System.out.println(c2.equals(c3));

        // Test case 3 (Hidden)
        CommissionEmployee c4 = new CommissionEmployee();
        c4.setName("Yule Josef Ato");
        c4.setAddress("Cebu City");
        c4.setAge(28);
        c4.setCompanyName("Kyocera");
        c4.setRegularSalary(5000.00f);
        c4.setItemSold(40);
        c4.setCommissionRate(0.2f);
        System.out.println(c4);
    }
}
