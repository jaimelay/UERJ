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
public class LivroNaoCadastradoEx extends Exception {
    public LivroNaoCadastradoEx(){
        super("Este livro nao esta cadastrado.");
    }
}
