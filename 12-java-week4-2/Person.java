public class Person {
    private String name;
    private String address;
    private int age;

    public Person(String name,String address,int age) {
       this.name = name;
       this.address = address;
       this.age = age;
    }

	public Person() {
	}

	public void setName(String name){
		this.name = name;
	}

	public void setAddress(String address){
			this.address = address;
	}

	public void setAge(int age){
			this.age = age;
	}

    public String getName() {
       return name;
    }

    public String getAddress() {
       return address;
    }

    public int getAge() {
       return age;
    }

    public void display() {
        System.out.println("Name      : "+name);
        System.out.println("Address   : "+address);
        System.out.println("Age       : "+age);
    }

    public void eat(String food) {
       System.out.println(name+" is eating "+food);
    }

	public String toString(){
		return "Name: " + name + "\nAddress: " + address +"\nAge: " + age + "\n";
	}

	public boolean equals(Object obj){
		if(obj instanceof Person){
			if (this.age == ((Person)obj).age && ((Person)obj).name.equals(this.name) && ((Person)obj).address.equals(this.address) ){
				return true;
			}
		}
		return false;
	}
}