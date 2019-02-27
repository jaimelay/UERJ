import java.io.*;

public class Ex3 {
	public static void main(String[] args){
		BufferedReader inData = new BufferedReader(new InputStreamReader(System.in));
		boolean permitido = false;
		int qtdAngulos = 0;
		while(!permitido){
			try{
				System.out.print("Digite o numero de angulos: ");
				qtdAngulos = Integer.parseInt(inData.readLine());
				permitido = true;
			}catch(NumberFormatException e1){
				System.out.println(e1);
			}catch(IOException e2){
				System.out.println(e2);
			}
		}
		if(permitido){
			AnguloObj[] objetos = new AnguloObj[qtdAngulos];
			permitido = false;
			for(int i = 0; i < qtdAngulos; i++){
				while(!permitido){
					try{
						System.out.printf("Digite a medida do %dº angulo: ", i + 1);
						double angulo = Double.parseDouble(inData.readLine());
						objetos[i] = new AnguloObj(angulo);
						permitido = true;
					}catch(NumberFormatException e1){
						System.out.println(e1);
					}catch(IOException e2){
						System.out.println(e2);
					}
				}
				if(i == qtdAngulos - 1) permitido = true;
				else permitido = false;
			}
			if(permitido){
				System.out.println("Resultado: ");
				for(int i = 0; i < objetos.length; i++){
					System.out.println(objetos[i].toString());
				}
			}
		}
	}
}