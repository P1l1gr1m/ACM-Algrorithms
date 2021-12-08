package com.company;
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("input.txt"));
        FileOutputStream fout = new FileOutputStream("output.txt");
        try (PrintStream ps = new PrintStream(fout)) {
            int k = in.nextInt();
            int n = in.nextInt();
            int res = 0;
            int mas[] = new int[n+1];
            mas[0] = k;
            mas[1] = k * k;
            for (int i = 2; i < n; ++i) {
                mas[i] = (mas[i-1] + mas[i-2]) * k;
            }
            for (int i = 0; i < n; ++i) {
                res += mas[i];
            }
            ps.println(res);
        }
    }
}
