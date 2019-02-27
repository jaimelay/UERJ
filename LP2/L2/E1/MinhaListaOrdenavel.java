import java.util.*;

public class MinhaListaOrdenavel{

	private ArrayList<PessoaIMC> listaP = new ArrayList<PessoaIMC>();

	protected void add(PessoaIMC p){
		listaP.add(p);
	}

	public PessoaIMC getArray(int i){
		return (PessoaIMC) listaP.get(i);
	}

	public int getSize(){
		return listaP.size();
	}

	public Comparator<Object> nomeC = new Comparator<Object>(){
		public int compare(Object obj1, Object obj2){
			String p1, p2;
			PessoaIMC objTmp1 = (PessoaIMC) obj1;
			PessoaIMC objTmp2 = (PessoaIMC) obj2;
			p1 = objTmp1.getNome();
			p2 = objTmp2.getNome();
			return (int)Math.round(p1.compareTo(p2));
		}
	};

	public Comparator<Object> pesoC = new Comparator<Object>(){
		public int compare(Object obj1, Object obj2){
			double p1, p2;
			PessoaIMC objTmp1 = (PessoaIMC) obj1;
			PessoaIMC objTmp2 = (PessoaIMC) obj2;
			p1 = objTmp1.getPeso();
			p2 = objTmp2.getPeso();
			return (int)Math.round(p2 - p1);
		}
	};

	public Comparator<Object> alturaC = new Comparator<Object>(){
		public int compare(Object obj1, Object obj2){
			double p1, p2;
			PessoaIMC objTmp1 = (PessoaIMC) obj1;
			PessoaIMC objTmp2 = (PessoaIMC) obj2;
			p1 = objTmp1.getAltura();
			p2 = objTmp2.getAltura();
			return (int)Math.floor(p2 - p1);
		}
	};

	public Comparator<Object> imcC = new Comparator<Object>(){
		public int compare(Object obj1, Object obj2){
			double p1, p2;
			PessoaIMC objTmp1 = (PessoaIMC) obj1;
			PessoaIMC objTmp2 = (PessoaIMC) obj2;
			p1 = objTmp1.getIMC();
			p2 = objTmp2.getIMC();
			return (int)Math.round(p2 - p1);
		}
	};

	// public Comparator generoC = new Comparator(){
	// 	public int compare(Object obj1, Object obj2){
	// 		return 0;
	// 	}
	// };

	public ArrayList<PessoaIMC> ordena(int opcao){
		switch(opcao){
			case 1:
				Collections.sort(listaP, nomeC);
				break;
			case 2:
				Collections.sort(listaP, nomeC.reversed());
				break;
			case 3:
				Collections.sort(listaP, pesoC.reversed());
				break;
			case 4:
				Collections.sort(listaP, pesoC);
				break;
			case 5:
				Collections.sort(listaP, alturaC);
				break;
			case 6:
			 	Collections.sort(listaP, imcC);
			 	break;
			// case 7:
			// 	Collections.sort(listaP, generoC);
			// 	break;
		}
		return this.listaP;
	}
}