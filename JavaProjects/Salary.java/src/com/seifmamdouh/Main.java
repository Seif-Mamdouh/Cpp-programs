package com.seifmamdouh;

        public class Salary {
            public static void main(String[] args) {
                // write your code here
                double percentRaise;
                double currentSalary; // employee's current salary
                double raise = 0.0;// amount of the raise
                double newSalary; // new salary for the employee
                String rating; // performance rating

                Scanner scan = new Scanner(System.in);
                System.out.print("Enter the current salary: ");
                currentSalary = scan.nextDouble();
                System.out.print("Enter the performance rating (Excellent, Good, or Poor): ");
                rating = scan.next();
// Compute the raise using if ...

                if (rating.equals("Excellent")) {
                    percentRaise = 0.06;
                    raise = currentSalary * percentRaise;
                } else if (rating.equals("Good")) {
                    percentRaise = 0.04;
                    raise = currentSalary * percentRaise;
                } else if (rating.equals("Poor")) {
                    percentRaise = 0.015;
                    raise = currentSalary * percentRaise;
                } else {
                    System.out.println("rating not found.");
                }
                newSalary = currentSalary + raise;
// Print the results
                NumberFormat money = NumberFormat.getCurrencyInstance();
                System.out.println();
                System.out.println("Current Salary: " + money.format(currentSalary));
                System.out.println("Amount of your raise: " + money.format(raise));
                System.out.println("Your new salary: " + money.format(newSalary));
                System.out.println();

            }

        }

