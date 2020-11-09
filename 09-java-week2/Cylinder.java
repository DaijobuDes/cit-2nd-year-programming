public class Cylinder
{
	private Circle base;
	private float height;

	public Cylinder() {
		height = 0;
		base = new Circle();
	}

	public Cylinder(Circle base, float height) {
		this.base = base;
		this.height = height;
	}

	
	public boolean equals(Object obj) {
		if(!(obj instanceof Cylinder))
			return false;
			
		Cylinder cyl = (Cylinder)obj;
		
		if(
			cyl.getCircle().equals(getCircle()) && 
			cyl.getHeight() == this.getHeight()
		) {
			return true;
		}

		return false;
	}

	public void setCircle(Circle base) {
		this.base = base;
	}

	public void setCircle(int x, int y, float rad) {
		this.base = new Circle(x, y, rad);
	}

	public void setHeight(float height) {
		this.height = height;
	}

	public float getHeight() {
		return height;
	}

	public Circle getCircle() {
		return base;
	}

	public float getArea() {
		return (float)(Math.round((2 * base.getArea() + base.getCircumference() * height) * 100.0) / 100.0);
	}

	public float getVolume() {
		return (float)(Math.round((base.getArea() * height) * 100.0) / 100.0);
	}

	public String toString() {
		String str = String.format("%s\nHeight: %.2f", base.toString(), height);
		return str;
	}
}