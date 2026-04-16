package org.example;
import java.util.Scanner;

public class Aprovacao {
    public static boolean aprovar(double salario, double parcela) {
        return parcela <= (salario * (30.0 / 100));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Digite seu salario: ");
        double salario = sc.nextDouble();

        System.out.print("Digite o valor da parcela: ");
        double parcela = sc.nextDouble();

        boolean resultado = aprovar(salario, parcela);
        if (resultado) {
            System.out.println("Aprovado");
        } else {
            System.out.println("Reprovado");
        }
        sc.close();
    }
}