public class Circle
{
	private float radius;
	private MyPoint center;

	public Circle() {
		radius = 0;
		center = new MyPoint(0, 0);
	}

	public Circle(MyPoint center, float radius) {
		this.radius = radius;
		this.center = center;
	}

	public Circle(int x, int y, float radius) {
		this.radius = radius;
		this.center = new MyPoint(x, y);
	}

	public String toString() {
		String str = String.format("Radius: %.2f\nPoint: %s", radius, center);
		return str;
	}

	public void setRadius(float radius) {
		this.radius = radius;
	}

	public boolean equals(Object obj) {
		Circle circle = (Circle)obj;

		if(obj == this || obj instanceof Circle)
			return true;

		if(
			circle.getRadius() == getRadius() &&
			circle.getCenter().get_X() == center.get_X() &&
			circle.getCenter().get_Y() == center.get_Y()
		) {
			return true;
		}

		return false; 
	}

	public void setCenter(int x, int y) {
		this.center = new MyPoint(x, y);
	}

	public float getArea() {
		return (float)Math.PI * (float)Math.pow(radius, 2);
	}

	public float getRadius() {
		return radius;
	}

	public MyPoint getCenter() {
		return center;
	}

	public float getCircumference() {
		return (float)Math.PI * (radius * 2);
	}
}


















