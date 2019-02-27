import java.text.DecimalFormat;

public class FuncionarioContratado extends Funcionario {
	private int numDependentes;
	private double salario_familia;
	final double valorPorDep = 9.58;
	final double aliquotaIR = 0.15;

	public FuncionarioContratado(String nome, String codigo, double salario, int numDependentes){
		super(nome, codigo, salario);
		this.numDependentes = numDependentes;
	}

	private void calculaSalario(){
		super.getCalculaSalario(aliquotaIR);
	}
	public void getCalculaSalario(){
		calculaSalario();
	}

	private void calculaSalario(int numDependentes){
		this.salario_familia = this.numDependentes * this.valorPorDep;
		setSalario(getSalario() + salario_familia); 
		calculaSalario();
	}
	public void getCalculaSalario(int numDependentes){
		calculaSalario(numDependentes);
	}

	@Override
	public String toString(){
		DecimalFormat d = new DecimalFormat("#0.00");
		return "Nome: " + getNome() + "\n" +
				"Codigo: " + getCodigo() + "\n" +
				"Salario-Base: " + d.format(getSalario()) + "\n" +
				"Salario-Liquido: " + d.format(getSalarioLiquido()) + "\n";
	}
}