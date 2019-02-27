public class Mulher extends PessoaIMC{
	public Mulher(String nome, String dataNasc, double peso, double altura){
		super(nome, dataNasc, peso, altura);
	}

	protected String resultIMC(){
		String s, strIMC;
		double IMC = calculaIMC(getAltura(), getPeso());
		strIMC = String.format("IMC: %.2f ", IMC);
		if(IMC < 19){
			s = "Abaixo do peso ideal\n";
		}else if(IMC >= 19 && IMC <= 25.8){
			s = "Peso ideal\n";
		}else{
			s = "Acima do peso ideal\n";
		}
		return strIMC + s;
	}
}