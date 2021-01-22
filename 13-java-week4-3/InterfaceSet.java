interface InterfaceSet
{
    public static final int MAX = 10;
    public void add(int e);
    public void display(); 
    public int count(); 
    public boolean isElementOf(int e); 
    public int getElement(int index); 
    public Set union(Set s);
}