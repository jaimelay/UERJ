package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
)

func doAsyncTask(url string, ch chan<- string) {
	resp, _ := http.Get(url)
	body, _ := ioutil.ReadAll(resp.Body)
	ch <- fmt.Sprintf("3. O tamanho do conteúdo da página %s é de %d caracteres", url, len(body))
}

func doSyncTask() {
	fmt.Println("1. Fazendo alguma tarefa síncrona...")
}

func doSyncTaskWhileAwait() {
	fmt.Println("4. Enquanto a tarefa assíncrona não é terminada, podemos fazer outras tarefas simultaneamente......")
	for i := 1; i <= 3; i++ {
		fmt.Println("Tarefa ", i, " realizada")
	}
}

func main() {
	doSyncTask()
	ch := make(chan string)
	fmt.Println("2. Tarefa assíncrona começou...")
	go doAsyncTask("https://docs.microsoft.com/en-us/dotnet/csharp/csharp", ch)
	doSyncTaskWhileAwait()
	fmt.Println(<-ch)
}

