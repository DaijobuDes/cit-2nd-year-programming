import java.util.*;

public class Correct
{
    /* Inputs followed by outputs
    after a train crashed, every single person died. who survived?all of the couples.
    After a train crashed, every single person died. Who survived?All of the couples.
    turn us on our backs and open up our stomachs, and you will be the wisest but at the start a lummox. what are we? books.
    Turn us on our backs and open up our stomachs, and you will be the wisest but at the start a lummox. What are we? Books.
    help! help! it's an emergency. 
    */
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String text = sc.nextLine();
        char[] tChars = text.toCharArray();

        tChars[0] = Character.toUpperCase(tChars[0]);
        String punctuations = ".?!";

        for (int i = 0; i < tChars.length; i++)
            if( punctuations.contains(""+tChars[i]))
                for (i += 1; i < tChars.length; i++)
                    if (Character.isLetter(tChars[i])) {
                        tChars[i] = Character.toUpperCase(tChars[i]);
                        break;
                    }

        System.out.println(tChars);
        sc.close();
    }
}
