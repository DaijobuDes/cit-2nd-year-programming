public class Runner {
    public static void main(String[] args) {
        // Case 1
        HourlyEmployee h1 = new HourlyEmployee("Yule Josef Ato","Cebu City",23,"Accenture",40, 550.98);
        System.out.println(h1);
        System.out.println("\nEarnings: "+h1.earnings());

        // Case 2
        HourlyEmployee h2 = new HourlyEmployee("Linc Josef Ato","Talisay City",28,"Alliance",41, 600.00);
        h2.display();
        System.out.println("\nEarnings: "+h2.earnings());

        // Case 3
        HourlyEmployee h3 = new HourlyEmployee("Yule Josef Ato","Cebu City",23,"Accenture",40, 550.98);
        HourlyEmployee h4 = new HourlyEmployee("Linc Josef Ato","Talisay City",28,"Alliance",41, 600.00);
        System.out.println(h3.equals(h4));

        // Case 4
        HourlyEmployee h5 = new HourlyEmployee();
        h5.setName("Yule Josef Ato");
        h5.setAddress("Cebu City");
        h5.setAge(28);
        h5.setCompanyName("Kyocera");
        h5.setRate(600.00);
        h5.setHoursWorked(40);
        System.out.println(h5);

    }
}
