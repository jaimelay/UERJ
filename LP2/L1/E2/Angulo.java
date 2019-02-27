import java.lang.Math;

public class Angulo {
	private static double converteAng(double graus){
		return Math.toRadians(graus);
	}
	public static double getRad(double graus){
		return converteAng(graus);
	}

	private static double funcaoSen(double ang){
		return Math.sin(ang);
	}
	public static double getSen(double ang){
		return funcaoSen(ang);
	}

	private static double funcaoCos(double ang){
		return Math.cos(ang);
	}
	public static double getCos(double ang){
		return funcaoCos(ang);
	}

	private static double funcaoTan(double ang){
		return Math.tan(ang);
	}
	public static double getTan(double ang){
		return funcaoTan(ang);
	}

	private static double funcaoCotan(double ang){
		return Math.cos(ang)/Math.sin(ang);
	}
	public static double getCotan(double ang){
		return funcaoCotan(ang);
	}
}