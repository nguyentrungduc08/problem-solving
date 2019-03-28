/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package uva.java;

import java.util.Scanner;

/**
 *
 * @author ducnt6
 */
public class java_10038 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        while (sc.hasNext()) {
            int n = sc.nextInt();
            int[] arr = new int[n+1];
            for (int i = 0; i < n; ++i) {
                arr[i] = sc.nextInt();
            }
            boolean[] checker = new boolean[n+1];
            for(int i = 0; i < n; ++i) {
                checker[i] = false;
            }
                    
            boolean isCorrect = true;
            for(int i = 0; i < n-1; ++i) {
                int dis = Math.abs(arr[i] - arr[i+1]);
                if ( dis > n-1 || checker[dis]) {
                    isCorrect = false;
                    break;
                } else {
                    checker[dis] = true;
                }
            } 
            
            if (isCorrect) {
                System.out.println("Jolly");
            } else {
                System.out.println("Not jolly");
            }
        }
    }
}
