/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lp2g13.biblioteca;

import java.io.*;
import java.util.Calendar;
import java.util.Hashtable;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.GregorianCalendar;
import lp2g13.exception.*;
/**
 *
 * @author Jaime
 */
public class Biblioteca implements Serializable{
    private Hashtable usuarios;
    private Hashtable livros;

    public Biblioteca(){
        usuarios = new Hashtable();
        livros = new Hashtable();
    }

    public Biblioteca(String arqUsuario, String arqLivros){
        try{
            ObjectInputStream inputStream1 = new ObjectInputStream(new FileInputStream(arqUsuario));
            ObjectInputStream inputStream2 = new ObjectInputStream(new FileInputStream(arqLivros));
            usuarios = (Hashtable)inputStream1.readObject();
            livros = (Hashtable)inputStream2.readObject();
            inputStream1.close();
            inputStream2.close();
        }catch(FileNotFoundException e){
            System.out.println(e);
        }catch(IOException e){
            System.out.println(e);
        }catch(ClassNotFoundException e){
            System.out.println(e);
        }
    }

    public void cadastraUsuario(Usuario user){
        usuarios.put(user.codigoUsuario, user);
    }

    public void cadastraLivro(Livro book){
        livros.put(book.codigoLivro, book);
    }

    public void salvaArquivo(Hashtable objHash, String arquivo){
        try{
            ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream(arquivo));
            outputStream.writeObject(objHash);
            outputStream.flush();
            outputStream.close();
        }catch(FileNotFoundException e){
            System.out.println(e);
        }catch(IOException e){
            System.out.println(e);
        }
    }

    public void leArquivo(String arquivo){
        try{
            ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream(arquivo));
            Hashtable hashTmp = (Hashtable)inputStream.readObject();
            System.out.println(hashTmp);
            inputStream.close();
        }catch(FileNotFoundException e){
            System.out.println(e);
        }catch(IOException e){
            System.out.println(e);
        }catch(ClassNotFoundException e){
            System.out.println(e);
        }
    }
    
    public void emprestaLivro(Usuario usuario, Livro livro) throws CopiaNaoDisponivelEx{
        livro.empresta();
        usuario.emprestimos();
        GregorianCalendar dataAtual = new GregorianCalendar();
        GregorianCalendar dataDev = new GregorianCalendar();
        dataDev.add(Calendar.DATE, 7);
        usuario.addLivroHist(dataAtual, dataDev, livro.getCodigoLivro());
        livro.addUsuarioHist(dataAtual, dataDev, usuario.getCodigoUsuario());
    }
    
    public void devolveLivro(Usuario usuario, Livro livro) throws NenhumaCopiaEmprestadaEx{
        int index1 = usuario.getIndexLivHist(livro.getCodigoLivro());
        int index2 = livro.getIndexUsuHist(usuario.getCodigoUsuario());
        GregorianCalendar dataAtual = new GregorianCalendar();
        //if(dataAtual != usuario.getDataDev(index1) && dataAtual != livro.getDataDevPara(index2)){
        //    System.out.println("Voce esta com atraso na entrega do livro.");
        //}
        livro.devolve();
        usuario.devolucao();
        livro.removIndexUsuHist(index2);
        usuario.removIndexLivHist(index1);
    }
    
    public String imprimeLivros(){
        if(livros.isEmpty()){
            System.out.println("Nao ha nenhum livro na hash.");
        }
        return livros.toString();
    }
    
    public String imprimeUsuarios(){
        if(usuarios.isEmpty()){
            System.out.println("Nao ha nenhum usuario na hash.");
        }
        return usuarios.toString();
    }
    
    public Livro getLivro(String codigoLivro) throws LivroNaoCadastradoEx{
        Livro livro = (Livro) livros.get(codigoLivro);
        if(livro == null){
            throw new LivroNaoCadastradoEx();
        }
        return livro;
    }
    
    public Usuario getUsuario(int codigoUsuario) throws UsuarioNaoCadastradoEx{
        Usuario usuario = (Usuario) usuarios.get(codigoUsuario);
        if(usuario == null){
            throw new UsuarioNaoCadastradoEx();
        }
        return usuario;
    }
    
    public Hashtable getUsuarioHash(){
        return usuarios;
    }
    
    public Hashtable getLivroHash(){
        return livros;
    }
}
