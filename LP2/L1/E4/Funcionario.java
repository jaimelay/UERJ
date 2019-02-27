import java.text.DecimalFormat;

public class Funcionario {
	private String nome, codigo;
	private double salario, salario_liquido;

	public Funcionario(String nome, String codigo, double salario) {
		this.nome = nome;
		this.codigo = codigo;
		this.salario = salario;
		this.salario_liquido = salario;
	}

	private double calculaSalario(double desconto){
		return salario_liquido = salario - (desconto * salario);
	}
	public double getCalculaSalario(double desconto){
		return calculaSalario(desconto);
	}

	public String getNome(){
		return this.nome;
	}
	public String getCodigo(){
		return this.codigo;
	}
	public double getSalario(){
		return this.salario;
	}
	public void setSalario(double salario){
		this.salario = salario;
	}
	public void setSalarioLiquido(double salarioLiquido){
		this.salario_liquido = salarioLiquido;
	}
	public double getSalarioLiquido(){
		return this.salario_liquido;
	}

	public String toString(){
		DecimalFormat d = new DecimalFormat("#0.00");
		return "Nome: " + getNome() + "\n" +
				"Codigo: " + getCodigo() + "\n" +
				"Salario-Base: " + d.format(getSalario()) + " " + "\n";
	}
}