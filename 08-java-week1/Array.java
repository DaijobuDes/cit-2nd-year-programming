import java.util.*;

public class Array {
	public static void main(String arg[]) {

		Scanner sc = new Scanner(System.in);

		int size = 10;
		double[] arr = new double[size];
		double addOn = 200;
		int counter = 0;

		for (int i = 0; i < size; i++) {
			System.out.printf("Enter employee's %d gross sales: ", i + 1);
			arr[i] = sc.nextDouble();
			if (arr[i] * 0.09 + addOn > 500)
				counter++;
		}
		System.out.println("There are " + counter + " employees who earned more than Php500");
		sc.close();
	}

}
