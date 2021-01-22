import java.util.*;

public class Match
{
    // Inputs
    // You will always have my love, my love, for the love I love is as lovely as love itself.
    // love
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String str1 = sc.nextLine();
        String str2 = sc.nextLine();
        System.out.println("New text: " + match(str1, str2));
        System.out.println("\nNumber of occurrence: " + countOccurence(str1, str2));
        sc.close();
    }

    public static String match(String str1, String str2)
    {
        String[] words = str1.split(" ");
        String punctuations = ",;\'\".?!";
    
        for(int i = 0; i < words.length; i++)
        {
            if(words[i].toUpperCase().startsWith(str2.toUpperCase()))
            {
                if(words[i].length() == str2.length() || punctuations.contains(""+words[i].charAt(str2.length())))
                {
                    words[i] = words[i].toUpperCase();
                }
            }
        }
    
        return String.join(" ", words);
    }
    
    public static int countOccurence(String str1, String str2)
    {
        String[] words = str1.split(" ");
        String punctuations = ",;\'\".?!";

        int count = 0;
        for(int i = 0; i < words.length; i++)
        {
            if(words[i].toUpperCase().startsWith(str2.toUpperCase()))
            {
                if(words[i].length() == str2.length() || punctuations.contains(""+words[i].charAt(str2.length())))
                {
                    count++;
                }
            }
        }

        return count;
    }
}
