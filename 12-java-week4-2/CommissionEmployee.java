class CommissionEmployee extends Employee {

	private float regularSalary;  //fixed monthly salary
	private int itemSold;	      //total number of items sold
	private float commission_rate;	//rate per item (in decimal form)

	public CommissionEmployee(String name,String address,
			int age,String cName, float regSal, int nItems,
			float commission) {
		super(name,address,age,cName);
		regularSalary = regSal;
		itemSold = nItems;
		commission_rate = commission;
	}

	public CommissionEmployee() {

	}

	// provide the setters and getters of your data members
    public void setRegularSalary(float salary)
    {
        regularSalary = salary;
    }

    public void setItemSold(int sold)
    {
        itemSold = sold;
    }

    public void setCommissionRate(float amount)
    {
        commission_rate = amount;
    }

    public float getRegularSalary()
    {
        return regularSalary;
    }

    public float getCommissionRate()
    {
        return commission_rate;
    }

    public int getItemSold()
    {
        return itemSold;
    }
	// implement the abstract method
	
		//the total earnings of a commission employee is the sum of
		//the monthly salary plus the commission.
		//commission will be based on the total number of items sold
		//times the commission rate per item.

    public double earnings()
    {
        return regularSalary + ((float)itemSold * commission_rate);
    }

	// override the toString() and equals() methods
    public String toString()
    {
        return super.toString() + "Regular salary: " + regularSalary + "\nItem sold: " + itemSold + "\nCommission rate: " + commission_rate;
    }

    public boolean equals(Object obj)
    {
        if(super.equals(obj))
            return true;

        CommissionEmployee c = (CommissionEmployee)obj;

        if( 
            itemSold == c.getItemSold() &&
            regularSalary == c.getRegularSalary() &&
            commission_rate == c.getCommissionRate()
            ) 
            return true;

        return false;
    }

}