package com.seifmamdouh;

import java.util.Scanner;

public class TestAccount2 {

        public static void main(String[] args) {

            String name;
            Account accounts[]=new Account[3];
            /*
             * Creating an Scanner class object which is used to get the inputs
             * entered by the user
             */
            Scanner sc = new Scanner(System.in);

            for(int i=0;i<accounts.length;i++)
            {
                //Getting the input entered by the user
                System.out.print("Enter Name of Account Holder#"+(i+1)+":");
                name=sc.nextLine();
                Account acc=new Account(100,name);
                accounts[i]=acc;
            }

            System.out.println("Displaying the 3 Account Info :");
            for(int i=0;i<accounts.length;i++)
            {
                System.out.println(accounts[i]);
            }

            accounts[0].close();
            Account newAcc=Account.consolidate(accounts[1],accounts[2]);
            accounts[0]=newAcc;
            System.out.println("Displaying the 3 Account Info After consolidation :");
            for(int i=0;i<accounts.length;i++)
            {
                System.out.println(accounts[i]);
            }


        }
}
