@ECHO OFF
set CLASSPATH=./lp2g13/biblioteca/Biblioteca.java; ./lp2g13/biblioteca/EmprestadoPara.java; ./lp2g13/biblioteca/Emprestimo.java; ./lp2g13/biblioteca/Livro.java; ./lp2g13/biblioteca/Pessoa.java; ./lp2g13/biblioteca/Usuario.java; ./lp2g13/exception/CopiaNaoDisponivelEx.java; ./lp2g13/exception/LivroNaoCadastradoEx.java; ./lp2g13/exception/NenhumaCopiaEmprestadaEx.java; ./lp2g13/exception/UsuarioNaoCadastradoEx.java;
javac *java
java Ex2
pause
