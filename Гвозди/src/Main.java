import java.text.DecimalFormat;
import java.text.Format;
import java.util.*;
import java.io.*;



public class Main {
    static double a[] = new double[101];
    static double mas[] = new double[101];
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("in.txt"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
        int n = Integer.parseInt(br.readLine());
        String temp;
        for (int i = 1; i <= n; i++) {
            temp = br.readLine();
            a[i] = Double.parseDouble(temp);
        }
        mas[2] = a[2] - a[1];
        mas[3] = a[3] - a[1];
        for (int i = 4; i <= n; i++)
            mas[i] = Math.min(mas[i - 1], mas[i - 2]) + a[i] - a[i - 1];
        String a = new DecimalFormat("0.00").format(mas[n]);
        bw.write(a.replace(',', '.'));
        br.close();
        bw.close();
    }
}