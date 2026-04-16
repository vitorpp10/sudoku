package org.example;
import java.util.Scanner;

public class Soma {
    public static int somar(int x, int y) {
        return x + y;
    }

    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);

        System.out.print("Digite o primeiro numero: ");
        int a = leitor.nextInt();

        System.out.print("Digite o segundo numero: ");
        int b = leitor.nextInt();

        int resultado = somar(a, b);

        System.out.println(" ");
        System.out.println(a + " + " + b + " = " + resultado);

        leitor.close();
    }
}