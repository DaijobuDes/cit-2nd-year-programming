public class MyPoint
{
	private int x;
	private int y;
	
	public MyPoint(){}

	public MyPoint(int x, int y) {
		this.x = x;
		this.y = y;
	}
	public String toString() {
		return "("+x+","+y+")";
	}

	public int get_X() {
		return x;
	}

	public int get_Y() {
		return y;
	}

}