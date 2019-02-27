import java.io.*;

public class Ex1 {
	public static void main(String[] args){
		double[] vet = new double[3];
		boolean permitido = true;

		if(args.length == 0){
			System.out.println("Numero de argumentos insuficiente");
		}else if(args.length > 3){
			System.out.println("Numero de argumentos excessivos.");
		}else{
			for(int i = 0; i < args.length; i++){
				try{
					if(Double.parseDouble(args[i]) <= 0){
						System.out.println("Nao e permitido o uso de numeros nulos ou negativos.");
						permitido = false;
						break;
					}else{
						vet[i] = Double.parseDouble(args[i]);
					}
				}catch(NumberFormatException e){
					System.out.println(e);
					permitido = false;
				}
			}

			if(permitido){
				if(args.length == 1){
					System.out.printf("A area do circulo e: %.2f unidades de area.\n", Calcula.getCalcula(vet[0]));
				}else if(args.length == 2){
					System.out.printf("A area do retangulo e: %.2f unidades de area.\n", Calcula.getCalcula(vet[0], vet[1]));
				}else if(args.length == 3){
					if( (Math.abs(vet[1] - vet[2]) < vet[0] && vet[0] < vet[1] + vet[2]) && (Math.abs(vet[0] - vet[2]) < vet[1] && vet[1] < vet[0] + vet[2]) && (Math.abs(vet[0] - vet[1]) < vet[2] && vet[2] < vet[0] + vet[1])){
						System.out.printf("A area do triangulo e: %.2f unidades de area.\n", Calcula.getCalcula(vet[0], vet[1], vet[2]));
						System.out.println(Calcula.getTipoTriang(vet[0], vet[1], vet[2]));
					}else{
						System.out.println("As medidas nao formaram um triangulo.");
					}
				}
			}
		}

	}
}