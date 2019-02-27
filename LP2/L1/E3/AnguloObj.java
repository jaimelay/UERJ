import java.lang.Math;
import java.text.DecimalFormat;

public class AnguloObj {
	private double arcoRad;

	public AnguloObj(double anguloGraus){
		this.arcoRad = converteAngulo(anguloGraus);
	}

	public double getArcoRad(){
		return arcoRad;
	}

	private double converteAngulo(double arcoRad){
		return Math.toRadians(arcoRad);
	}

	private double funcSen(){
		return Math.sin(arcoRad);
	}

	private double funcCos(){
		return Math.cos(arcoRad);
	}

	private double funcTan(){
		return Math.tan(arcoRad);
	}

	private double funcCotan(){
		return 1/Math.tan(arcoRad);
	}

	@Override
	public String toString(){
		DecimalFormat d = new DecimalFormat("#0.00");
		return "Arco: " + d.format(getArcoRad()) + " rad\n" +
			 	"Seno: " + d.format(funcSen()) + "\n" +
			 	"Cosseno: " + d.format(funcCos()) + "\n" +
			 	"Tangente: " + d.format(funcTan()) + "\n" +
			 	"Cotangente: " + d.format(funcCotan()) + " " + "\n";
	}
}