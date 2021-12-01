package com.company;
import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {


    public static void main(String[] args) {
        try (FileInputStream fin = new FileInputStream("input.txt");
             FileOutputStream fout = new FileOutputStream("output.txt");
             PrintStream ps = new PrintStream(fout)) {
            
            Scanner in = new Scanner(fin);
            long N = in.nextLong();
            int q = 0;
            ArrayList<Integer> mass = new ArrayList<>();

            while (N != 0) {
                if ((N & 1l) == 1) {
                    mass.add(q);
                }
                q++;
                N >>= 1;
            }
            for (int i = 0; i < mass.size(); i++) {
                ps.println(mass.get(i));
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
