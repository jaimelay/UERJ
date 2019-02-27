import java.io.*;

public class Ex4 {
	private static int qntdFuncionarios = 0;
	private static BufferedReader inData = new BufferedReader(new InputStreamReader(System.in));

	public Ex4(int qtdFuncionarios){
		Ex4.qntdFuncionarios = qtdFuncionarios;
	}

	private void calculaSalarios(){
		FuncionarioContratado[] funcContratado = new FuncionarioContratado[qntdFuncionarios];
		System.out.println("--- Cadastro de Funcionarios");
		String nome, codigo;
		double salario = 0;
		int dependentes = 0;
		boolean permitido = false;
		for(int i = 0; i < qntdFuncionarios; i++){
			System.out.print("Nome do Empregado: ");
			nome = entrada();
			while(nome.length() == 0){
					System.out.println("Seu nome nao pode ser vazio. Escreva um nome.");
					System.out.print("Nome do Empregado: ");
					nome = entrada();
			}

			System.out.print("Codigo: ");
			codigo = entrada();
			while(codigo.length() == 0){
				System.out.println("O codigo nao pode ser vazio. Escreva um codigo.");
				System.out.print("Codigo: ");
				codigo = entrada();
			}

			while(!permitido){
				try{
					System.out.print("Salario: ");
					salario = Double.parseDouble(entrada());
					permitido = true;
				}catch(NumberFormatException e){
					System.out.println(e);
					permitido = false;
				}
			}
			permitido = false;
			while(!permitido){
				try{
					System.out.print("Numero de Dependentes: ");
					dependentes = Integer.parseInt(entrada());
					permitido = true;
				}catch(NumberFormatException e){
					System.out.println(e);
					permitido = false;
				}
			}
			permitido = false;

			System.out.println("");
				
			funcContratado[i] = new FuncionarioContratado(nome, codigo, salario, dependentes);
			funcContratado[i].getCalculaSalario(dependentes);
		}

		System.out.println("---- Folha Salarial ----");
		for(int i = 0; i < qntdFuncionarios; i++){
			System.out.print(funcContratado[i].toString());
			System.out.println("-------------------------");
		}
	}

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
		boolean permitido = false;
		int qtdFuncionarios = 0;

		while(!permitido){
			try{
				System.out.println("Digite a quantidade de Funcionarios: ");
				qtdFuncionarios = Integer.parseInt(entrada());
				permitido = true;
			}catch(NumberFormatException e){
				System.out.println(e);
				permitido = false;
			}
		}
		permitido = false;
		Ex4 ex4 = new Ex4(qtdFuncionarios);
		ex4.calculaSalarios();
	}
}