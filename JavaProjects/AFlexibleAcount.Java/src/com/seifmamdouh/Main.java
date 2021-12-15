package com.seifmamdouh;

import java.util.Random;

public class Main {

    private static final Random rn = ;

    public static void main(String[] args) {
        import java.text.NumberFormat;
        import java.util.Random;

        public class Account
        {
            private double balance;
            private String name;
            private long acctNum;

            private int random = new Random();

            // Constructor -- initializes balance, owner, and account number
            public Account(double balance, String name, long acctNum)
            {
                this.balance = balance;
                this.name = name;
                this.acctNum = acctNum;

            }

            // Constructor -- Generates random balance (less than 1000) and random account number (from 1000 - 5000), with a name supplied
            public Account(String name)
            {

                this(
                        Random.nextInt(1000) + Math.random(),
                        name,
                        Random.nextInt(4000) + 1001);
            }

            // Checks to see if balance is sufficient for withdrawal.
            // If so, decrements balance by amount; if not, prints message.
            public void withdraw(double amount)
            {
                if (balance >= amount)
                    balance -= amount;
                else
                    System.out.println("Insufficient funds");
            }

            // Adds deposit amount to balance
            public void deposit(double amount)
            {
                balance += amount;
            }

            // Returns the account owner
            public String getName()
            {
                return name;
            }

            // Returns balance.
            public double getBalance()
            {
                return balance;
            }

            // Returns the account number
            public long getAcctNumber()
            {
                return acctNum;
            }

            // Returns a string containing the name, account number, and balance.
            public String toString()
            {
                // write your code here

                NumberFormat usMoney = NumberFormat.getCurrencyInstance();

                return "Account Owner: " + name
                        + "\nAccount Number: " + acctNum
                        + "\nBalance: " + usMoney.format(balance);

		/*String str = "Account Owner: %s%nAccount Number: %d%nBalance: $%.2f", name, Long.parsetoInt(acctNum), balance;
	  return str; */
            }

            // Deducts $10 service fee
            public double chargeFee()
            {
                // write your code here
                balance -= 10;

                return balance;
            }

            // Changes the name on the account
            public void changeName(String newName)
            {
                // Write your code here
                name = newName;
            }

            // Closes the account: sets balance to 0 and adds "CLOSED" to account name and decreases number of active accounts
            public void close()
            {
                this.name += " - CLOSED";
                this.balance = 0;
            }

            // Transfers money from one bank account to another bank account
            public void transfer(Account acct, double amount)
            {
                NumberFormat usMoney = NumberFormat.getCurrencyInstance();
                if (amount < 0)
                {
                    System.out.println("Invalid amount to transfer from account #";
    }
}
        }

    }

}
}