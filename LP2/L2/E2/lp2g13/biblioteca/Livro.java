/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lp2g13.biblioteca;

import java.io.Serializable;
import lp2g13.exception.*;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.GregorianCalendar;
/**
 *
 * @author Jaime
 */
public class Livro implements Serializable{
    protected String codigoLivro;
    protected String tituloLivro;
    protected String categoriaLivro;
    protected int qntdLivro;
    protected int emprestadosLivro;
    protected ArrayList<EmprestadoPara> historico;

    public Livro(String codigoLivro, String tituloLivro, String categoriaLivro, int qntdLivro, int emprestadosLivro){
        this.codigoLivro = codigoLivro;
        this.tituloLivro = tituloLivro;
        this.categoriaLivro = categoriaLivro;
        this.qntdLivro = qntdLivro;
        this.emprestadosLivro = emprestadosLivro;
        historico = new ArrayList<EmprestadoPara>();
    }

    public Livro(String tituloLivro){
        this.tituloLivro = tituloLivro;
    }

    public void empresta() throws CopiaNaoDisponivelEx{
        if(qntdLivro - emprestadosLivro < 0){
            throw new CopiaNaoDisponivelEx();
        }else{
            emprestadosLivro++;
        }
    }

    public void devolve() throws NenhumaCopiaEmprestadaEx{
        if(emprestadosLivro == 0){
            throw new NenhumaCopiaEmprestadaEx();
        }else{
            emprestadosLivro--;
        }
    }

    public void addUsuarioHist(GregorianCalendar dataLocacao, GregorianCalendar dataDevolucao, int codigoUsuario){
        historico.add(new EmprestadoPara(dataLocacao, dataDevolucao, codigoUsuario));
    }

    public int getIndexUsuHist(int codigoUsuario){
        for (int i = 0; i < historico.size(); i++) {
            EmprestadoPara tmpEmpPara = (EmprestadoPara) historico.get(i);
            if(tmpEmpPara.codigoUsuario == codigoUsuario){
                return i;
            }
        }
        return -1;
    }
        
    public void removIndexUsuHist(int i){
        historico.set(i, null);
    }
        
    public GregorianCalendar getDataDevPara(int i){
        return historico.get(i).dataDevolucao;
    }
        
    public String getCodigoLivro(){
        return codigoLivro;
    }
    
    public String getTituloLivro(){
        return tituloLivro;
    }
    
    public String getCategoriaLivro(){
        return categoriaLivro;
    }
    
    public int getQntdLivro(){
        return qntdLivro;
    }
    
    public int getEmprestadosLivro(){
        return emprestadosLivro;
    }

    public String imprimeHistoricoLiv(){
        String strHistorico = "- Historico -\n";
        for(int i = 0; i < historico.size(); i++){
            strHistorico += historico.get(i) + "\n";
        }
        return strHistorico;
    }
        
    @Override
    public String toString(){
        return String.format("Codigo do Livro: " + codigoLivro + "\n"
                + "Titulo do Livro: " + tituloLivro + "\n"
                + "Categoria do Livro: " + categoriaLivro + "\n"
                + "Quantidade de Livros: " + qntdLivro + "\n"
                + "Quantidade de Livros Emprestados: " + emprestadosLivro + "\n"
                + imprimeHistoricoLiv() + "\n");
    }
}