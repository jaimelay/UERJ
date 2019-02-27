package lp2g13.biblioteca;

import java.io.Serializable;
import java.util.Calendar;
import java.util.GregorianCalendar;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Jaime
 */
public class Emprestimo implements Serializable{
    protected GregorianCalendar dataEmprestimo;
    protected GregorianCalendar dataDevolucao;
    protected String codigoLivro;
    
    public Emprestimo(GregorianCalendar dataEmpr, GregorianCalendar dataDev, String codigoLivro){
        this.dataEmprestimo = dataEmpr;
        this.dataDevolucao = dataDev;
        this.codigoLivro = codigoLivro;
    }
    
    @Override
    public String toString(){
        return String.format("Codigo do Livro: " + codigoLivro + "\n"
                + "Data de Emprestimo: " + dataEmprestimo.get(Calendar.DATE) + "\\" + dataEmprestimo.get(Calendar.MONTH) + "\\" + dataEmprestimo.get(Calendar.YEAR) + "\n"
                + "Data de Devolucao: " + dataDevolucao.get(Calendar.DATE) + "\\" + dataDevolucao.get(Calendar.MONTH) + "\\" + dataDevolucao.get(Calendar.YEAR) + "\n");
    }
}
