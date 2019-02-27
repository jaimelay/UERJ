import java.io.*;
import java.text.DecimalFormat;

public class Ex2 {
	private static DecimalFormat d = new DecimalFormat("#0.00");
	private static BufferedReader dataFile = new BufferedReader(new InputStreamReader(System.in));
	private static String line;

	private static void imprime(double graus){
		System.out.println("Seno: " + d.format(Angulo.getSen(graus)));
		System.out.println("Cosseno: " + d.format(Angulo.getCos(graus)));
		System.out.println("Tangente: " + d.format(Angulo.getTan(graus)));
		System.out.println("Cotangente: " + d.format(Angulo.getCotan(graus)));
		System.out.println("");	
	}

	private static String entrada(){
		try{
			line = dataFile.readLine();
		}catch(IOException e){
			System.out.println(e);
		}
		return line;
	}
	public static void main(String[] args){
		double graus = 0, graus2 = 0;
		boolean permitido = true;
		if(args.length > 1){
			System.out.println("So e permitido a entrada de um unico argumento por vez.");
		}else if(args.length == 0){
			System.out.println("E necessario que tenha um argumento.");
		}else{
			try{
				graus = Double.parseDouble(args[0]);
			}catch(NumberFormatException e1){
				System.out.println(e1);
				permitido = false;
			}
			if(permitido){
				graus = Angulo.getRad(graus);
				imprime(graus);
				System.out.print("Digite uma medida em graus do angulo: ");
				entrada();
				while(line.length() != 0){
					try{
						graus2 = Double.parseDouble(line);
					}catch(NumberFormatException e1){
						System.out.println(e1);
						permitido = false;
					}
					graus2 = Angulo.getRad(graus2);
					if(permitido) imprime(graus2);
					System.out.print("Digite uma medida em graus do angulo: ");
					entrada();
					permitido = true;
				}
			}
		}
	}
}