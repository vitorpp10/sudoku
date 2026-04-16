package org.example;
import java.util.Scanner;

public class CalculoMedia {
    public static double media(double x, double y, double z) {
        return (x + y + z) / 3;
    }

    public static void main(String[] args) {
        Scanner leitor = new Scanner(System.in);

        System.out.print("Digite seu nome: ");
        String nome = leitor.nextLine();

        System.out.print("Sua primeira nota: ");
        double a = leitor.nextDouble();
        System.out.print("Sua segunda nota: ");
        double b = leitor.nextDouble();
        System.out.print("Sua terceira nota: ");
        double c = leitor.nextDouble();

        System.out.println(" ");

        double resultado = media(a, b, c);
        System.out.print("Media final de " + nome + " = " + resultado);

        leitor.close();
    }
}