/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lp2g13.biblioteca;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.GregorianCalendar;

/**
 *
 * @author Jaime
 */
public class Usuario extends Pessoa implements Serializable{
    protected String endereco;
    protected int codigoUsuario;
    protected int qntdLivro = 0;
    protected ArrayList<Emprestimo> historico;
    
    public Usuario(String nome, int dia, int mes, int ano, String endereco, int codigoUsuario){
        super(nome, dia, mes, ano);
        this.endereco = endereco;
        this.codigoUsuario = codigoUsuario;
        historico = new ArrayList<Emprestimo>();
    }
    
    public void addLivroHist(GregorianCalendar dataLoc, GregorianCalendar dataDev, String codigoLivro){
        historico.add(new Emprestimo(dataLoc, dataDev, codigoLivro));
    }
    
    public String getEndereco(){
        return endereco;
    }
    
    public int getCodigoUsuario(){
        return codigoUsuario;
    }
    
    public void emprestimos(){
        if(qntdLivro == 3){
            System.out.println("Voce ja pegou o maximo de livros emprestados.");
        }else{
            qntdLivro++; 
        }
    }
    
    public void devolucao(){
        if(qntdLivro == 0){
            System.out.println("Esse usuario nao tem nenhum livro emprestado.");
        }else{
            qntdLivro--;
        }
    }
    
    public GregorianCalendar getDataDev(int i){
        return historico.get(i).dataDevolucao;
    }
    
    public int getIndexLivHist(String codigoLivro){
        for(int i = 0; i < historico.size(); i++){
            Emprestimo tmpEmprest = (Emprestimo) historico.get(i);
            if(tmpEmprest.codigoLivro.equals(codigoLivro)){
                return i;
            }
        }
        return -1;
    }
    
    public void removIndexLivHist(int i){
        historico.set(i, null);
    }
    
    public String imprimeHistorico(){
        String strHistorico = "- Historico -\n";
        for(int i = 0; i < historico.size(); i++){
            strHistorico += historico.get(i) + "\n";
        }
        return strHistorico;
    }
    
    @Override
    public String toString(){
        return String.format("Nome: " + nome + "\n"
                + "Data de Nascimento: " + getDataNasc().get(Calendar.DATE) + "\\" + getDataNasc().get(Calendar.MONTH) + "\\" + getDataNasc().get(Calendar.YEAR) + "\n"
                + "Endereco: " + endereco + "\n"
                + "Codigo do Usuario: " + codigoUsuario + "\n"
                + "Quantidade de Livros: " + qntdLivro + "\n"
                + imprimeHistorico() + "\n");
    }
}
