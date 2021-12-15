//Program Code:

import java.text.NumberFormat;

import java.util.Scanner;

public class CSCreditCard {

    // Constructor

    public CSCreditCard()

    {

        introduction();

    }


    private void calculateChargesOnCard(double balance, double charges)

    {

        String pattern = "#,###.##;(#,###.##)";

        NumberFormat nf = NumberFormat.getCurrencyInstance();

        double interest = 0.0;

        System.out.println();

        printTableHeader();

        System.out.println("Previous balance: " + nf.format(balance));

        System.out.println("Additional charges: " + nf.format(charges));



        if (balance > 0)

        {

            interest = balance * 0.02;

            System.out.println("Interest @ 2%: " + nf.format(interest));

            System.out.println();

            balance += interest;
        }

        balance += charges;

        double minimumPay = balance;

        if (balance >= 50.0 && balance <= 300.0)

        {

            minimumPay = 50.0;

        }

        else if (balance > 300.0)

        {

            minimumPay = balance * 0.20;

        }

        System.out.println("New Balance: " + nf.format(balance));

        System.out.println("Minimum Payment: " + nf.format(minimumPay));

        System.out.println("------------------------");

    }

    private void introduction()

    {

        Scanner sc = new Scanner(System.in);


        do

        {

            printTableHeader();


            message("Enter the previous balance");

            double balance = loopInput(sc);

            message("Enter any additional charges");

            double charges = loopInput(sc);

            calculateChargesOnCard(balance, charges);


            message("Do another? [y/n]");

        } while (!sc.nextLine().equalsIgnoreCase("n"));

        System.out.println("Thank you, and goodbye!");

    }


    private Double loopInput(Scanner sc)

    {

        String sNum;

        do

        {

            sNum = sc.nextLine();

        } while (!validate(sNum));

        return Double.parseDouble(sNum);

    }


    private boolean validate(String value)

    {

        try

        {

            Double.parseDouble(value);

            return true;

        } catch (Exception e)

        {

            message("-----------------\n");

            message("Please enter a valid amount");

            return false;

        }

    }


    private void message(String s)

    {

        System.out.printf("%s ==>", s);

    }


    private void printTableHeader()

    {

        String head = "CS CARD International Statement\n";

        head += "===============================\n";

        System.out.println(head);

    }


    public static void main(String[] args)

    {

        new CSCreditCard();

    }

}