package info;

import java.io.*;
import java.util.Scanner;

public class Tfiles {
    public static PrintStream out = System.out;
    public static void main(String[] args) {
        int m, n, k, l;
        try {
            File file1 = new File("input1.txt");
            File file2 = new File("input2.txt");
            Scanner in1 = new Scanner(file1);
            Scanner in2 = new Scanner(file2);
            k = Integer.parseInt(in1.next());
            l=Integer.parseInt(in2.next());
            m=Integer.parseInt(in1.next());
            n=Integer.parseInt(in1.next());
            File fout1 = new File("output1.txt");
            File fout2 = new File("output2.txt");
            File fout3 = new File("output3.txt");
            PrintWriter out1 = new PrintWriter(new FileWriter(fout1));
            PrintWriter out2 = new PrintWriter(new FileWriter(fout2));
            PrintWriter out3 = new PrintWriter(new FileWriter(fout3));
            for (int i=0; i<(Integer.min(k, l+1)); i=i+2){
                String a1[][]= new String[m][n];
                String a2[][]= new String[m][n];
                String b1[][]= new String[m][n];
                String b2[][]= new String[m][n];
                for (int j1=0; j1<m; j1++){
                    for (int j2=0; j2<n; j2++){
                        a1[j1][j2]=in1.next();
                        a2[j1][j2]=in2.next();
                        out1.printf(a1[j1][j2]+"\t");
                    }
                    out1.printf("\n");
                }
                for (int j1=0; j1<m; j1++){
                    for (int j2=0; j2<n; j2++){
                        b1[j1][j2]=in1.next();
                        if (i+1<l) b2[j1][j2]=in2.next();
                    }
                }
                for (int j1=0; j1<m; j1++){
                    for (int j2=0; j2<n; j2++){
                        out1.printf(a2[j1][j2]+"\t");
                        out2.printf(b1[j1][j2]+"\t");
                    }
                    out1.printf("\n");
                    out2.printf("\n");
                }
                if (i+1<l)
                    for (int j1=0; j1<m; j1++){
                        for (int j2=0; j2<n; j2++){
                            out2.printf(b2[j1][j2]+"\t");
                        }
                        out2.printf("\n");
                    }
            }
            if (k<l){ // оставшиеся в большем файле
                for (int i=(Integer.min(k, l))+1; i<l; i++) {
                    String a1[][] = new String[m][n];
                    for (int j1 = 0; j1 < m; j1++) {
                        for (int j2 = 0; j2 < n; j2++) {
                            a1[j1][j2] = in2.next();
                            out3.printf(a1[j1][j2] + "\t");
                        }
                        out3.printf("\n");
                    }
                }
            }
            else{
                if (k>l){
                    for (int i=Integer.min(k, l)+1; i<k; i++) {
                        String a1[][] = new String[m][n];
                        for (int j1 = 0; j1 < m; j1++) {
                            for (int j2 = 0; j2 < n; j2++) {
                                a1[j1][j2] = in1.next();
                                out3.printf(a1[j1][j2] + "\t");
                            }
                            out3.printf("\n");
                        }
                    }
                }
            }
            in1.close();
            in2.close();
            out1.close();
            out2.close();
            out3.close();
            File fout1p = new File("output1.txt");
            File fout2p = new File("output2.txt");
            Scanner p1 = new Scanner(fout1p);
            Scanner p2 = new Scanner(fout2p);
            while (p1.hasNextLine()){
                out.println(p1.nextLine());
            }
            out.println();
            while (p2.hasNextLine()){
                out.println(p2.nextLine());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}

/*
input1.txt
6
2 2
1 1
1 1
2 2
2 2
3 3
3 3
4 4
4 4
5 5
5 5
6 6
6 6

input2.txt
5
21 21
21 21
22 22
22 22
23 23
23 23
24 24
24 24
25 25
25 25

 */
