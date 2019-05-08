# Intro
Este projeto consiste na implementação de um biblioteca que contém as funções: `min`, `reverse`, `copy`, `clone`, `find_if`, `find`, `all_of`, `any_of`, `none_of`, `equal`, `unique`, `partition` e `sort`. A biblioteca, IntRangelib.a, pode ser vinculada a qualquer aplicativo que precise usar as funções definidas nela.

A implementação da biblioteca explora conceitos abordados da discplina de Linguagem de Programação I, ministrada pelo professor [Selan Rodrigues](https://docente.ufrn.br/2497950/perfil).

# Compiling
Para compilar a biblioteca basta seguir os seguintes passos:

# Parte 1: Compilando a Biblioteca

1. `mkdir build`: isso cria um novo diretório no qual a saída da compilação será armazenada, incluindo o executável.
2. `cd build`: apenas se move para o diretório criado na etapa acima.
3. `cmake -G "Unix Makefiles" ..`: pede ao cmake para criar o Makefile baseado no script encontrado `CMakeLists.txt`, um nível acima.
4. `cmake --build .`: aciona o processo de compilação.
5. `make install`: copia a biblioteca para o diretório `lib`.

## Executando os testes

Basta executar no terminal:

```
$ ./build/run_tests
```