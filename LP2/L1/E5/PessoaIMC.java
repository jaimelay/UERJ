public abstract class PessoaIMC extends Pessoa{
	private double peso;
	private double altura;

	public PessoaIMC(String nome, String dataNasc, double peso, double altura){
		super(nome, dataNasc);
		this.peso = peso;
		this.altura = altura;
	}

	public double getPeso(){
		return peso;
	}

	public double getAltura(){
		return altura;
	}

	protected double calculaIMC(double altura, double peso){
		return peso/Math.pow(altura, 2);
	}

	protected abstract String resultIMC();

	@Override
	public String toString(){
		String s = "Peso: " + this.peso + "\n";
		String s2 = "Altura: " + this.altura + "\n";
		return super.toString() + s + s2 + resultIMC();
	}
}