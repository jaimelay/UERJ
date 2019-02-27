import java.lang.Math;

public class Calcula {
	private static double calcula(double r){
		return Math.PI * (r * r);
	}
	public static double getCalcula(double r){
		return calcula(r);
	}

	private static double calcula(double b, double a){
		return b * a;
	}
	public static double getCalcula(double b, double a){
		return calcula(b, a);
	}

	private static double calcula(double l1, double l2, double l3){
		double p = (l1 + l2 + l3)/2;
		return Math.sqrt(p * (p - l1) * (p - l2) * (p - l3));
	}
	public static double getCalcula(double l1, double l2, double l3){
		return calcula(l1, l2, l3);
	}

	private static String tipoTriang(double l1, double l2, double l3){
		if((l1 == l2) && (l1 == l3) && (l2 == l3)){
			return "O triangulo e equilatero.";
		}else if((l1 == l2) || (l1 == l3) || (l2 == l3)){
			return "O triangulo e isosceles.";
		}else{
			return "O triangulo e escaleno.";
		}
	}
	public static String getTipoTriang(double l1, double l2, double l3){
		return tipoTriang(l1, l2, l3);
	}

}