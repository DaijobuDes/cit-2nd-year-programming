public class Matrix{
    private int matrix[][];
    private String letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    public Matrix(){}
    
    public Matrix(int row, int column){
        matrix = new int[row][column];
    }
    
    public void read(String str) {

        try {

            for (int i = 0; i < str.length(); i++) {
                if (letters.contains("" + str.toUpperCase().charAt(i)))
                    throw new ExceptionWrongMatrixValues("ExceptionWrongMatrixValues");
                if (i < str.length() - 1)
                    if (str.charAt(i) == ' ' && str.charAt(i + 1) == ' '
                            || str.charAt(i) != ' ' && str.charAt(i + 1) != ' ')
                        throw new ExceptionWrongMatrixDimension("ExceptionWrongMatrixDimension");
            }

            String[] numbers = str.split("\\.");

            if (matrix == null)
                matrix = new int[numbers.length][numbers[0].length() / 2];

            for (int i = 0; i < numbers.length; i++) {
                if (numbers[i].length() != numbers[0].length() && numbers[i].length() != 5)
                    throw new ExceptionWrongMatrixValues("ExceptionWrongMatrixValues");
            }

            for (int i = 0; i < numbers.length; i++) {
                for (int j = 0, count = 0; j < numbers[i].length(); j++) {
                    if (numbers[i].charAt(j) != ' ')
                        matrix[i][count++] = (int) numbers[i].charAt(j) - 48;
                }
            }

            for (int i = 0; i < matrix.length; i++) {
                for (int l = 0; l < matrix[i].length; l++)
                    System.out.print(matrix[i][l] + " ");
                System.out.printf("\n");
            }

        } catch (ExceptionWrongMatrixValues e) {
            System.out.println(e.getMessage());
        } catch (ExceptionWrongMatrixDimension e) {
            System.out.println(e.getMessage());
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

    }
}