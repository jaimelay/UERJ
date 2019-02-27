public class Pessoa {
	private String nome;
	private String dataNasc;


	public Pessoa(String nome, String dataNasc){
		this.nome = nome;
		this.dataNasc = dataNasc;
	}

	@Override
	public String toString(){
		String s = "Nome: " + nome + "\n";
		String s2 = "Data de Nascimento: " + dataNasc + "\n";
		return s + s2;
	}

}