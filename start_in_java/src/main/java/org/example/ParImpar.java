package org.example;
import java.util.Scanner;

public class ParImpar {
    public static boolean parImpar(int x) {
        return x % 2 == 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Digite o numero: ");
        int n = sc.nextInt();

        boolean resultado = parImpar(n);
        if (resultado) {
            System.out.println("Par");
        } else {
            System.out.println("Impar");
        }
        sc.close();
    }
}