public class Runner {
    public static void main(String[] args) {

        // Test case 1 Circle.java
        Circle c = new Circle();
        System.out.println(c);
        c.setRadius(25);
        c.setCenter(4,5);
        System.out.println(c);

        System.out.print("\n");
        
        // Test case 2 Circle.java
        Circle d  = new Circle(new MyPoint(1,2),4.5f);
        System.out.println(d);

        System.out.print("\n");

        // Test case 3 Circle.java
        Circle e = new Circle (10,20,11.5f);
        System.out.println(e);

        System.out.print("\n");

        // Test case 4 Circle.java
        Circle f = new Circle(10,20,5);
        System.out.printf("Area: %.2f\n",f.getArea());
        System.out.printf("Circumference: %.2f",f.getCircumference());

        // Test case 1 Cylinder.java
        Cylinder g = new Cylinder();
        g.setCircle(10,20,4.5f);
        g.setHeight(10);
        System.out.printf("Radius: %.2f\n",g.getCircle().getRadius());
        System.out.println("Point: "+g.getCircle().getCenter());
        System.out.printf("Height: %.2f\n",g.getHeight());

        System.out.print("\n");

        // Test case 2 Cylinder.java
        Cylinder h = new Cylinder(new Circle(5,5,10.5f),25);
        System.out.println(h);
        System.out.println("Area: "+h.getArea());
        System.out.println("Volume: "+h.getVolume());

        System.out.print("\n");

        // Test case 3 Cylinder.java (Hidden)
        Cylinder c1 = new Cylinder(new Circle(5,5,5),10);
        Cylinder c2 = new Cylinder(new Circle(5,5,5),10);
        Circle circle = new Circle(5,5,5);
        System.out.println(c1.equals(c2));
        System.out.println(c1.equals(circle));

    }
}
