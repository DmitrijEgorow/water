package info;

import java.io.*;
import java.util.Scanner;

public class Fil {
    public static void main(String[] args) {
        String s="";
        String out_data[] = new String[14], current[]=new String[14];
        out_data[11]="9999";
        out_data[12]="99";
        out_data[13]="99";
        try {
            File file = new File("input.txt");
            Scanner in = new Scanner(file);
            while (in.hasNext()) {
                for (int i=0; i<14; i++){
                    current[i]=in.next();
                }
                if (Integer.parseInt(current[11])<=Integer.parseInt(out_data[11])){
                    if (Integer.parseInt(current[12])<=Integer.parseInt(out_data[12])){
                        if (Integer.parseInt(current[13])<=Integer.parseInt(out_data[13])){
                            out_data=current.clone();
                        }
                    }
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
            for (int i=0; i<14; i++){
                out.printf(out_data[i]+"\n");
            }
            out.close(); // Закрываем файл
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
