
public class SquareOne {
    public static void main(String[] args) {
        // Check if argument is provided

        int num = Integer.parseInt(args[0]);
        int square = num * num;
        
        System.out.println("Square of " + num + " = " + square);
    }
}
