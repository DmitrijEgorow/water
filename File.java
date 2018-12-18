package info;

import java.io.*;
import java.util.Scanner;

public class Fil {
    public static void main(String[] args) {
        String s="";
        long number=0;
        try {
            File file = new File("input.txt");
            Scanner in = new Scanner(file);
            while (in.hasNext()) {
                String e = in.next();
                if (square(e)){
                    s=s+e+" ";
                    number++;
                }
            }
            in.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        try {
            File file = new File("output.txt");
            PrintWriter out = new PrintWriter(new
                    FileWriter(file));
            out.printf(String.valueOf(number)+"\n"+s); //Записываем текст в файл
            out.close(); // Закрываем файл
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    static boolean square(String s){
        int n=Integer.parseInt(s);
        if (n<0) return false;
        if (((int)Math.sqrt(n))*((int)Math.sqrt(n))==n){
            if (((int)Math.sqrt(n))%2==1){
                return true;
            }
            else return false;
        } else return false;
    }
}
