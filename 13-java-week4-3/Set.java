public class Set implements InterfaceSet
{
    private int[] arr;
    private int count;

    public Set()
    {
        arr = new int[MAX];
        count = 0;
    }

    public Set(int size)
    {
        arr = new int[size];
        count = 0;
    }

    public void add(int e)
    {
        if(count == arr.length) 
            return;

        int flag = 0;

        for(int i : arr) 
            if(i == e) 
                flag = 1;

        if(flag == 0) 
        {
            arr[count] = e;
            count++;
        }
    }

    public void display( )
    {
        for(int i = 0 ; i < count; i++) 
            System.out.println(arr[i]);
    }

    public int count( )
    {
        return count;
    }

    public boolean isElementOf(int e)
    {
        for(int i : arr) 
            if(i == e) 
                return true;

        return false;
    }

    public int getElement(int index)
    {
        return arr[index];
    }

    public Set union(Set s)
    {
        int j = count;
        int[] union = new int[count + s.count()];
        // Copies an array from the specified source array, 
        // beginning at the specified position, 
        // to the specified position of the destination array.
        System.arraycopy(arr, 0, union, 0, count);

        for(int i = 0; i < s.count(); i++) 
        {
            if(!isElementOf(s.getElement(i))) 
            {
                union[j] = s.getElement(i);
                j++;
            }
        }

        Set u = new Set(union.length);

        for(int i : union)
            u.add(i);

        return u;    
    }
}