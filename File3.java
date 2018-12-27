package info;

import java.io.*;
import java.util.Scanner;

public class Fil {
    public static PrintStream out = System.out;
    public static void main(String[] args) {
        String s="";
        long number=0;
        double sum=0;
        String current[]=new String[4];
        try {
            File file = new File("data.in");
            Scanner in = new Scanner(file);
            while (in.hasNextLine()) {
                for (int i=0; i<4; i++){
                    current[i]=in.nextLine();
                }
                if (current[1].contains("C++")){
                    sum=sum+Double.parseDouble(current[3]);
                }
                number++;
            }
            in.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        out.println(number+" "+sum);
    }
}

/*
data.in:

YoKin
C++ Intro
300000
1000.5

 */
