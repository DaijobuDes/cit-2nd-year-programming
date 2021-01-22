

class HourlyEmployee extends Employee
{
	private int hoursWorked;  //total number of hours worked
	private double rate;	  // rate per hour

	public HourlyEmployee()
	{

	}

	public HourlyEmployee(String name,String address,int age,String cName,int hoursWorked,double rate)
	{
		super(name,address,age,cName);
		this.hoursWorked = hoursWorked;
		this.rate = rate;
	}

	public HourlyEmployee(String name,String address,int age,String cName)
	{
		super(name,address,age,cName);
		hoursWorked = 0;
		rate = 0;

	}

	// provide the setters and getters of your data members

	//SETTERS
	public void setHoursWorked(int hw)
	{
		hoursWorked = hw;
	}

	public void setRate(double r)
	{
		rate = r;
	}

	//GETTERS
	public int getHoursWorked()
	{
		return hoursWorked;
	}

	public double getRate()
	{
		return rate;
	}

	// implement the abstract method
	public double earnings()
	{
		double base = (Math.min(hoursWorked, 40) * rate);
		double extra = (Math.max(hoursWorked - 40, 0) * (rate * 1.5));
		return  base + extra;
	}
		//earnings is computed by having the product of
		//the total number of hours worked and the rate.
		// but if the number of hours worked exceeds 40,
		// the rate increases to 150% of the current rate.
		// (ex. rate=200; 150% = 300)


	// override the toString() and equals() methods

	public String toString()
	{
		return super.toString() + "\nHours worked: " + hoursWorked + "\n" +
			"Rate: " + rate; 
	}

	public boolean equals(Object o)
	{
		if(o == this)
			return true;
		
		if(!(o instanceof HourlyEmployee))
			return false;
		HourlyEmployee h = (HourlyEmployee) o;
		if(	h.getName().equals(getName()) &&
			h.getAddress().equals(getAddress()) &&
			h.getAge() == getAge() &&
			h.getCompanyName().equals(getCompanyName()) &&
			h.getHoursWorked() == hoursWorked &&
			h.getRate() == rate)
			return true;
		
		return false;
	}
}
