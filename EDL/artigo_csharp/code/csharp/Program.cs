using System;
using System.Net.Http;
using System.Threading.Tasks;

namespace codigos{
    class Program{
        private const string URL = "https://docs.microsoft.com/en-us/dotnet/csharp/csharp";
        static void Main(string[] args){
            doSyncTask();
            var someTaskAsync = doAsyncTask();
            doSyncTaskWhileAwait();
            someTaskAsync.Wait(); // Isso é uma "blocking call", faz com que o bloco não termine até a Tarefa ser realizada.
        }
        static void doSyncTask(){ Console.WriteLine("1. Fazendo alguma tarefa síncrona..."); } 
        static async Task doAsyncTask(){
            Console.WriteLine("2. Tarefa assíncrona começou...");
            await getTotalSizeOfContent();
        }
        static async Task getTotalSizeOfContent(){
            using (var httpClient = new HttpClient()){
                string result = await httpClient.GetStringAsync(URL); // execução para aqui até o GetStringAsync finalizar
                // Apartir dessas linhas abaixo, a execução só irá acontecer após o término da requisição
                Console.WriteLine($"3. O tamanho do conteúdo da página {URL} é de {result.Length} caracteres");
            }
        }
        static void doSyncTaskWhileAwait(){
            Console.WriteLine("4. Enquanto a tarefa assíncrona não é terminada, podemos fazer outras tarefas simultaneamente...");
            for (var i = 1; i <= 3; i++)
                Console.WriteLine($"Tarefa {i} realizada");
        }
    }
}


