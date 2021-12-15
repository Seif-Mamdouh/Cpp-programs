//Factorial1.java
import java.util.Scanner;

public class Factorial1 {
    public static void main(String args[]){
        int result = 1,n;
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.print("Enter a number to compute factorial: ");
            n = sc.nextInt();
            if (n < 0) {
                System.out.println("A non negative number is required.");
                break;
            }
            result = 1;
            while (n > 1) {
                result *= n;
                n--;
            }
            System.out.println("Factorial of "+n+" is = " + result);
        }
    }
}