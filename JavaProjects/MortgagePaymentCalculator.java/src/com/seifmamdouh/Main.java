import java.text.NumberFormat;
import java.util.Scanner;

public class MortageCalulator {

    public static double calculateMonthlyPayment(int loanAmount, int termInYears, double interestRate)  {

        interestRate /= 100.0;
        double monthlyRate = interestRate / 12.0;
        int termInMonths = termInYears * 12;

        double monthlyPayment =
                (loanAmount*monthlyRate) / (1-Math.pow(1+monthlyRate, -termInMonths));
        return monthlyPayment;
    }
    public static void main (String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter loan amount: ");
        int loanAmount = scanner.nextInt();

        System.out.println("Enter loan term (in years): ");
        int termInYears = scanner.nextInt();

        System.out.print("Enter interest rate: ");
        double interestRate = scanner.nextDouble();

        double monthlyPayment = calculateMonthlyPayment(loanAmount, termInYears, interestRate);

        NumberFormat currencyFormat =
                NumberFormat.getCurrencyInstance();
        NumberFormat interestFormat =
                NumberFormat.getPercentInstance();

        System.out.println("Loan Amount: "+ currencyFormat.format(loanAmount));
        System.out.println("Loan Term: "+ termInYears+" years");
        System.out.println("Interest Rate: " + interestFormat.format(interestRate));
        System.out.println("Monthly Payment: " + currencyFormat.format(monthlyPayment));




    }
}
