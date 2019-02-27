/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lp2g13.biblioteca;

import java.io.Serializable;
import java.util.Calendar;
import java.util.GregorianCalendar;

/**
 *
 * @author Jaime
 */
public class EmprestadoPara implements Serializable{
    protected GregorianCalendar dataEmprestimo;
    protected GregorianCalendar dataDevolucao;
    protected int codigoUsuario;

    public EmprestadoPara(GregorianCalendar dataEmprestimo, GregorianCalendar dataDevolucao, int codigoUsuario){
        this.dataEmprestimo = dataEmprestimo;
        this.dataDevolucao = dataDevolucao;
        this.codigoUsuario = codigoUsuario;
    }
    
    @Override
    public String toString(){
        return String.format("Codigo do Usuario: " + codigoUsuario + "\n"
                + "Data de Emprestimo: " + dataEmprestimo.get(Calendar.DATE) + "\\" + dataEmprestimo.get(Calendar.MONTH) + "\\" + dataEmprestimo.get(Calendar.YEAR) + "\n"
                + "Data de Devolucao: " + dataDevolucao.get(Calendar.DATE) + "\\" + dataDevolucao.get(Calendar.MONTH) + "\\" + dataDevolucao.get(Calendar.YEAR) + "\n");
    }
}