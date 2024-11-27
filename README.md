# Data Master

## ??? Grupo
Bruno Brand�o
Gustavo Prado
Gabriel Henrique Vieira
Matheus Bidin

## ? Documenta��o

### Introdu��o

O DataMaster � um sistema em C para gerenciamento de registros, desenvolvido com o objetivo de aplicar conceitos avan�ados de estruturas de dados, como listas din�micas, �rvores bin�rias e listas duplamente ligadas. Este projeto interdisciplinar do 3� semestre visa integrar teoria e pr�tica, criando uma ferramenta funcional e did�tica.

O documento descreve os requisitos funcionais e n�o funcionais, diagramas UML, guia de usu�rio e tecnologias utilizadas, al�m de destacar os desafios enfrentados e as solu��es adotadas.

### Vis�o do Produto

Para estudantes e desenvolvedores que t�m a necessidade de aprender e implementar conceitos de estruturas de dados, o DataMaster � um sistema de cadastro que oferece armazenamento eficiente, consultas r�pidas e manipula��o de registros utilizando lista din�mica, �rvore bin�ria e lista duplamente ligada. Diferentemente de outros exemplos b�sicos de estruturas de dados, o DataMaster tem integra��o de m�ltiplas estruturas avan�adas, exemplos pr�ticos e implementa��o modular em linguagem c, facilitando o aprendizado e o uso did�tico. 

### Requisitos Funcionais

| ID | Story Points | Prioridade | T�tulo | Descri��o                                                                                        | Crit�rio de Aceita��o                                                         |
|----|--------------|------------|--------|--------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------|
| 1  | 100          | Alta       |  Cadastrar Registro        | Como administrador, quero cadastrar um novo registro para inclu�-lo no sistema. | Informar nome, CPF e idade; o sistema deve validar o CPF antes de salvar.     |
| 2  | 80           | Alta       |  Buscar Registro          | Como usu�rio, quero buscar um registro pelo CPF para verificar suas informa��es.                                                                                                   | Inserir CPF; o sistema deve retornar os dados completos.                      |
| 3  | 80           | Alta       |  Excluir Registro         | Como administrador, quero excluir um registro para manter os dados atualizados.                                                                                                   | Inserir CPF; o sistema deve remover os dados correspondentes.                 |
| 4  | 40           | M�dia      | Gerar Relat�rio  | Como administrador, quero gerar um relat�rio de registros ordenados por nome. | O relat�rio deve ser gerado em ordem alfab�tica. | 
| 5  | 50           | M�dia      |  Atualizar Registro          | Como administrador, quero atualizar os dados de um registro existente.                                                                                                 | O relat�rio deve ser gerado em ordem alfab�tica.                              |
| 6  | 80           | Alta       |  Valida��o de CPF         | Como usu�rio, quero que o sistema valide os CPFs para evitar duplicidade ou registros inv�lidos.                                                                                                  | Inserir CPF, editar dados espec�ficos e confirmar altera��es.                 |
| 7  | 100          | Alta       |  Persist�ncia de Dados          | Como administrador, quero que o sistema salve os registros em arquivos para garantir persist�ncia mesmo ap�s o encerramento do programa.                                                                                                  | O sistema deve verificar a unicidade e formato v�lido do CPF antes de salvar. |
| 8  | 40           | M�dia      |  Interface Intuitiva          | Como usu�rio, quero que o sistema apresente mensagens claras e menus intuitivos.                                                                                                  | Registros salvos em arquivos bin�rios ou texto, recuper�veis ao reiniciar o programa.                                                                               |
| 9  | 90           | Alta       |  Ordena��o de Registros          | Como administrador, quero que os registros sejam ordenados automaticamente para facilitar consultas e gera��o de relat�rios.                                                                                                  |  Mensagens e menus devem orientar o usu�rio nas opera��es dispon�veis.   |
| 10 | 40           | Baixa      |  Compatibilidade          | Como desenvolvedor, quero que o sistema seja compat�vel com diferentes sistemas operacionais (Windows, Linux, macOS) e compiladores, como GCC e MSVC.                                                                                                  | Registros na lista duplamente ligada devem permanecer em ordem alfab�tica ap�s inser��es ou altera��es.  |

### Requisitos N�o Funcionais

- Desempenho:

  - Busca por CPF em tempo O(log n) com �rvore bin�ria.

  - Inser��o, busca e remo��o em listas din�micas em O(n).

  - Relat�rios gerados em O(n) com lista duplamente ligada.

- Confiabilidade: Valida��o de entradas e integridade dos dados.

- Persist�ncia: Dados armazenados em arquivos locais.

- Portabilidade: Compat�vel com Windows, Linux e macOS.

### Diagrama de Casos de Uso

Representa as intera��es do administrador para cadastrar, buscar, excluir registros e gerar relat�rios.

![Diagrama de Casos de Uso](Imagens/casos_uso.png)

### Diagrama de Atividades

Fluxo detalhado das opera��es principais do sistema, incluindo:

![Diagrama de Atividades 1](Imagens/atividades_1.png)
![Diagrama de Atividades 2](Imagens/atividades_2.png)

1. Menu inicial com sele��o de op��es.

2. Opera��es dispon�veis: Cadastro, Busca, Exclus�o, Relat�rios.

3. Decis�es baseadas nos inputs do usu�rio.

4. O Fluxo termina no menu ou na finaliza��o do programa.

### Modelagem de Classe

   | Classe         | Atributos                  | Opera��es                |
   |----------------|----------------------------|--------------------------|
   | Registro       | Nome, CPF, Telefone        | Cadastrar, Atualizar     |  
   | Lista Din�mica | Ponteiro para in�cio / Fim | Inserir, Remover, Buscar | 
   | �rvore Bin�ria | Ponteiro para Ra�z         | Inserir, Remover, Buscar | 

### Guia do usu�rio

Instru��es Passo a Passo:

    1. Cadastrar Registro:
        - Escolha "Cadastrar"
        - Insira os dados solicitados(nome, CPF, idade)
    2. Buscar Registro:
        - Insira o CPF para consulta
    3. Excluir Registro:
        - Insira o CPF do registro a ser removido.
    4. Gerar Relat�rio:
        - O sistema exibe a lista ordenada ou salva o arquivo.

Tecnologias Utilizadas

    - Linguagem: C((Padr�o C11 ou posterior).
    - Compiladores: GCC (Linux) e MSVC (Windows).
    - Ferramentas: CLion, Linux Terminal. 

Problemas e Solu��es:

    1. Integra��o de Estruturas:
        - Desafio: Conectar lista din�mica, �rvore bin�ria e lista duplamente ligada.
        - Solu��o: Modulariza��o e testes incrementais.
    2. Persist�ncia de Dados:
        - Desafio: Armazenar e recuperar grandes volumes de dados. 
        - Solu��o: Uso de arquivos bin�rios para maior efici�ncia.

### Conclus�o

O desenvolvimento do DataMaster possibilitou aplicar estruturas de dados avan�adas e explorar conceitos fundamentais como modularidade e escalabilidade. Futuras melhorias podem incluir uma interface gr�fica e integra��o com banco de dados para maior robustez. 

                                                                           

