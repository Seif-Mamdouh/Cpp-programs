package com.seifmamdouh;

import java.util.Scanner;

public class Account {
    private double balance;
    private int accountNumber;
    private String customerName;
    private static int noOfAccounts;
    public Account(double initialBalance, String custName) {

        balance = initialBalance;
        accountNumber = (int)(Math.random()*((9999-1000)+1))+1000;
        customerName = custName;
        noOfAccounts++;
    }

    public Account() {
        balance = 0.0;
        accountNumber =(int)(Math.random()*((9999-1000)+1))+1000;
        customerName = "";
        noOfAccounts++;
    }

    public void deposit(double amount) {
        balance += amount;
    }

    public void withdraw(double amount) {
        balance -= amount;
    }

    public double getBalance() {
        return (int) (balance * 100) / 100.0;
    }

    public int getAccountNumber() {
        return accountNumber;
    }

    public String getCustomerName() {
        return customerName;
    }

    public void close() {
        balance = 0.0;
        this.customerName=customerName+"CLOSED";
        noOfAccounts--;
    }

    public static int numAccounts()
    {
        return noOfAccounts;
    }
    public static Account consolidate(Account acct1, Account acct2)
    {
        Account newAcc=null;
        if(acct1.getCustomerName().equalsIgnoreCase(acct2.getCustomerName()) && (acct1.getAccountNumber()!=acct2.getAccountNumber()))
        {
            newAcc=new Account(acct1.getBalance()+acct2.getBalance(), acct1.getCustomerName());
            acct1.close();
            acct2.close();
        }
        else
        {
            System.out.println("Two Accounts is having same Account Number Or or Different name");
        }
        return newAcc;
    }
    @Override
    public String toString() {
        return "Account :: Balance : " + balance + ", Account Number : "
                + accountNumber + ", Customer Name : " + customerName;
    }


}

