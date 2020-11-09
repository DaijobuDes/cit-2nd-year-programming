import java.util.*;

public class switchCase {
		public static void main(String[] args) {
			  Scanner sc = new Scanner(System.in);
			  System.out.print("Enter Product Type: ");
			  int productType = sc.nextInt();
			  System.out.print("Enter Total Sales: ");
			  double totalSales = sc.nextDouble();
			  double commission = 0;

			switch(productType) {
				case 1:	if (totalSales * .07 > 400)
				  			commission = totalSales * 0.07;
				  		else
				  		  	commission = 400;
				  		break;
				case 2:	if (totalSales * .1 < 900)
							commission = totalSales * 0.07;
						else
							commission = 900;
				  		break;
				case 3: commission = totalSales * 0.12;
						break;
				case 4:	commission = 250;
						break;
				default:
						System.out.println("Invalid input");
			}
		System.out.println("\nTotal commission: " + commission);
		sc.close();
		}
}
