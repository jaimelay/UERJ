/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lp2g13.biblioteca;

import java.io.Serializable;
import java.util.GregorianCalendar;
import java.util.Calendar;

/**
 *
 * @author Jaime
 */
public class Pessoa implements Serializable{
    final String nome;
    final GregorianCalendar dataNasc;
    
    public Pessoa(String nome, int dia, int mes, int ano){
        this.nome = nome;
        this.dataNasc = new GregorianCalendar(ano, mes, dia);
    }
    
    public String getNome(){
        return nome;
    }
    
    public GregorianCalendar getDataNasc(){
        return dataNasc;
    }
    
    @Override
    public String toString(){
        return String.format("Nome: " + nome + "\n"
                + "Data de Nascimento: " + dataNasc.get(Calendar.DATE) + "\\" + dataNasc.get(Calendar.MONTH) + "\\" + dataNasc.get(Calendar.YEAR));
    }
}
