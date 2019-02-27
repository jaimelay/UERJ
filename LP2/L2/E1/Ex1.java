import java.io.*;

public class Ex1 {
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
		MinhaListaOrdenavel listaP = new MinhaListaOrdenavel();

		listaP.add(new Homem("Jaime Lay", "25/04/1997", 67.00, 1.63));
		listaP.add(new Homem("Leonardo", "28/02/1997", 67.00, 1.70));
		listaP.add(new Homem("Ricardo", "08/06/1998", 86.00, 1.72));
		listaP.add(new Homem("Lucas", "12/05/1998", 80.00, 1.80));
		listaP.add(new Homem("Gabriel", "05/08/1999", 64.00, 1.75));
		listaP.add(new Homem("Eduardo", "28/04/1999", 55.00, 1.63));
		listaP.add(new Mulher("Mariana", "25/04/1997", 54.00, 1.60));
		listaP.add(new Mulher("Alessandra", "25/04/1997", 62.00, 1.62));
		listaP.add(new Mulher("Leticia", "25/04/1997", 52.00, 1.50));
		listaP.add(new Mulher("Bruna", "25/04/1997", 57.00, 1.55));

		int opcao = 0, opcaoOrd = 0;
		do{
			boolean permitido = true;
			System.out.println("Selecione uma opcao abaixo: ");
			System.out.println("1. Imprimir Lista.");
			System.out.println("2. Sair.");
			System.out.print("Digite sua opcao: ");
			try{
				opcao = Integer.parseInt(entrada());
				permitido = true;
			}catch(NumberFormatException e){
				System.out.println(e);
				permitido = false;
			}
			while((opcao != 1 && opcao != 2) || permitido == false){
				System.out.println("Voce so pode escolher um numero das opcoes abaixo: ");
				System.out.println("1. Imprimir Lista.");
				System.out.println("2. Sair.");
				System.out.print("Digite uma dessas opcao: ");
				try{
					opcao = Integer.parseInt(entrada());
					permitido = true;
				}catch(NumberFormatException e){
					System.out.println(e);
					permitido = false;
				}
			}
			switch(opcao){
				case 1:
					System.out.println("Escolha seu modo de ordenacao");
					System.out.println("1. Alfabetica (A-Z)");
					System.out.println("2. Alfabetica (Z-A)");
					System.out.println("3. Menor Peso");
					System.out.println("4. Maior Peso");
					System.out.println("5. Maior Altura");
					System.out.println("6. Menor IMC");
					System.out.print("Digite sua opcao: ");
					try{
						opcaoOrd = Integer.parseInt(entrada());
						permitido = true;
					}catch(NumberFormatException e){
						System.out.println(e);
						permitido = false;
					}
					while( (opcaoOrd < 1 && opcaoOrd > 5) || permitido == false){
						System.out.println("ATENCAO: As opcoes tem que ser um numero de 1 a 5");
						System.out.println("Escolha seu modo de ordenacao");
						System.out.println("1. Alfabetica (A-Z)");
						System.out.println("2. Alfabetica (Z-A)");
						System.out.println("3. Menor Peso");
						System.out.println("4. Maior Peso");
						System.out.println("5. Maior Altura");
						System.out.println("6. Menor IMC");
						System.out.print("Digite sua opcao novamente: ");
						try{
							opcaoOrd = Integer.parseInt(entrada());
							permitido = true;
						}catch(NumberFormatException e){
							System.out.println(e);
							permitido = false;
						}
					}
					listaP.ordena(opcaoOrd);

					for(int i = 0; i < listaP.getSize(); i++){
						System.out.println(listaP.getArray(i));
					}
				case 2:
					break;
			}
		}while(opcao != 2);

	}
}