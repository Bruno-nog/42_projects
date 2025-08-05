# Minitalk

Projeto da 42 São Paulo que implementa uma comunicação **entre dois processos via sinais UNIX** (`SIGUSR1` e `SIGUSR2`), sem uso de sockets, pipes ou arquivos.

![nota minitalk](../images/minitalk-125.png)

## 📡 Descrição

O `minitalk` consiste em dois programas:

- **Servidor (`server`)**: aguarda sinais e converte em caracteres.
- **Cliente (`client`)**: envia uma string, bit a bit, usando sinais para o PID do servidor.

Essa comunicação é **assíncrona e baseada em sinais**, simulando uma forma rudimentar de protocolo binário.

---

## 🔧 Funcionamento

### Envio de caracteres

O cliente envia cada caractere bit a bit:

- `SIGUSR1` representa o bit **0**
- `SIGUSR2` representa o bit **1**

Cada sinal é enviado com um `usleep` entre eles, para garantir a leitura correta do lado do servidor.

---

### Servidor

```c
int main(void)
{
	// Exibe o PID e espera sinais para construir a mensagem recebida
}
```

- Exibe seu PID ao iniciar

- Usa sigaction para capturar sinais com SA_SIGINFO

- Ao receber todos os bits de um caractere, imprime-o

- Finaliza a mensagem ao receber \0

## Cliente
```c
int main(int ac, char **av)
{
	// Envia a string passada na linha de comando
}
```

- Espera 2 argumentos: o PID do servidor e a mensagem a enviar

- Valida o PID

- Envia caractere por caractere (incluindo o \0)

## 🛠️ Compilação

Clone e compile com:

```c
git clone https://github.com/Bruno-nog/42_projects.git 42_projects
cd 42_projects/minitalk
make
```

Isso gera dois executáveis: server e client.

## ▶️ Execução

### 1. Rode o servidor em um terminal:

```c
./server

exemplo saída:
Server PID: 12345
```
### 2. Em outro terminal, envie uma mensagem:

```c
./client 12345 "Mensagem secreta"
```
**O número 12345 deve ser substituído pelo PID real exibido pelo servidor.

## 🧼 Observações

- O servidor pode ser interrompido com Ctrl+C (tratado por signal(SIGINT, clean_exit);)

- O client espera uma resposta do server apenas por convenção (\0 como fim da mensagem)

- Nenhuma biblioteca externa é utilizada além da libft e unistd.h, conforme permitido

## 🧪 Testes e Validações

- Envio de mensagens curtas e longas

- Envio de strings com caracteres especiais

- Testes com múltiplos clientes enviando simultaneamente

<br>
Se quiser visualizar logs ou o comportamento dos sinais, use ferramentas como strace.

# English:

# Minitalk

42 São Paulo project that implements communication **between two processes via UNIX signals** (`SIGUSR1` and `SIGUSR2`), without using sockets, pipes, or files.

![minitalk grade](../images/minitalk-125.png)

## 📡 Description

The `minitalk` consists of two programs:

- **Server (`server`)**: waits for signals and converts them to characters.  
- **Client (`client`)**: sends a string, bit by bit, using signals to the server PID.

This communication is **asynchronous and signal-based**, simulating a rudimentary binary protocol.

---

## 🔧 Operation

### Character Sending

The client sends each character bit by bit:

- `SIGUSR1` represents bit **0**  
- `SIGUSR2` represents bit **1**

Each signal is sent with a `usleep` between them to ensure correct reading on the server side.

---

### Server

```c
int main(void)
{
	// Displays the PID and waits for signals to build the received message
}
```

- Displays its PID at startup

- Uses sigaction to capture signals with SA_SIGINFO

- When all bits of a character are received, prints it

- Terminates the message on receiving \0

## Client

```c
int main(int ac, char **av)
{
	// Sends the string passed in the command line
}
```

- Expects 2 arguments: the server PID and the message to send

- Validates the PID

- Sends character by character (including \0)

## 🛠️ Compilation

Clone and compile with:

```c
git clone https://github.com/Bruno-nog/42_projects.git 42_projects
cd 42_projects/minitalk
make

```
This generates two executables: server and client.

## ▶️ Execution

### 1. Run the server in one terminal:

```c
./server

example output:
Server PID: 12345

```

### 2. In another terminal, send a message:

```c
./client 12345 "Secret message"

```

The number 12345 should be replaced by the actual PID displayed by the server.

## 🧼 Notes

- The server can be stopped with Ctrl+C (handled by signal(SIGINT, clean_exit);)

- The client expects a response from the server by convention only (\0 as end of the message)

- No external libraries are used other than libft and unistd.h, as allowed

## 🧪 Tests and Validation

- Sending short and long messages

- Sending strings with special characters

- Tests with multiple clients sending simultaneously

<br> 

If you want to view logs or the behavior of the signals, use tools like `strace`.