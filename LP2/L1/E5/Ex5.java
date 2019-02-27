import java.io.*;
import java.util.*;

public class Ex5 {
	private static BufferedReader inData = new BufferedReader(new InputStreamReader(System.in));

	private static String entrada(){
		String line = "";
		try{
			line = inData.readLine();
		}catch(IOException e){
			System.out.println(e);
		}
		return line;
	}
	public static void main(String[] args){
		int qntdPessoas = 0;
		char tipo;
		String nome, dataNasc;
		double peso = 0, altura = 0;
		boolean permitido = false;

		ArrayList lista = new ArrayList();
		while(!permitido){
			try{
				System.out.print("Digite a quantidade de pessoas: ");
				qntdPessoas = Integer.parseInt(entrada());
				permitido = true;
			}catch(NumberFormatException e){
				System.out.println(e);
				permitido = false;
			}
		}
		permitido = false;
		for(int i = 0; i < qntdPessoas; i++){
			System.out.print("Inserir homem(h) ou mulher(m): ");
			tipo = entrada().charAt(0);
			while(tipo != 'h' && tipo != 'm'){
				System.out.println("--- Opcao Invalida, coloque h para homem ou m para mulher!!!");
				System.out.print("Inserir homem(h) ou mulher(m) novamente: ");
				tipo = entrada().charAt(0);
			}

			System.out.print("Digite o nome: ");
			nome = entrada();
			while(nome.isEmpty()){
				System.out.println("--- Nome nao pode ser vazio!!!");
				System.out.print("Digite o nome novamente: ");
				nome = entrada();
			}

			System.out.print("Digite a data de nascimento: ");
			dataNasc = entrada();

			while(!permitido){
				try{
					System.out.print("Digite o peso: ");
					peso = Double.parseDouble(entrada());
					permitido = true;
				}catch(NumberFormatException e){
					System.out.println(e);
					permitido = false;
				}
			}
			permitido = false;

			while(!permitido){
				try{
					System.out.print("Digite a altura (em metros): ");
					altura = Double.parseDouble(entrada());
					permitido = true;
				}catch(NumberFormatException e){
					System.out.println(e);
					permitido = false;
				}
			}
			permitido = false;

			if(tipo == 'h'){
				lista.add(new Homem(nome, dataNasc, peso, altura));
			}else if(tipo == 'm'){
				lista.add(new Mulher(nome, dataNasc, peso, altura));
			}
		}
		for(int i = 0; i < lista.size(); i++){
			System.out.println(lista.get(i));
		} 

	}
}