import java.util.*;

public class tuitionFee {
  	public static void main(String[] args) {
		int unitPrice = 45;

		double misc = 0.15;
		int blanketPrice = 200;

		Scanner sc= new Scanner(System.in);

		System.out.print("Enter number of Units: ");
		int units = sc.nextInt();

		double tuition = (units * unitPrice) * (1 + misc) + blanketPrice;

		System.out.println("\nTotal Tuition Fee = " + tuition);
		sc.close();
  	}
}
