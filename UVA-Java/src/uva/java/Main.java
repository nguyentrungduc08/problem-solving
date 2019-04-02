/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package uva.java;
import java.io.*;
import java.util.StringTokenizer;
/**
 *
 * @author ducnt6
 */
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
        int[] L = new int[100002];
        int[] R = new int[100002];
        String str;
        StringBuilder stringBuilder = new StringBuilder(25000);
        while ((str = input.readLine()) != null) {
            StringTokenizer stringTokenizer = new StringTokenizer(str);
            int numSoldiers = 
               Integer.parseInt(stringTokenizer.nextToken());
            int loss = 
               Integer.parseInt(stringTokenizer.nextToken());
            if (numSoldiers == 0 && loss == 0) break;
            final int NIL = 0;
            L[0] = R[0] = NIL;
            for (int i = 1; i <= numSoldiers; ++i) {
                L[i] = i - 1;
                R[i] = i + 1;
            }
            R[numSoldiers] = NIL;
            int lhs, rhs, sL, sR;   //sL = survivor
            for (int i = 0; i < loss; i++) {
                str = input.readLine();
                stringTokenizer = new StringTokenizer(str);
                lhs = Integer.parseInt(stringTokenizer.nextToken());
                rhs = Integer.parseInt(stringTokenizer.nextToken());
                sL = L[lhs];
                sR = R[rhs];
                if (sL == 0) stringBuilder.append('*');
                else stringBuilder.append(sL);
                stringBuilder.append(' ');
                if (sR == 0) stringBuilder.append('*');
                else stringBuilder.append(sR);
                stringBuilder.append('\n');
                R[sL] = sR;
                L[sR] = sL;
            }
            stringBuilder.append("-\n");
            if (stringBuilder.length() >= 10000) {
                output.write(stringBuilder.toString());
                stringBuilder = new StringBuilder(25000);
            }
        }
        output.write(stringBuilder.toString());
        output.flush();
        output.close();
    }
}
