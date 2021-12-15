package com.seifmamdouh;

import java.util.*;

        public class LoveCS {

            public static void main (String[] args){

// Read input from user

                Scanner sc = new Scanner(System.in);

                int limit = sc.nextInt();

                int count = 1;

// create variable to store the sum

                int sum = 0;

                while (count<=limit)

                {

                    System.out.println(count+" I Love Computer Science! ! ");

//Calculate Sum

                    sum=sum+count;

                    count++;

                }

//print the message and sum

                System.out.println("Printed this message "+limit+" times. The sum of the numbers from 1 to "+limit+" is "+sum+".");

            }

        }
