package com.company;

import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("input.txt"));
        FileOutputStream fout = new FileOutputStream("output.txt");
        try (PrintStream ps = new PrintStream(fout)) {
            int x = in.nextInt();
            int y = in.nextInt();
            int x1 = in.nextInt();
            int y1 = in.nextInt();
            int x2 = in.nextInt();
            int y2 = in.nextInt();
            int temp1 = 1000, temp2 = 1000;
            int mas[][] = new int[temp1][temp2];
            for (int i = 0; i < x; ++i) {
                for (int j = 0; j < y; ++j) {
                    if (i == x1 - 1 && j == y1 - 1 || i == y1 - 1 && j == x1 - 1 || i == x2 - 1 && j == y2 - 1 || i == y2 - 1 && j == x2 - 1) {
                        mas[i][j] = 0;
                    } else {
                        mas[i][j] = (i + 1) * (j + 1);
                        int numb = 1;
                        for (int k = 0, k_end = (i + 1) >> 1; k < k_end; ++k) {
                            numb = mas[k][j] + mas[i - 1 - k][j];
                            if (mas[i][j] > numb)
                                mas[i][j] = numb;

                        }
                        for (int k = 0, k_end = (j + 1) >> 1; k < k_end; ++k) {
                            numb = mas[i][k] + mas[i][j - 1 - k];
                            if (mas[i][j] > numb)
                                mas[i][j] = numb;
                        }
                    }
                }
            }
            ps.println(mas[x - 1][y - 1]);
        }
    }
}
