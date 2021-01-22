import java.util.*;

public class StringLength {

    static void validate(String s) throws ExceptionLineTooLong {
        if (s.length() > 80) {
            throw new ExceptionLineTooLong("The strings is too long.");
        }
        else {
            System.out.print(s);
        }
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            // String str = "The quick brown fox jumped over the lazy dogs. The quick brown fox jumped over the lazy dogs.The quick brown fox jumped over the lazy dogs. The quick brown fox jumped over the lazy dogs.The quick brown fox jumped over the lazy dogs. The quick brown fox jumped over the lazy dogs.The quick brown fox jumped over the lazy dogs. The quick brown fox jumped over the lazy dogs.The quick brown fox jumped over the lazy dogs. The quick brown fox jumped over the lazy dogs.The quick brown fox jumped over the lazy dogs. The quick brown fox jumped over the lazy dogs.The quick brown fox jumped over the lazy dogs. The quick brown fox jumped over the lazy dogs.The quick brown fox jumped over the lazy dogs. The quick brown fox jumped over the lazy dogs.The quick brown fox jumped over the lazy dogs. The quick brown fox jumped over the lazy dogs.The quick brown fox jumped over the lazy dogs. The quick brown fox jumped over the lazy dogs.The quick brown fox jumped over the lazy dogs. The quick brown fox jumped over the lazy dogs.The quick brown fox jumped over the lazy dogs. The quick brown fox jumped over the lazy dogs.The quick brown fox jumped over the lazy dogs. The quick brown fox jumped over the lazy dogs.The quick brown fox jumped over the lazy dogs. The quick brown fox jumped over the lazy dogs.The quick brown fox jumped over the lazy dogs. The quick brown fox jumped over the lazy dogs.The quick brown fox jumped over the lazy dogs. The quick brown fox jumped over the lazy dogs.";
            // String str = "The quick brown fox jumped over the lazy dogs.";
            // validate(str);
            validate(sc.nextLine());
        } catch (Exception e) {
            System.out.print(e.getMessage());
        }
    }
}
