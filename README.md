# winexplorer-hidder
## O que é?
É um programa, desenvolvido para sistemas operacionais (OS) Windows.
O program serve para ocultar arquivos e pastas do windows explorer (as pastas do windows).
Foi apelido de Cofre, pois cria um pasta onde todo conteúdo a ser ocultado deve ficar

## O que é necessário pra ultilizar o programa?
Não é necessário nada, o projeto já conta com o executável, basta apenas chamar o executavel e passar o login e a senha e caso deseje, o caminho do cofre

## Como ultilizar?
O programa foi desenvolvido para ser ultilizado via linha de comando, para facilitar o acesso, onde só será necessário passar o caminho do executavel, o login, a senha e o caminho do cofre.
Você também pode adiciona-lo às variáveis de ambiente e acessa-lo de qualquer parte do sistema, sendo assim, não necessitará passar o caminho do cofre, pois a aplicação entenderá que o cofre se encontra na pasta atual.

## Como adicionar variaveis de ambiente
[Tutorial de variáveis de ambiente Windows](https://docs.microsoft.com/pt-br/windows-server/administration/windows-commands/setx#:~:text=O%20comando%20setx%20tamb%C3%A9m%20recupera,grava%20em%20arquivos%20de%20texto.&text=O%20comando%20set%20%2C%20que%20%C3%A9,a%20janela%20de%20console%20atual.)

## Comandos para executar projeto
run.bat login senha caminho_coffer

Após adicionado ao PATH:
Coffer login senha caminho_coffer
ou
Coffer login senha

## Para DEVs
Caso queira, a aplicação permite que altere o código e recompile-o. Foi disponibilizado um arquivo em lotes para a compilação, que também pode ser alterado conforme a necessidade
