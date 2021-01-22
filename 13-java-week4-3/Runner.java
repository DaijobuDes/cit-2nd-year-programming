public class Runner {
    public static void main(String[] args) {
        // Case 1
        Set s1 = new Set();
        s1.add(1);
        s1.add(2);
        s1.add(3);
        s1.add(2);
        s1.display();

        // Case 2
        Set s2 =  new Set();
        s2.add(10);
        s2.add(12);
        s2.add(13);
        s2.add(14);
        s2.add(15);
        s2.add(17);
        s2.add(16);
        s2.add(18);
        s2.add(20);
        s2.add(21);
        s2.add(22);
        System.out.println("Count: "+s2.count());
        s2.display();

        // Hidden Case 1
        Set hs1 = new Set();
        hs1.add(1);
        hs1.add(2);
        hs1.add(3);
        hs1.add(6);
        System.out.println(hs1.isElementOf(2));
        System.out.println(hs1.isElementOf(10));

        // Hidden Case 2
        Set hs2 = new Set();
        Set hs3 = new Set();
        Set union = null;
        hs2.add(1);
        hs2.add(2);
        hs2.add(3);
        hs2.add(4);
        hs3.add(10);
        hs3.add(2);
        hs3.add(20);
        union = hs2.union(hs3);
        union.display();

        // Case 3
        Set s3 =  new Set();
        s3.add(10);
        s3.add(12);
        s3.add(13);
        s3.add(14);
        s3.add(15);
        s3.add(17);
        s3.add(16);
        s3.add(18);
        s3.add(20);
        s3.add(21);
        s3.add(22);
        Set s4 = new Set();
        s4.add(41);
        s4.add(42);
        s4.add(43);
        s4.add(44);
        s4.add(45);
        s4.add(46);
        s4.add(47);
        s4.add(48);
        s4.add(49);
        s4.add(50);
        Set union2 = s3.union(s4);
        union2.display();
    }
}
