/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lp2g13.exception;

/**
 *
 * @author Jaime
 */
public class CopiaNaoDisponivelEx extends Exception {
    public CopiaNaoDisponivelEx(){
        super("Todas copias foram emprestadas.");
    }
}
