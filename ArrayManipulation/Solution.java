package ArrayManipulation;

import java.math.BigInteger;
import java.util.Scanner;

public class Solution {
    static BigInteger [] arr;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        arr = new BigInteger [n + 2];
        for (int i=0; i<=n; ++i) {
           arr [i] = BigInteger.ZERO;
        }
        for(int i = 0; i < m; i++){
            int a = in.nextInt();
            int b = in.nextInt();
            String temp = in.next();
            BigInteger  k = new BigInteger(temp);
            arr [a - 1] = arr [a - 1].add(k);
            arr [b] = arr [b].subtract(k);
        }
        BigInteger max = arr [0];
        for (int i=1; i<n; ++i) {
           arr [i] = arr [i].add (arr [i-1]);
           max = arr[i].max(max);
        }
        System.out.println(max);
        in.close();
    }
}