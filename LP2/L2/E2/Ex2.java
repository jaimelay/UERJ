/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import lp2g13.biblioteca.*;
import lp2g13.exception.*;
import java.io.*;

/**
 *
 * @author Jaime
 */
public class Ex2 {
    private static Biblioteca biblioteca = new Biblioteca();
    
    public static boolean isDouble(String str){
        try{
            Double.parseDouble(str);
            return true;
        }catch(NumberFormatException e){
            return false;
        }  
    }
    
    public static boolean isInteger(String str){
        try{
            Integer.parseInt(str);
            return true;
        }catch(NumberFormatException e){
            return false;
        }  
    }
    
    public static boolean hasUser(int codigoUsuario){
        try{
            biblioteca.getUsuario(codigoUsuario);
            return true;
        }catch(UsuarioNaoCadastradoEx e){
            return false;
        }
    }
    
    public static boolean hasBook(String codigoLivro){
        try{
            biblioteca.getLivro(codigoLivro);
            return true;
        }catch(LivroNaoCadastradoEx e){
            return false;
        }
    }
    
    public static void manutencao(String arq1, String arq2){
        try{
            FileInputStream inputStream1 = new FileInputStream(arq1);
            FileInputStream inputStream2 = new FileInputStream(arq2);
            biblioteca = new Biblioteca(arq1, arq2);
        }catch(FileNotFoundException e){
            System.out.println(e);
        }
    }

    public static void cadastro()throws IOException, InterruptedException{
        BufferedReader inData = new BufferedReader(new InputStreamReader(System.in));
        String input, nome, endereco, strDiaNasc, strMesNasc, strAnoNasc, strCodigoUsuario;
        String codigoLivro, tituloLivro, categoriaLivro, strQntdLivro, strEmprestados;
        String strOpSalvar, arqUsuario, arqLivro;
        int op = 10;
        do{
            clearConsole();
            System.out.println("======= Sessao de Cadastros =======");
            System.out.println("1 - Cadastrar Usuario.");
            System.out.println("2 - Cadastrar Livro.");
            System.out.println("3 - Salvar em Arquivo.");
            System.out.println("0 - Voltar.");
            System.out.print("Digite sua opcao: ");
            input = inData.readLine();
            while(!isInteger(input)){
                System.out.println("=========== Sessao de Cadastros ===========");
                System.out.println("1 - Cadastrar Usuario.");
                System.out.println("2 - Cadastrar Livro.");
                System.out.println("3 - Salvar em Arquivo.");
                System.out.println("0 - Voltar.");
                System.out.print("Digite sua opcao: ");
                input = inData.readLine();
            }
            op = Integer.parseInt(input);
            switch(op){
                default:
                    break;
                case 0:
                    break;
                case 1:
                    clearConsole();
                    System.out.println("======= Cadastramento de Usuario =======");
                    System.out.print("Digite o nome: ");
                    nome = inData.readLine();
                    System.out.println("- Digite a data de nascimento -");
                    int diaNasc = 0;
                    do{
                        System.out.print("Digite o dia: ");
                        strDiaNasc = inData.readLine();
                        while(!isInteger(strDiaNasc)){
                            System.out.print("O dia que voce digitou nao e valido, digite novamente: ");
                            strDiaNasc = inData.readLine();
                        }
                        diaNasc = Integer.parseInt(strDiaNasc);
                        if(diaNasc <= 0 || diaNasc > 31){
                            System.out.println("O dia tem que ser entre 1 e 31.");
                        }
                    }while(diaNasc <= 0 || diaNasc > 31);

                    int mesNasc = 0;
                    do{
                        System.out.print("Digite o mes: ");
                        strMesNasc = inData.readLine();
                        while(!isInteger(strMesNasc)){
                            System.out.print("O mes que voce digitou nao e valido, digite novamente: ");
                            strMesNasc = inData.readLine();
                        }
                        mesNasc = Integer.parseInt(strMesNasc);
                        if(mesNasc <= 0 || mesNasc > 12){
                            System.out.println("O mes tem que ser entre 1 e 12.");
                        }
                    }while(mesNasc <= 0 || mesNasc > 12);

                    int anoNasc = 0;
                    do{
                        System.out.print("Digite o ano: ");
                        strAnoNasc = inData.readLine();
                        while(!isInteger(strAnoNasc)){
                            System.out.print("O ano que voce digitou nao e valido, digite novamente: ");
                            strAnoNasc = inData.readLine();
                        }
                        anoNasc = Integer.parseInt(strAnoNasc);
                        if(anoNasc < 1900 || anoNasc > 2019){
                            System.out.println("O ano tem que ser entre 1900 e 2019.");
                        }
                    }while(anoNasc < 1900 || anoNasc > 2019);

                    System.out.println("--");
                    System.out.print("Digite o endereco: ");
                    endereco = inData.readLine();

                    boolean hasUsuario = true;
                    int codigoUsuario;
                    do{
                        System.out.print("Digite o codigo do usuario: ");
                        strCodigoUsuario = inData.readLine();
                        while(!isInteger(strCodigoUsuario)){
                            System.out.print("O codigo do usuario nao e valido, digite novamente: ");
                            strCodigoUsuario = inData.readLine();
                        }
                        codigoUsuario = Integer.parseInt(strCodigoUsuario);   
                        if(!hasUser(codigoUsuario)) hasUsuario = false;
                        if(hasUser(codigoUsuario)) System.out.println("Este codigo ja esta sendo utilizado.");
                    }while(hasUsuario);
                    Usuario usuario = new Usuario(nome, diaNasc, mesNasc, anoNasc, endereco, codigoUsuario);
                    biblioteca.cadastraUsuario(usuario);
                    System.out.println("Cadastro de Usuario Realizado com Sucesso!!");
                    System.out.print("Voltando ao menu em 3 segundos.");
                    Thread.sleep(3000);
                    break;
                case 2:
                    clearConsole();
                    System.out.println("======== Cadastramento de Livro ========");
                    boolean hasLivro = true;
                    do{
                        System.out.print("Digite o codigo do livro: ");
                        codigoLivro = inData.readLine();
                        if(!hasBook(codigoLivro)) hasLivro = false;
                        if(hasBook(codigoLivro)) System.out.println("Este codigo ja esta sendo utilizado.");
                    }while(hasLivro);

                    System.out.print("Digite o titulo do livro: ");
                    tituloLivro = inData.readLine();
                    System.out.print("Digite a categoria do livro: ");
                    categoriaLivro = inData.readLine();
                    
                    int qntdLivro = 0;
                    do{
                        System.out.print("Digite a quantidade de copias do livro: ");
                        strQntdLivro = inData.readLine();
                        while(!isInteger(strQntdLivro)){
                            System.out.print("Invalido!! Digite novamente a quantidade de copias do livro: ");
                            strQntdLivro = inData.readLine();
                        }
                        qntdLivro = Integer.parseInt(strQntdLivro);
                        if(qntdLivro < 0){
                            System.out.println("A quantidade de livros nao pode ser menor que 0.");
                        }
                    }while(qntdLivro < 0);
                    
                    int qntdEmprestado = 0;
                    do{
                        System.out.print("Digite a quantidade de livros para emprestar: ");
                        strEmprestados = inData.readLine();
                        while(!isInteger(strEmprestados)){
                            System.out.print("Invalido!! Digite novamente a quantidade de livros para emprestar: ");
                            strEmprestados = inData.readLine();
                        }
                        qntdEmprestado = Integer.parseInt(strEmprestados);
                        if(qntdEmprestado < 0 || qntdEmprestado > qntdLivro){
                            System.out.println("A quantidade de livros tem que ser entre 0 e " + qntdLivro);
                        }
                    }while(qntdEmprestado > qntdLivro || qntdEmprestado < 0);

                    Livro livro = new Livro(codigoLivro, tituloLivro, categoriaLivro, qntdLivro, qntdEmprestado);
                    biblioteca.cadastraLivro(livro);
                    System.out.println("Cadastrado de Livro Realizado com Sucesso!!");
                    System.out.print("Voltando ao menu em 3 segundos.");
                    Thread.sleep(3000);
                    break;
                case 3:
                    clearConsole();
                    System.out.println("=========== Salvar em Arquivo ===========");
                    System.out.println("1 - Salvar o cadastro de Usuarios.");
                    System.out.println("2 - Salvar o cadastro de Livros.");
                    System.out.println("0 - Sair.");
                    System.out.print("Digite sua opcao: ");
                    strOpSalvar = inData.readLine();
                    while(!isInteger(strOpSalvar)){
                        System.out.println("1 - Salvar o cadastro de Usuarios.");
                        System.out.println("2 - Salvar o cadastro de Livros.");
                        System.out.println("0 - Sair.");
                        System.out.print("Digite sua opcao: ");
                        strOpSalvar = inData.readLine();
                    }
                    int opSalvar = Integer.parseInt(strOpSalvar);
                    switch(opSalvar){
                        case 1:
                            System.out.print("Digite o nome do arquivo de usuarios: ");
                            arqUsuario = inData.readLine();
                            biblioteca.salvaArquivo(biblioteca.getUsuarioHash(), arqUsuario);
                            System.out.println("Cadastro de Usuarios Salvo com Sucesso!!");
                            System.out.print("Voltando ao menu em 3 segundos.");
                            Thread.sleep(3000);
                            break;
                        case 2:
                            System.out.print("Digite o nome do arquivo de livros: ");
                            arqLivro = inData.readLine();
                            biblioteca.salvaArquivo(biblioteca.getLivroHash(), arqLivro);
                            System.out.println("Cadastro de Livros Salvo com Sucesso!!");
                            System.out.print("Voltando ao menu em 3 segundos.");
                            Thread.sleep(3000);
                            break;
                        case 0:
                            break; 
                        default:
                            break;
                    }
                    break;
            }
        }while(op != 0);
    }
    
    public static void emprestimo()throws IOException, InterruptedException{
        BufferedReader inData = new BufferedReader(new InputStreamReader(System.in));
        String strOp;
        int op = 10;
        do{
            clearConsole();
            System.out.println("======== Sessao de Emprestimos ========");
            System.out.println("1 - Exibir o cadastro de livros.");
            System.out.println("2 - Fazer um emprestimo.");
            System.out.println("3 - Fazer uma devolucao.");
            System.out.println("0 - Voltar.");
            System.out.print("Digite sua opcao: ");
            strOp = inData.readLine();
            while(!isInteger(strOp)){
                System.out.println("======== Sessao de Emprestimos ========");
                System.out.println("1 - Exibir o cadastro de livros.");
                System.out.println("2 - Fazer um emprestimo.");
                System.out.println("3 - Fazer uma devolucao.");
                System.out.println("0 - Voltar.");
                System.out.print("Digite sua opcao: ");
                strOp = inData.readLine();
            }
            op = Integer.parseInt(strOp);
            switch(op){
                case 1:
                    String opc;
                    clearConsole();
                    System.out.println("======== Sessao de Cadastros ========");
                    System.out.println(biblioteca.imprimeLivros());
                    System.out.print("Caso queira voltar aperte qualquer tecla");
                    opc = inData.readLine();
                    break;
                case 2:
                    clearConsole();
                    System.out.println("======== Sessao de Emprestimos ========");
                    int codigoUsuario, cont = 0, cont2 = 0;
                    String strCodigoUsuario, strCodigoLivro;
                    boolean hasUsuario = false;
                    boolean hasBook = false;
                    do{
                        System.out.print("Digite o codigo do usuario: ");
                        strCodigoUsuario = inData.readLine();
                        while(!isInteger(strCodigoUsuario)){
                            System.out.print("Invalido!! Digite novamente o codigo do usuario: ");
                            strCodigoUsuario = inData.readLine();
                        }
                        codigoUsuario = Integer.parseInt(strCodigoUsuario);
                        if(hasUser(codigoUsuario)){
                            hasUsuario = true;
                        }else{
                            System.out.println("Nao ha cadastro de usuario com este codigo.");
                        }
                        cont++;
                        if(cont == 3){
                            System.out.println("Voce passou do numero de tentativas, tente novamente depois.");
                            System.out.print("Voltando ao menu em 3 segundos.");
                            Thread.sleep(3000);
                            break;
                        }
                    }while(!hasUsuario);
                    
                    if(cont != 3){
                        do{
                            System.out.print("Digite o codigo do livro: ");
                            strCodigoLivro = inData.readLine();
                            if(hasBook(strCodigoLivro)){
                                hasBook = true;
                            }else{
                                System.out.println("Nao ha cadastro de livro com este codigo.");
                            }
                            cont2++;
                            if(cont2 == 3){
                                System.out.println("Voce passou do numero de tentativas, tente novamente depois.");
                                System.out.print("Voltando ao menu em 3 segundos.");
                                Thread.sleep(3000);
                                break;
                            }
                        }while(!hasBook);
                        
                        if(cont2 != 3){
                            Usuario tmpUser = null;
                            try{
                                tmpUser = (Usuario) biblioteca.getUsuario(codigoUsuario);
                            }catch(UsuarioNaoCadastradoEx e){
                                System.out.println(e);
                            }
                            
                            Livro tmpBook = null;
                            try{
                                tmpBook = (Livro) biblioteca.getLivro(strCodigoLivro);
                            }catch (LivroNaoCadastradoEx e){
                                System.out.println(e);
                            }

                            try{
                                biblioteca.emprestaLivro(tmpUser, tmpBook);
                                System.out.println("Emprestimo realizado com Sucesso!!");
                                System.out.print("Voltando ao menu em 3 segundos.");
                                Thread.sleep(3000);
                            }catch(CopiaNaoDisponivelEx e){
                                System.out.println(e);
                            }
                        }else{
                            break;
                        }
                    }else{
                        break;
                    }
                    break;
                case 3:
                    clearConsole();
                    int codigoUsuario2, cont3 = 0, cont4 = 0;
                    String strCodigoUsuario2, strCodigoLivro2;
                    boolean hasUsuario2 = false;
                    boolean hasBook2 = false;
                    System.out.println("======== Sessao de Devolucao ========");
                    do{
                        System.out.print("Digite o codigo do usuario: ");
                        strCodigoUsuario2 = inData.readLine();
                        while(!isInteger(strCodigoUsuario2)){
                            System.out.print("Invalido!! Digite novamente o codigo do usuario: ");
                            strCodigoUsuario2 = inData.readLine();
                        }
                        codigoUsuario2 = Integer.parseInt(strCodigoUsuario2);
                        if(hasUser(codigoUsuario2)){
                            hasUsuario2 = true;
                        }else{
                            System.out.println("Nao ha cadastro de usuario com este codigo.");
                        }
                        cont3++;
                        if(cont3 == 3){
                            System.out.println("Voce passou do numero de tentativas, tente novamente depois.");
                            System.out.print("Voltando ao menu em 3 segundos.");
                            Thread.sleep(3000);
                            break;
                        }
                    }while(!hasUsuario2);
                    
                    if(cont3 != 3){
                        do{
                            System.out.print("Digite o codigo do livro: ");
                            strCodigoLivro2 = inData.readLine();
                            if(hasBook(strCodigoLivro2)){
                                hasBook2 = true;
                            }else{
                                System.out.println("Nao ha cadastro de livro com este codigo.");
                            }
                            cont4++;
                            if(cont4 == 3){
                                System.out.println("Voce passou do numero de tentativas, tente novamente depois.");
                                System.out.print("Voltando ao menu em 3 segundos.");
                                Thread.sleep(3000);
                                break;
                            }
                        }while(!hasBook2);
                        
                        if(cont4 != 3){
                            Usuario tmpUser2 = null;
                            try{
                                tmpUser2 = (Usuario) biblioteca.getUsuario(codigoUsuario2);
                            }catch(UsuarioNaoCadastradoEx e){
                                System.out.println(e);
                            }
                            
                            Livro tmpBook2 = null;
                            try{
                                tmpBook2 = (Livro) biblioteca.getLivro(strCodigoLivro2);
                            }catch(LivroNaoCadastradoEx e){
                                System.out.println(e);
                            }

                            try {
                                biblioteca.devolveLivro(tmpUser2, tmpBook2);
                                System.out.println("Devolucao realizado com Sucesso!!");
                                System.out.print("Voltando ao menu em 3 segundos.");
                                Thread.sleep(3000);
                            }catch(NenhumaCopiaEmprestadaEx e){
                                System.out.println(e);
                            }
                        }else{
                            break;
                        }
                    }else{
                        break;
                    }
                    break;
                case 0:
                    break;
                default:
                    break;
            }
        }while(op != 0);

    }
    
    public static void relatorio() throws IOException, InterruptedException{
        BufferedReader inData = new BufferedReader(new InputStreamReader(System.in));
        String strOp, limpa;
        int op = 10;
        do{
            clearConsole();
            System.out.println("======== Relatorio ========");
            System.out.println("1 - Acervo de Livros.");
            System.out.println("2 - Cadastros dos Usuarios.");
            System.out.println("3 - Detalhes de um usuario especifico.");
            System.out.println("4 - Detalhes de um livro especifico.");
            System.out.println("0 - Voltar.");
            System.out.print("Digite sua opcao: ");
            strOp = inData.readLine();
            while(!isInteger(strOp)){
                System.out.println("======== Relatorio ========");
                System.out.println("1 - Acervo de Livros.");
                System.out.println("2 - Cadastros dos Usuarios.");
                System.out.println("3 - Detalhes de um usuario especifico.");
                System.out.println("4 - Detalhes de um livro especifico.");
                System.out.println("0 - Voltar.");
                System.out.print("Digite sua opcao: ");
                strOp = inData.readLine();
            }
            op = Integer.parseInt(strOp);
            switch(op){
                case 1:
                    clearConsole();
                    System.out.println("======== Acervo de Livros ========");
                    System.out.println(biblioteca.getLivroHash());
                    System.out.print("Caso queira voltar aperte qualquer tecla");
                    limpa = inData.readLine();
                    break;
                case 2:
                    clearConsole();
                    System.out.println("======== Cadastros dos Usuarios ========");
                    System.out.println(biblioteca.getUsuarioHash());
                    System.out.print("Caso queira voltar aperte qualquer tecla");
                    limpa = inData.readLine();
                    break;
                case 3:
                    clearConsole();
                    String strCodigoUsuario;
                    int codigoUsuario;
                    int cont = 0;
                    boolean hasUsuario = false;
                    System.out.println("======== Detalhes de um Usuario ========");
                    do{
                        System.out.print("Digite o codigo do usuario que voce deseja se informar: ");
                        strCodigoUsuario = inData.readLine();
                        while(!isInteger(strCodigoUsuario)){
                            System.out.print("Invalido!! Digite novamente o codigo do usuario: ");
                            strCodigoUsuario = inData.readLine();
                        }
                        codigoUsuario = Integer.parseInt(strCodigoUsuario);
                        if(hasUser(codigoUsuario)){
                            hasUsuario = true;
                        }else{
                            System.out.println("Nao ha cadastro de usuario com este codigo.");
                        }
                        cont++;
                        if(cont == 3){
                            System.out.println("Voce passou do numero de tentativas, tente novamente depois.");
                            System.out.print("Voltando ao menu em 3 segundos.");
                            Thread.sleep(3000);
                            break;
                        }
                    }while(!hasUsuario);
                    if(cont != 3){
                        try{
                            Usuario tmpUser = (Usuario) biblioteca.getUsuario(codigoUsuario);
                            System.out.println(tmpUser.toString());
                            System.out.print("Caso queira voltar aperte qualquer tecla");
                            limpa = inData.readLine();
                        }catch(UsuarioNaoCadastradoEx e){
                            System.out.println(e);
                        }
                    }else{
                        break;
                    }
                    break;  
                case 4:
                    clearConsole();
                    String strCodigoLivro;
                    int cont2 = 0;
                    boolean hasLivro = false;
                    System.out.println("======== Detalhes de um Livro ========");
                    do{
                        System.out.print("Digite o codigo do livro que voce deseja se informar: ");
                        strCodigoLivro = inData.readLine();
                        if(hasBook(strCodigoLivro)){
                            hasLivro = true;
                        }else{
                            System.out.println("Nao ha cadastro de livro com este codigo.");
                        }
                        cont2++;
                        if(cont2 == 3){
                            System.out.println("Voce passou do numero de tentativas, tente novamente depois.");
                            System.out.print("Voltando ao menu em 3 segundos.");
                            Thread.sleep(3000);
                            break;
                        }
                    }while(!hasLivro);
                    if(cont2 != 3){
                        try{
                            Livro tmpLivro = (Livro) biblioteca.getLivro(strCodigoLivro);
                            System.out.println(tmpLivro.toString());
                            System.out.print("Caso queira voltar aperte qualquer tecla");
                            limpa = inData.readLine();
                        }catch(LivroNaoCadastradoEx e){
                            System.out.println(e);
                        }
                    }else{
                        break;
                    }
                    break;
                case 0:
                    break;
                default:
                    break;
            }
        }while(op != 0);
    }
    
    public final static void clearConsole(){
        try{
            final String os = System.getProperty("os.name");
            if(os.contains("Windows")){
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            }else{
                Runtime.getRuntime().exec("clear");
            }
        }catch (final InterruptedException | IOException e){
            System.out.println(e);
        }
    }
    
    public static void loading() throws InterruptedException{
        clearConsole();
        Thread.sleep(1000);
        System.out.println("Carregando: [                                    ]");
        Thread.sleep(1000);
        clearConsole();
        System.out.println("Carregando: [====                                ]");
        Thread.sleep(1000);
        clearConsole();
        System.out.println("Carregando: [===========                         ]");
        Thread.sleep(1000);
        clearConsole();
        System.out.println("Carregando: [======================              ]");
        Thread.sleep(1000);
        clearConsole();
        System.out.println("Carregando: [===========================         ]");
        Thread.sleep(1000);
        clearConsole();
        System.out.println("Carregando: [====================================]");
        Thread.sleep(1000);
        clearConsole();
    }
    
    public static void main(String[] args)throws IOException, InterruptedException{
        BufferedReader inData = new BufferedReader(new InputStreamReader(System.in));
        String strOp, arqUsuarios, arqLivros;
        int op = 10;
        loading();
        do{
            clearConsole();
            System.out.println("========= Bem-Vindo(a) ao Menu =========");
            System.out.println("1 - Manutencao.");
            System.out.println("2 - Cadastro.");
            System.out.println("3 - Emprestimo.");
            System.out.println("4 - Relatorio.");
            System.out.println("0 - Sair.");
            System.out.print("Digite sua opcao: ");
            strOp = inData.readLine();
            while(!isInteger(strOp)){
                System.out.println("========= Bem-Vindo(a) ao Menu =========");
                System.out.println("1 - Manutencao.");
                System.out.println("2 - Cadastro.");
                System.out.println("3 - Emprestimo.");
                System.out.println("4 - Relatorio.");
                System.out.println("0 - Sair.");
                System.out.print("Digite sua opcao: ");
                strOp = inData.readLine();
            }
            op = Integer.parseInt(strOp);
            switch(op){
                case 1:
                    clearConsole();
                    System.out.println("========= Manutencao =========");
                    System.out.print("Digite o nome do arquivo para carregar os cadastros de usuarios: ");
                    arqUsuarios = inData.readLine();
                    System.out.print("Digite o nome do arquivo para carregar os cadastros de livros: ");
                    arqLivros = inData.readLine();
                    manutencao(arqUsuarios, arqLivros);
                    break;
                case 2:
                    clearConsole();
                    cadastro();
                    break;
                case 3:
                    clearConsole();
                    emprestimo();
                    break;
                case 4:
                    clearConsole();
                    relatorio();
                    break;
                case 0:
                    break;
            }
        }while(op != 0);

    }
}
