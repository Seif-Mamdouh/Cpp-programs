//Java Code:

import java.util.*;

class Grade{

    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);

        int numStudents,grade,sum=0,countPass=0,countFail=0;

        System.out.print("Enter Number of students: ");

        numStudents=sc.nextInt();

        for(int i=0;i<numStudents;i++){

            System.out.print("Enter grade for student "+(i+1)+": ");

            grade=sc.nextInt();

            countFail=grade<60?countFail++:countFail;

            countFail=grade>=60?countPass++:countPass;

            sum+=grade;

        }

        double avg=(double)sum/numStudents;

        System.out.println("Average grade: "+avg);

        System.out.println("Number of students who passed: "+countPass);

        System.out.println("Number of students who passed: "+countFail);

    }

}