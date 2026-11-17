# 🐾 PetControl — Sistema de Gerenciamento de Pet Shop

![Linguagem](https://img.shields.io/badge/Linguagem-C-blue)
![Categoria](https://img.shields.io/badge/Categoria-Projeto%20Acad%C3%AAmico-green)
![Interface](https://img.shields.io/badge/Interface-Terminal-lightgrey)

## 📖 Sobre o projeto

O **PetControl** é um sistema de gerenciamento de pet shop e clínica veterinária, desenvolvido em linguagem C como projeto acadêmico da disciplina de Lógica de Programação.

O objetivo é aplicar conceitos fundamentais de programação na construção de uma aplicação funcional, utilizando estruturas de dados, vetores, matrizes, funções, condicionais, laços de repetição e ponteiros.

O sistema permite gerenciar tutores, animais e atendimentos, além de realizar consultas e gerar relatórios financeiros durante sua execução.

## 👥 Equipe de Desenvolvimento

| Nº | Nome completo | Matrícula |
|:---:|---|:---:|
| 1 | Robert Guelber Frazão Souza | UC26200486 |
| 2 | Gabrieli Rodrigues Moreira | UC26200273 |
| 3 | Stevam Pereira da Silva | UC26200280 |
| 4 | Miguel Solano Meirelles | UC26200274 |

## 🎯 Objetivos

- Aplicar conceitos de lógica de programação em linguagem C.
- Desenvolver um sistema modular utilizando funções.
- Organizar registros por meio de estruturas (`struct`).
- Utilizar vetores e matrizes para armazenar e consultar informações.
- Implementar validações e buscas sequenciais.
- Aplicar ponteiros para manipulação de dados.
- Gerar relatórios com base nos atendimentos registrados.

## ⚙️ Funcionalidades

O sistema disponibiliza um menu interativo com as seguintes operações:

| Opção | Funcionalidade | Descrição |
|---|---|---|
| 1 | Cadastrar tutor | Registra código, nome e telefone |
| 2 | Cadastrar animal | Registra dados do animal e vincula um tutor |
| 3 | Listar cadastros | Exibe tutores e animais cadastrados |
| 4 | Buscar registro | Localiza tutor ou animal pelo código |
| 5 | Registrar atendimento | Seleciona um serviço e calcula seu valor |
| 6 | Alterar cadastro | Permite modificar o nome de um tutor |
| 7 | Relatório financeiro | Exibe atendimentos e faturamento por serviço |
| 0 | Sair | Encerra a execução do programa |

## 📋 Requisitos funcionais

Os requisitos funcionais representam as operações que o sistema deve realizar.

| Código | Requisito | Descrição |
|---|---|---|
| RF01 | Cadastro de tutores | Permitir cadastrar tutores com código, nome e telefone |
| RF02 | Cadastro de animais | Permitir cadastrar animais vinculados a tutores existentes |
| RF03 | Listagem de registros | Exibir os tutores e animais cadastrados |
| RF04 | Consulta de registros | Permitir buscar tutores e animais por código |
| RF05 | Registro de atendimentos | Registrar serviços prestados a animais cadastrados |
| RF06 | Cálculo de valores | Calcular o valor do atendimento conforme serviço e quantidade |
| RF07 | Alteração de cadastro | Permitir modificar o nome de um tutor existente |
| RF08 | Relatórios financeiros | Exibir a quantidade de atendimentos e o faturamento total e por serviço |
| RF09 | Menu interativo | Disponibilizar navegação entre as funcionalidades |
| RF10 | Validação de dados | Impedir determinados registros inválidos ou duplicados |

## 🛠️ Requisitos técnicos e não funcionais

| Código | Requisito | Especificação |
|---|---|---|
| RNF01 | Linguagem | Implementação em C |
| RNF02 | Interface | Interação por terminal, com entrada e saída textual |
| RNF03 | Compilação | Compilador C compatível com os recursos utilizados |
| RNF04 | Armazenamento | Vetores estáticos em memória RAM |
| RNF05 | Modularidade | Funcionalidades organizadas em funções |
| RNF06 | Dependências | Utilização das bibliotecas padrão `stdio.h` e `string.h` |
| RNF07 | Persistência | Os registros não são mantidos após o encerramento |
| RNF08 | Capacidade | Limites fixos de registros definidos por constantes |

## 🧩 Estruturas de dados

O PetControl utiliza três estruturas personalizadas por meio de `typedef struct`.

### Tutor

Armazena as informações dos responsáveis pelos animais.

| Campo | Tipo | Descrição |
|---|---|---|
| `codigo` | `int` | Identificador do tutor |
| `nome[100]` | `char` | Nome completo |
| `telefone[30]` | `char` | Telefone de contato |

### Animal

Armazena as informações dos animais cadastrados.

| Campo | Tipo | Descrição |
|---|---|---|
| `codigo` | `int` | Identificador do animal |
| `nome[100]` | `char` | Nome do animal |
| `especie[40]` | `char` | Espécie |
| `idade` | `int` | Idade em anos |
| `codigoTutor` | `int` | Código do tutor responsável |

### Atendimento

Armazena os dados dos serviços realizados.

| Campo | Tipo | Descrição |
|---|---|---|
| `codigoAnimal` | `int` | Código do animal atendido |
| `codigoServico` | `int` | Identificador do serviço |
| `quantidade` | `int` | Quantidade registrada |
| `valorTotal` | `float` | Valor total do atendimento |

### Capacidade de armazenamento

O sistema utiliza constantes definidas com `#define`.

| Registro | Capacidade máxima |
|---|---:|
| Tutores | 30 |
| Animais | 50 |
| Atendimentos | 100 |

Os registros são armazenados em vetores estáticos, enquanto variáveis contadoras controlam a quantidade efetivamente cadastrada.

## 💰 Catálogo de serviços

O sistema possui quatro serviços previamente definidos.

| Código | Serviço | Valor unitário |
|---|---|---:|
| 1 | Banho | R$ 35,00 |
| 2 | Tosa | R$ 45,00 |
| 3 | Consulta veterinária | R$ 80,00 |
| 4 | Vacinação fictícia | R$ 60,00 |

Os nomes são armazenados em uma matriz de caracteres `nomesServicos[4][30]`, enquanto os valores são armazenados no vetor `precosServicos[4]`.

A correspondência entre nomes e preços ocorre por meio dos índices dos vetores.

**Cálculo do atendimento:**

`valorTotal = precoUnitario * quantidade`

Os serviços de banho e tosa permitem informar quantidades entre 1 e 100. Consulta e vacinação são registradas com quantidade igual a 1.

## 🔒 Regras de negócio e validações

O PetControl implementa as seguintes regras:

**RN01 — Identificação dos registros**

Os códigos de tutores e animais devem ser números inteiros positivos e não podem estar duplicados dentro de seus respectivos cadastros.

**RN02 — Vinculação entre tutor e animal**

Um animal somente poderá ser cadastrado se o código do tutor responsável já existir.

**RN03 — Campos obrigatórios**

Os campos de nome e telefone do tutor, além de nome e espécie do animal, não podem estar vazios.

**RN04 — Validação de idade**

A idade do animal deve estar entre 0 e 100 anos.

**RN05 — Registro de atendimentos**

Somente animais previamente cadastrados podem receber atendimentos.

**RN06 — Serviços disponíveis**

O usuário deve selecionar um serviço entre as opções 1 e 4.

**RN07 — Controle de capacidade**

O sistema impede novos cadastros quando os respectivos vetores atingem sua capacidade máxima.

**RN08 — Relatórios financeiros**

O faturamento é calculado com base nos atendimentos registrados durante a execução atual do programa.

## 🧠 Conceitos de programação aplicados

| Conceito | Aplicação |
|---|---|
| `#define` | Definição dos limites de armazenamento |
| `typedef struct` | Criação de tipos personalizados |
| Vetores | Armazenamento dos registros |
| Matrizes de caracteres | Armazenamento dos nomes dos serviços |
| `for` | Percorrer registros e realizar buscas |
| `while` | Limpeza de caracteres restantes na entrada |
| `do while` | Repetição do menu principal |
| `if / else` | Validações e decisões |
| `switch / case` | Seleção das funcionalidades |
| Funções | Modularização do programa |
| Ponteiros | Alteração direta dos dados de um tutor |
| `fgets()` | Leitura de textos com espaços |
| `strlen()` | Verificação do comprimento de strings |
| `strcpy()` | Cópia de strings |
| `strcspn()` | Localização da quebra de linha na entrada |

## 🏗️ Organização do código

O projeto está implementado no arquivo principal `petcontrol.c`.

As funcionalidades são organizadas nas seguintes funções:

| Função | Responsabilidade |
|---|---|
| `limparEntrada()` | Limpar caracteres restantes da entrada |
| `lerTexto()` | Ler textos e remover a quebra de linha |
| `buscarTutor()` | Localizar tutor pelo código |
| `buscarAnimal()` | Localizar animal pelo código |
| `cadastrarTutor()` | Cadastrar novos tutores |
| `cadastrarAnimal()` | Cadastrar novos animais |
| `listarCadastros()` | Listar tutores e animais |
| `buscarRegistro()` | Consultar registros |
| `registrarAtendimento()` | Registrar serviços realizados |
| `alterarTutor()` | Alterar o nome de um tutor por ponteiro |
| `alterarCadastro()` | Localizar o tutor e solicitar a alteração |
| `relatorio()` | Gerar relatório financeiro |
| `mostrarMenu()` | Exibir as opções disponíveis |
| `main()` | Controlar o fluxo principal do programa |

## 💻 Requisitos para execução

Para compilar e executar o PetControl, é necessário:

- Um computador com Windows, Linux ou macOS.
- Um compilador C, como GCC.
- Um terminal ou ambiente de desenvolvimento compatível.

Não são necessários banco de dados, servidor ou bibliotecas externas.

### Compilação

No terminal, acesse a pasta que contém `petcontrol.c` e execute:

```bash
gcc petcontrol.c -o petcontrol
```

### Execução no Windows

```bash
.\petcontrol.exe
```

### Execução no Linux ou macOS

```bash
./petcontrol
```

Após iniciar, o programa apresentará o menu interativo.

## ⚠️ Limitações da versão atual

O PetControl é um projeto acadêmico e possui algumas limitações:

- Não utiliza banco de dados.
- Os registros são perdidos ao encerrar o programa.
- A capacidade dos vetores é fixa.
- Não possui interface gráfica.
- O catálogo de serviços é definido diretamente no código.
- A alteração de cadastro permite modificar apenas o nome do tutor.
- Não possui autenticação de usuários.
- A validação de entradas é básica.
- Os valores financeiros são armazenados utilizando o tipo `float`.

## 🚀 Possíveis melhorias futuras

As seguintes funcionalidades são propostas para futuras versões e **não estão implementadas atualmente**:

- Persistência dos registros em arquivos ou banco de dados.
- Cadastro de novos serviços e atualização de preços.
- Edição completa dos dados de tutores e animais.
- Exclusão de cadastros.
- Histórico de atendimentos por animal.
- Relatórios por período.
- Interface gráfica.
- Melhorias nas validações e no tratamento de entradas.

## 🤝 Colaboração e apresentação

O repositório também é utilizado para compartilhamento do código e organização da apresentação acadêmica.

A divisão das responsabilidades e as orientações para os integrantes estão disponíveis no documento:

**[PRESENTATION.md](PRESENTATION.md)**

---

**PetControl — Projeto acadêmico desenvolvido em linguagem C.**
