public class MatrixMain {
    public static void main(String[] args) {
        String input="1 2 3 . 1 e 3 .";
        Matrix m = new Matrix();
        m.read(input);

        String input2="1 2 3 . 1 2 3 4 5 .";
        Matrix m2 = new Matrix();
        m2.read(input2);

        String input3="12312345";
        Matrix m3 = new Matrix();
        m3.read(input3);

        String input4="1 2 . 3 4 .";
        Matrix m4 = new Matrix();
        m4.read(input4);
    }
}
