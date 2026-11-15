# 🎤 Roteiro de Apresentação — Robert Guelber Frazão Souza

**Projeto:** PetControl — Sistema de Gerenciamento de Pet Shop  
**Matrícula:** 26200486  
**Linguagem:** C

---

## 📋 Conteúdos sob minha responsabilidade

1. Constantes — `#define`
2. Estruturas de dados — `typedef struct`
3. Vetores e armazenamento
4. Contadores de registros
5. Catálogo de serviços e preços
6. `case 3` — Listagem de cadastros

---

## 1. Constantes — `#define`

### Trecho do código

```c
#define MAX_TUTORES 30
#define MAX_ANIMAIS 50
#define MAX_ATENDIMENTOS 100
```

### Explicação técnica

A diretiva `#define` é utilizada para definir macros que serão processadas pelo pré-processador antes da compilação.

No PetControl, essas macros representam os limites máximos de registros que o programa pode armazenar.

- `MAX_TUTORES`: capacidade de 30 tutores.
- `MAX_ANIMAIS`: capacidade de 50 animais.
- `MAX_ATENDIMENTOS`: capacidade de 100 atendimentos.

Esses valores são utilizados na declaração dos vetores e nas validações de capacidade.

### Sugestão de fala

> Inicialmente, utilizamos a diretiva `#define` para estabelecer os limites de armazenamento do sistema. Definimos uma capacidade máxima de 30 tutores, 50 animais e 100 atendimentos. Dessa maneira, conseguimos reutilizar esses valores em diferentes partes do programa, sem precisar escrever os números repetidamente.

### Ponto importante

`#define` não cria uma variável. Ele define uma macro que, neste caso, representa um valor fixo utilizado durante a compilação.

---

## 2. Estruturas de dados — `typedef struct`

### Trecho do código

```c
typedef struct {
    int codigo;
    char nome[100];
    char telefone[30];
} Tutor;

typedef struct {
    int codigo;
    char nome[100];
    char especie[40];
    int idade;
    int codigoTutor;
} Animal;

typedef struct {
    int codigoAnimal;
    int codigoServico;
    int quantidade;
    float valorTotal;
} Atendimento;
```

### Explicação técnica

A palavra-chave `struct` permite agrupar diferentes tipos de dados em uma única estrutura.

O `typedef` cria um nome alternativo para esse tipo, permitindo declarar variáveis utilizando diretamente os nomes `Tutor`, `Animal` e `Atendimento`.

O programa utiliza três estruturas:

**Tutor:** armazena o código, o nome e o telefone do responsável.

**Animal:** armazena o código, nome, espécie, idade e código do tutor responsável.

**Atendimento:** armazena o código do animal, o serviço realizado, a quantidade e o valor total.

### Sugestão de fala

> Para organizar os dados, utilizamos `typedef struct`, que permite agrupar informações de diferentes tipos em uma única estrutura. Por exemplo, um tutor possui código, nome e telefone. Em vez de trabalhar com variáveis independentes, criamos o tipo personalizado `Tutor`. Aplicamos a mesma lógica para animais e atendimentos.

### Exemplo prático

```c
Tutor novo;
```

Essa declaração cria uma variável do tipo `Tutor`, contendo todos os campos definidos na estrutura.

Para acessar um campo, utilizamos o operador ponto:

```c
novo.codigo = 10;
```

### Ponto importante

O campo `codigoTutor`, presente na estrutura `Animal`, permite associar cada animal a um tutor cadastrado.

Essa associação é realizada por meio dos códigos dos registros.

---

## 3. Vetores — Armazenamento de registros

### Trecho do código

```c
Tutor tutores[MAX_TUTORES];
Animal animais[MAX_ANIMAIS];
Atendimento atendimentos[MAX_ATENDIMENTOS];
```

### Explicação técnica

Vetores são estruturas que permitem armazenar vários elementos do mesmo tipo em posições sequenciais.

No PetControl, cada posição dos vetores armazena uma estrutura completa.

Por exemplo:

```c
Tutor tutores[30];
```

Esse vetor possui capacidade para armazenar 30 estruturas do tipo `Tutor`.

Seus índices vão de `0` até `29`.

A mesma lógica é aplicada aos vetores de animais e atendimentos.

### Sugestão de fala

> Após definir as estruturas, criamos vetores para armazenar os registros. Cada posição do vetor `tutores`, por exemplo, contém uma estrutura completa com código, nome e telefone. Como os vetores começam no índice zero, um vetor com capacidade para 30 tutores possui posições de zero a vinte e nove.

### Exemplo prático

```c
tutores[0].codigo = 10;
```

Essa instrução acessa o campo `codigo` do primeiro tutor armazenado no vetor.

### Ponto importante

O vetor possui capacidade fixa, mas isso não significa que todas as suas posições estejam ocupadas.

Para controlar quantos registros realmente existem, o programa utiliza contadores.

---

## 4. Contadores — Controle dos registros

### Trecho do código

```c
int totalTutores = 0;
int totalAnimais = 0;
int totalAtendimentos = 0;
```

### Explicação técnica

Os contadores são variáveis inteiras que armazenam a quantidade de registros efetivamente cadastrados.

Todos são inicializados em zero porque, no início da execução, não existem registros cadastrados.

Quando um novo tutor é inserido, o programa executa:

```c
tutores[totalTutores] = novo;
totalTutores++;
```

A primeira instrução armazena o novo tutor na próxima posição disponível.

A segunda incrementa o contador em uma unidade.

### Exemplo prático

Imagine que existam dois tutores cadastrados.

Nesse caso:

```c
totalTutores = 2;
```

As posições `0` e `1` já estão ocupadas.

O próximo tutor será armazenado na posição `2`.

Após o cadastro:

```c
totalTutores++;
```

O contador passará a valer `3`.

### Sugestão de fala

> Os contadores permitem identificar quantos registros foram cadastrados. Eles começam em zero e são incrementados a cada novo cadastro bem-sucedido. Além de contabilizar os registros, também indicam a próxima posição disponível no vetor e são utilizados para controlar os limites de armazenamento.

### Ponto importante

É necessário distinguir:

- **Capacidade do vetor:** número máximo de registros.
- **Valor do contador:** quantidade de registros atualmente cadastrados.

---

## 5. Catálogo de serviços e preços

### Trecho do código

```c
char nomesServicos[4][30] = {
    "Banho",
    "Tosa",
    "Consulta veterinaria",
    "Vacinacao ficticia"
};

float precosServicos[4] = {
    35.0, 45.0, 80.0, 60.0
};
```

### Explicação técnica

O catálogo utiliza duas estruturas de armazenamento.

**Matriz de caracteres:**

```c
char nomesServicos[4][30];
```

Possui quatro linhas, cada uma com capacidade para armazenar uma string de até 29 caracteres, além do terminador `\0`.

Cada linha representa o nome de um serviço.

**Vetor de preços:**

```c
float precosServicos[4];
```

Armazena os preços dos quatro serviços.

### Relação entre nomes e preços

| Índice | Serviço | Preço |
|---|---|---|
| 0 | Banho | R$ 35,00 |
| 1 | Tosa | R$ 45,00 |
| 2 | Consulta veterinária | R$ 80,00 |
| 3 | Vacinação fictícia | R$ 60,00 |

O relacionamento entre as estruturas acontece por meio dos índices correspondentes.

Por exemplo:

```c
nomesServicos[0]
precosServicos[0]
```

Ambas as expressões fazem referência ao serviço de banho: a primeira ao nome e a segunda ao preço.

### Exibição do catálogo

Na função `registrarAtendimento()`, o programa utiliza:

```c
for (i = 0; i < 4; i++) {
    printf("%d - %s: R$ %.2f\n",
           i + 1,
           nomesServicos[i],
           precosServicos[i]);
}
```

O laço percorre os quatro serviços.

A expressão `i + 1` permite apresentar as opções numeradas de 1 a 4, embora os índices dos vetores comecem em zero.

### Sugestão de fala

> O catálogo de serviços foi organizado utilizando uma matriz de caracteres para armazenar os nomes e um vetor do tipo `float` para armazenar os preços. As duas estruturas possuem quatro posições correspondentes. Assim, o índice zero representa o banho e seu preço de 35 reais, o índice um representa a tosa e assim sucessivamente. Utilizamos um laço `for` para apresentar os serviços ao usuário.

### Ponto importante

O cálculo do valor do atendimento utiliza:

```c
valor = precosServicos[servico - 1] * quantidade;
```

A subtração de uma unidade é necessária porque o usuário escolhe opções de 1 a 4, enquanto os índices do vetor vão de 0 a 3.

---

## 6. Case 3 — Listagem de cadastros

### Trecho do menu principal

```c
case 3:
    listarCadastros();
    break;
```

### Explicação técnica

O `case 3` é executado quando o usuário seleciona a opção 3 no menu principal.

Ele chama a função `listarCadastros()`, responsável por apresentar os tutores e animais cadastrados.

O comando `break` encerra a execução do `switch` após o retorno da função.

### Função `listarCadastros()`

```c
void listarCadastros() {
    int i;

    printf("\n--- TUTORES ---\n");

    if (totalTutores == 0) {
        printf("Nenhum tutor cadastrado.\n");
    }

    for (i = 0; i < totalTutores; i++) {
        printf("Codigo: %d | Nome: %s | Telefone: %s\n",
               tutores[i].codigo,
               tutores[i].nome,
               tutores[i].telefone);
    }

    printf("\n--- ANIMAIS ---\n");

    if (totalAnimais == 0) {
        printf("Nenhum animal cadastrado.\n");
    }

    for (i = 0; i < totalAnimais; i++) {
        printf("Codigo: %d | Nome: %s | Especie: %s | Idade: %d | Codigo do tutor: %d\n",
               animais[i].codigo,
               animais[i].nome,
               animais[i].especie,
               animais[i].idade,
               animais[i].codigoTutor);
    }
}
```

### Etapa 1 — Verificação dos registros

```c
if (totalTutores == 0)
```

Essa condição verifica se existem tutores cadastrados.

Se o contador for igual a zero, o programa informa que não há registros.

O mesmo procedimento é realizado para os animais.

### Etapa 2 — Percorrendo os vetores

```c
for (i = 0; i < totalTutores; i++)
```

O laço começa com `i = 0` e continua enquanto `i` for menor que `totalTutores`.

A cada repetição, `i++` incrementa o índice em uma unidade.

Assim, o programa percorre somente as posições correspondentes aos registros cadastrados.

### Etapa 3 — Exibição das informações

```c
printf("Codigo: %d | Nome: %s | Telefone: %s\n",
       tutores[i].codigo,
       tutores[i].nome,
       tutores[i].telefone);
```

O `printf()` exibe os campos da estrutura armazenada na posição atual do vetor.

Os especificadores de formato utilizados são:

- `%d`: números inteiros.
- `%s`: strings.
- `\n`: quebra de linha.

### Sugestão de fala

> O `case 3` é responsável por chamar a função de listagem dos cadastros. Inicialmente, o programa verifica se existem registros por meio dos contadores. Em seguida, utiliza laços `for` para percorrer os vetores de tutores e animais. A cada repetição, o índice permite acessar uma estrutura e apresentar seus campos na tela. O laço termina quando todos os registros cadastrados tiverem sido exibidos.

### Ponto importante

O programa utiliza `totalTutores` e `totalAnimais` como limites dos laços, em vez de percorrer toda a capacidade dos vetores.

Isso evita exibir posições que não correspondem a cadastros realizados.

---

## 🖥️ Demonstração prática sugerida

Durante a apresentação, demonstrar a seguinte sequência:

1. Explicar os limites definidos com `#define`.
2. Mostrar as estruturas `Tutor`, `Animal` e `Atendimento`.
3. Apresentar os vetores responsáveis pelo armazenamento.
4. Explicar como os contadores são incrementados.
5. Mostrar o catálogo de serviços e seus preços.
6. Executar a opção 3 do menu para listar os cadastros.

**Sugestão:** antes de executar a opção 3, solicitar que outro integrante cadastre pelo menos um tutor e um animal. Assim, será possível demonstrar a listagem com dados reais inseridos durante a apresentação.

---

## ❓ Possíveis perguntas da banca

### 1. Qual é a diferença entre `struct` e `typedef struct`?

A `struct` define uma estrutura que agrupa diferentes campos. O `typedef` permite criar um nome alternativo para o tipo, simplificando sua utilização.

### 2. Por que utilizar vetores?

Porque precisamos armazenar múltiplos registros do mesmo tipo, permitindo acessá-los por índices.

### 3. Qual é a diferença entre capacidade e contador?

A capacidade define quantos elementos podem ser armazenados. O contador indica quantos registros foram efetivamente cadastrados.

### 4. Por que os vetores começam no índice zero?

Porque, em C, o primeiro elemento de um vetor é acessado pelo índice zero. Um vetor com quatro elementos possui índices de 0 a 3.

### 5. Por que utilizar `i + 1` no catálogo?

Porque os índices começam em zero, mas as opções apresentadas ao usuário são numeradas de 1 a 4.

### 6. Qual é a finalidade do `\0`?

É o caractere nulo que indica o término de uma string em C.

### 7. Por que a função `listarCadastros()` utiliza dois laços `for`?

Porque os tutores e animais são armazenados em vetores diferentes, cada um com seu próprio contador.

### 8. O que aconteceria se `totalTutores` fosse igual a zero?

O programa exibiria a mensagem informando que não existem tutores cadastrados, e o laço de listagem dos tutores não seria executado.

---

## 📝 Resumo para revisão

| Conceito | Ideia principal |
|---|---|
| `#define` | Define macros utilizadas como limites |
| `typedef struct` | Cria tipos personalizados para agrupar dados |
| Vetores | Armazenam múltiplos registros |
| Contadores | Controlam a quantidade de registros |
| Matriz de caracteres | Armazena os nomes dos serviços |
| Vetor `float` | Armazena os preços |
| `for` | Percorre os elementos cadastrados |
| `case 3` | Aciona a função de listagem |
| `printf()` | Apresenta os registros no terminal |

---

**Objetivo da minha apresentação:** demonstrar como o PetControl organiza seus dados em memória e como utiliza estruturas, vetores, contadores e laços de repetição para armazenar e apresentar informações.
