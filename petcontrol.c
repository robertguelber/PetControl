// Projeto PetControl - sistema simples para pet shop e clinica veterinaria.
// Este programa foi feito para praticar os conteudos de Logica de Programacao em C.

#include <stdio.h>   // Permite usar printf, fgets e outras funcoes de entrada e saida.
#include <string.h>  // Permite usar strlen e strcpy para trabalhar com textos.

#define MAX_TUTORES 30       // Quantidade maxima de tutores que podem ser cadastrados.
#define MAX_ANIMAIS 50       // Quantidade maxima de animais que podem ser cadastrados.
#define MAX_ATENDIMENTOS 100 // Quantidade maxima de atendimentos durante a execucao.

// Estrutura que guarda os dados de um tutor.
typedef struct {
    int codigo;          // Codigo usado para identificar o tutor.
    char nome[100];      // Nome completo do tutor.
    char telefone[30];  // Telefone guardado como texto.
} Tutor;

// Estrutura que guarda os dados de um animal.
typedef struct {
    int codigo;          // Codigo usado para identificar o animal.
    char nome[100];      // Nome do animal.
    char especie[40];    // Especie do animal, como cachorro ou gato.
    int idade;           // Idade do animal em anos.
    int codigoTutor;     // Codigo do tutor responsavel pelo animal.
} Animal;

// Estrutura que guarda cada atendimento realizado.
typedef struct {
    int codigoAnimal;    // Codigo do animal que recebeu o servico.
    int codigoServico;   // Numero do servico escolhido.
    int quantidade;      // Quantidade do servico, quando ele permite quantidade.
    float valorTotal;    // Valor cobrado pelo atendimento.
} Atendimento;

// Vetores usados para guardar os registros enquanto o programa estiver aberto.
Tutor tutores[MAX_TUTORES];                 // Lista de tutores.
Animal animais[MAX_ANIMAIS];                // Lista de animais.
Atendimento atendimentos[MAX_ATENDIMENTOS]; // Lista de atendimentos.

// Contadores que mostram quantos registros existem em cada vetor.
int totalTutores = 0;       // Comeca sem tutores cadastrados.
int totalAnimais = 0;       // Comeca sem animais cadastrados.
int totalAtendimentos = 0; // Comeca sem atendimentos registrados.

// Catalogo de servicos e precos.
char nomesServicos[4][30] = {"Banho", "Tosa", "Consulta veterinaria", "Vacinacao ficticia"}; // Nomes.
float precosServicos[4] = {35.0, 45.0, 80.0, 60.0}; // Preco de cada servico, na mesma ordem.


// Limpa o restante da linha depois de uma leitura com scanf.
void limparEntrada() {
    int c; // Variavel usada para ler os caracteres que sobrarem.
    while ((c = getchar()) != '\n' && c != EOF) {
        // Continua lendo ate chegar ao fim da linha.
    }
}

// Le um texto com espacos e tira o Enter que o fgets guarda no final.
void lerTexto(char texto[], int tamanho) {
    if (fgets(texto, tamanho, stdin) != NULL) { // Tenta ler o texto digitado.
        texto[strcspn(texto, "\n")] = '\0'; // Troca o Enter por fim de texto.
    } else {
        texto[0] = '\0'; // Deixa o texto vazio se a leitura falhar.
    }
}

// Procura um tutor pelo codigo e devolve a posicao dele no vetor.
int buscarTutor(int codigo) {
    int i; // Indice usado para percorrer os tutores.
    for (i = 0; i < totalTutores; i++) { // Passa por todos os tutores cadastrados.
        if (tutores[i].codigo == codigo) { // Confere se o codigo e igual ao procurado.
            return i; // Devolve a posicao encontrada.
        }
    }
    return -1; // Devolve -1 quando nao encontra o tutor.
}

// Procura um animal pelo codigo e devolve a posicao dele no vetor.
int buscarAnimal(int codigo) {
    int i; // Indice usado para percorrer os animais.
    for (i = 0; i < totalAnimais; i++) { // Passa por todos os animais cadastrados.
        if (animais[i].codigo == codigo) { // Confere se o codigo e igual ao procurado.
            return i; // Devolve a posicao encontrada.
        }
    }
    return -1; // Devolve -1 quando nao encontra o animal.
}

// Cadastra um tutor novo.
void cadastrarTutor() {
    Tutor novo; // Variavel temporaria para preencher os dados antes de guardar.

    if (totalTutores >= MAX_TUTORES) { // Verifica se o vetor ja esta cheio.
        printf("Limite de tutores atingido.\n"); // Avisa que nao cabem mais registros.
        return; // Volta para o menu.
    }

    printf("Codigo do tutor: "); // Pede o codigo do tutor.
    if (scanf("%d", &novo.codigo) != 1 || novo.codigo <= 0) { // Verifica se foi digitado um numero positivo.
        printf("Codigo invalido.\n"); // Mostra o erro.
        limparEntrada(); // Limpa o que ficou digitado.
        return; // Cancela o cadastro.
    }
    limparEntrada(); // Limpa o Enter que ficou depois do numero.

    if (buscarTutor(novo.codigo) != -1) { // Confere se esse codigo ja existe.
        printf("Ja existe um tutor com esse codigo.\n"); // Avisa sobre codigo repetido.
        return; // Cancela o cadastro.
    }

    printf("Nome completo: "); // Pede o nome do tutor.
    lerTexto(novo.nome, sizeof(novo.nome)); // Le o nome, inclusive se tiver espacos.
    if (strlen(novo.nome) == 0) { // Confere se o nome ficou vazio.
        printf("O nome nao pode ficar vazio.\n"); // Avisa sobre o campo vazio.
        return; // Cancela o cadastro.
    }

    printf("Telefone: "); // Pede o telefone.
    lerTexto(novo.telefone, sizeof(novo.telefone)); // Le o telefone como texto.
    if (strlen(novo.telefone) == 0) { // Confere se o telefone ficou vazio.
        printf("O telefone nao pode ficar vazio.\n"); // Avisa sobre o campo vazio.
        return; // Cancela o cadastro.
    }

    tutores[totalTutores] = novo; // Guarda o tutor na proxima posicao livre.
    totalTutores++; // Aumenta a quantidade de tutores cadastrados.
    printf("Tutor cadastrado com sucesso!\n"); // Confirma o cadastro.
}

// Cadastra um animal e verifica se o tutor informado existe.
void cadastrarAnimal() {
    Animal novo; // Variavel temporaria para preencher os dados do animal.

    if (totalAnimais >= MAX_ANIMAIS) { // Verifica se o vetor de animais esta cheio.
        printf("Limite de animais atingido.\n"); // Mostra o aviso.
        return; // Volta para o menu.
    }

    printf("Codigo do animal: "); // Pede o codigo do animal.
    if (scanf("%d", &novo.codigo) != 1 || novo.codigo <= 0) { // Aceita apenas codigo positivo.
        printf("Codigo invalido.\n"); // Mostra o erro.
        limparEntrada(); // Limpa a entrada incorreta.
        return; // Cancela o cadastro.
    }
    limparEntrada(); // Limpa o Enter que ficou depois do numero.

    if (buscarAnimal(novo.codigo) != -1) { // Verifica se o codigo ja foi usado.
        printf("Ja existe um animal com esse codigo.\n"); // Informa que o codigo e repetido.
        return; // Cancela o cadastro.
    }

    printf("Nome do animal: "); // Pede o nome.
    lerTexto(novo.nome, sizeof(novo.nome)); // Le o nome do animal.
    if (strlen(novo.nome) == 0) { // Verifica se o nome foi deixado em branco.
        printf("O nome nao pode ficar vazio.\n"); // Avisa sobre o campo vazio.
        return; // Cancela o cadastro.
    }

    printf("Especie: "); // Pede a especie do animal.
    lerTexto(novo.especie, sizeof(novo.especie)); // Le a especie digitada.
    if (strlen(novo.especie) == 0) { // Verifica se a especie foi deixada em branco.
        printf("A especie nao pode ficar vazia.\n"); // Avisa sobre o campo vazio.
        return; // Cancela o cadastro.
    }

    printf("Idade do animal: "); // Pede a idade.
    if (scanf("%d", &novo.idade) != 1 || novo.idade < 0 || novo.idade > 100) { // Valida a idade.
        printf("Idade invalida. Use um valor entre 0 e 100.\n"); // Mostra o erro.
        limparEntrada(); // Limpa a entrada incorreta.
        return; // Cancela o cadastro.
    }
    limparEntrada(); // Limpa o Enter que ficou depois da idade.

    printf("Codigo do tutor responsavel: "); // Pede o codigo do tutor.
    if (scanf("%d", &novo.codigoTutor) != 1 || novo.codigoTutor <= 0) { // Verifica se o codigo e valido.
        printf("Codigo de tutor invalido.\n"); // Mostra o erro.
        limparEntrada(); // Limpa a entrada incorreta.
        return; // Cancela o cadastro.
    }
    limparEntrada(); // Limpa o Enter que ficou depois do numero.

    if (buscarTutor(novo.codigoTutor) == -1) { // Confere se o tutor existe.
        printf("Tutor nao encontrado. Animal nao cadastrado.\n"); // Impede vinculo com tutor inexistente.
        return; // Cancela o cadastro.
    }

    animais[totalAnimais] = novo; // Guarda o animal na proxima posicao livre.
    totalAnimais++; // Aumenta a quantidade de animais cadastrados.
    printf("Animal cadastrado com sucesso!\n"); // Confirma o cadastro.
}

// Mostra todos os tutores e animais que estao cadastrados.

void listarCadastros() {
    int i; // Indice usado nos dois vetores.

    printf("\n--- TUTORES ---\n"); // Titulo da lista de tutores.
    if (totalTutores == 0) { // Confere se existe algum tutor.
        printf("Nenhum tutor cadastrado.\n"); // Informa que a lista esta vazia.
    }
    for (i = 0; i < totalTutores; i++) { // Percorre os tutores.
        printf("Codigo: %d | Nome: %s | Telefone: %s\n",
               tutores[i].codigo, tutores[i].nome, tutores[i].telefone); // Mostra os dados do tutor.
    }

    printf("\n--- ANIMAIS ---\n"); // Titulo da lista de animais.
    if (totalAnimais == 0) { // Confere se existe algum animal.
        printf("Nenhum animal cadastrado.\n"); // Informa que a lista esta vazia.
    }
    for (i = 0; i < totalAnimais; i++) { // Percorre os animais.
        printf("Codigo: %d | Nome: %s | Especie: %s | Idade: %d | Codigo do tutor: %d\n",
               animais[i].codigo, animais[i].nome, animais[i].especie,
               animais[i].idade, animais[i].codigoTutor); // Mostra os dados do animal.
    }
}

// Permite procurar um tutor ou animal pelo codigo.
void buscarRegistro() {
    int tipo; // Guarda se a pessoa quer procurar tutor ou animal.
    int codigo; // Guarda o codigo digitado.
    int posicao; // Guarda a posicao encontrada no vetor.

    printf("Buscar 1-Tutor ou 2-Animal: "); // Pergunta qual tipo de registro sera procurado.
    if (scanf("%d", &tipo) != 1 || (tipo != 1 && tipo != 2)) { // Aceita somente 1 ou 2.
        printf("Opcao invalida.\n"); // Mostra o erro.
        limparEntrada(); // Limpa a entrada incorreta.
        return; // Volta para o menu.
    }

    printf("Digite o codigo: "); // Pede o codigo para pesquisa.
    if (scanf("%d", &codigo) != 1 || codigo <= 0) { // Verifica se o codigo e positivo.
        printf("Codigo invalido.\n"); // Mostra o erro.
        limparEntrada(); // Limpa a entrada incorreta.
        return; // Volta para o menu.
    }
    limparEntrada(); // Limpa o Enter que ficou depois do numero.

    if (tipo == 1) { // Executa a busca de tutor.
        posicao = buscarTutor(codigo); // Procura o codigo no vetor de tutores.
        if (posicao == -1) { // Confere se a busca falhou.
            printf("Tutor nao encontrado.\n"); // Informa que nao existe.
        } else {
            printf("Tutor: %d | %s | Telefone: %s\n",
                   tutores[posicao].codigo, tutores[posicao].nome,
                   tutores[posicao].telefone); // Mostra os dados encontrados.
        }
    } else { // Executa a busca de animal.
        posicao = buscarAnimal(codigo); // Procura o codigo no vetor de animais.
        if (posicao == -1) { // Confere se a busca falhou.
            printf("Animal nao encontrado.\n"); // Informa que nao existe.
        } else {
            printf("Animal: %d | %s | Especie: %s | Idade: %d | Tutor: %d\n",
                   animais[posicao].codigo, animais[posicao].nome,
                   animais[posicao].especie, animais[posicao].idade,
                   animais[posicao].codigoTutor); // Mostra os dados encontrados.
        }
    }
}

// Mostra os servicos e registra um atendimento para um animal existente.
void registrarAtendimento() {
    int codigoAnimal; // Codigo do animal que sera atendido.
    int servico; // Numero do servico escolhido.
    int quantidade = 1; // Comeca com uma unidade.
    int posicao; // Guarda a posicao do animal encontrado.
    float valor; // Guarda o valor total do atendimento.
    int i; // Indice para mostrar os servicos.

    if (totalAtendimentos >= MAX_ATENDIMENTOS) { // Verifica se ja foram registrados muitos atendimentos.
        printf("Limite de atendimentos atingido.\n"); // Mostra o aviso.
        return; // Volta para o menu.
    }

    printf("Codigo do animal: "); // Pede qual animal sera atendido.
    if (scanf("%d", &codigoAnimal) != 1 || codigoAnimal <= 0) { // Valida o codigo.
        printf("Codigo invalido.\n"); // Mostra o erro.
        limparEntrada(); // Limpa a entrada incorreta.
        return; // Cancela o atendimento.
    }
    limparEntrada(); // Limpa o Enter que ficou depois do numero.

    posicao = buscarAnimal(codigoAnimal); // Procura o animal cadastrado.
    if (posicao == -1) { // Verifica se o animal existe.
        printf("Animal nao encontrado. Atendimento cancelado.\n"); // Impede atendimento de animal inexistente.
        return; // Volta para o menu.
    }

    printf("\n--- SERVICOS ---\n"); // Mostra o titulo do catalogo.
    for (i = 0; i < 4; i++) { // Percorre os quatro servicos.
        printf("%d - %s: R$ %.2f\n", i + 1, nomesServicos[i], precosServicos[i]); // Mostra nome e preco.
    }

    printf("Escolha o servico: "); // Pede o servico escolhido.
    if (scanf("%d", &servico) != 1 || servico < 1 || servico > 4) { // Aceita os codigos de 1 a 4.
        printf("Servico invalido.\n"); // Mostra o erro.
        limparEntrada(); // Limpa a entrada incorreta.
        return; // Cancela o atendimento.
    }
    limparEntrada(); // Limpa o Enter que ficou depois do numero.

    if (servico == 1 || servico == 2) { // Banho e tosa permitem informar quantidade.
        printf("Quantidade: "); // Pede quantas unidades serao cobradas.
        if (scanf("%d", &quantidade) != 1 || quantidade < 1 || quantidade > 100) { // Valida a quantidade.
            printf("Quantidade invalida.\n"); // Mostra o erro.
            limparEntrada(); // Limpa a entrada incorreta.
            return; // Cancela o atendimento.
        }
        limparEntrada(); // Limpa o Enter que ficou depois do numero.
    }

    valor = precosServicos[servico - 1] * quantidade; // Calcula o total com base no preco e na quantidade.
    atendimentos[totalAtendimentos].codigoAnimal = codigoAnimal; // Guarda o codigo do animal.
    atendimentos[totalAtendimentos].codigoServico = servico; // Guarda o servico escolhido.
    atendimentos[totalAtendimentos].quantidade = quantidade; // Guarda a quantidade.
    atendimentos[totalAtendimentos].valorTotal = valor; // Guarda o valor calculado.
    totalAtendimentos++; // Aumenta o contador de atendimentos.

    printf("Atendimento registrado. Total: R$ %.2f\n", valor); // Confirma o registro e mostra o valor.
}

// Mostra o numero de atendimentos, o faturamento e os totais por servico.
void relatorio() {
    int i; // Indice para percorrer os atendimentos.
    int j; // Indice para percorrer os servicos.
    int contagem[4] = {0, 0, 0, 0}; // Guarda quantos atendimentos foram feitos por servico.
    float totais[4] = {0, 0, 0, 0}; // Guarda o faturamento de cada servico.
    float faturamento = 0; // Comeca o faturamento em zero.

    for (i = 0; i < totalAtendimentos; i++) { // Percorre todos os atendimentos feitos.
        j = atendimentos[i].codigoServico - 1; // Converte o codigo do servico para indice do vetor.
        contagem[j]++; // Soma um atendimento para aquele servico.
        totais[j] += atendimentos[i].valorTotal; // Soma o valor no total daquele servico.
        faturamento += atendimentos[i].valorTotal; // Soma o valor no faturamento geral.
    }

    printf("\n--- RELATORIO DA SESSAO ---\n"); // Mostra o titulo do relatorio.
    printf("Numero de atendimentos: %d\n", totalAtendimentos); // Mostra a quantidade de atendimentos.
    printf("Faturamento total: R$ %.2f\n", faturamento); // Mostra o faturamento total.

    for (i = 0; i < 4; i++) { // Percorre os servicos para mostrar seus totais.
        printf("%s: %d atendimento(s), R$ %.2f\n",
               nomesServicos[i], contagem[i], totais[i]); // Mostra quantidade e faturamento por servico.
    }
}

// Altera o nome de um tutor recebendo o endereco da struct por ponteiro.
void alterarTutor(Tutor *tutor) {
    char novoNome[100]; // Guarda temporariamente o nome novo.

    limparEntrada(); // Garante que nao ficou Enter de uma leitura anterior.
    printf("Digite o novo nome: "); // Pede o nome atualizado.
    lerTexto(novoNome, sizeof(novoNome)); // Le o novo nome com espacos.

    if (strlen(novoNome) == 0) { // Verifica se o nome ficou vazio.
        printf("Nome vazio. Alteracao cancelada.\n"); // Avisa que nao foi possivel alterar.
        return; // Sai da funcao sem mudar o nome.
    }

    strcpy(tutor->nome, novoNome); // O operador -> acessa o nome usando o ponteiro.
}

// Procura um tutor e chama a funcao que altera o nome dele.
void alterarCadastro() {
    int codigo; // Guarda o codigo do tutor.
    int posicao; // Guarda a posicao do tutor no vetor.

    printf("Codigo do tutor que deseja alterar: "); // Pede o codigo.
    if (scanf("%d", &codigo) != 1 || codigo <= 0) { // Verifica se o codigo e valido.
        printf("Codigo invalido.\n"); // Mostra o erro.
        limparEntrada(); // Limpa a entrada incorreta.
        return; // Volta para o menu.
    }

    posicao = buscarTutor(codigo); // Procura o tutor pelo codigo.
    if (posicao == -1) { // Confere se o tutor foi encontrado.
        printf("Tutor nao encontrado.\n"); // Informa que nao existe.
        limparEntrada(); // Limpa o Enter que ficou na entrada.
        return; // Volta para o menu.
    }

    alterarTutor(&tutores[posicao]); // O & envia o endereco do tutor para a funcao.
    printf("Cadastro alterado.\n"); // Confirma a alteracao.
}

// Mostra as opcoes que o usuario pode escolher.
void mostrarMenu() {
    printf("\n===== PETCONTROL =====\n"); // Titulo do sistema.
    printf("1 - Cadastrar tutor\n"); // Opcao para cadastrar tutor.
    printf("2 - Cadastrar animal\n"); // Opcao para cadastrar animal.
    printf("3 - Listar cadastros\n"); // Opcao para listar os registros.
    printf("4 - Buscar registro\n"); // Opcao para procurar um registro.
    printf("5 - Registrar atendimento\n"); // Opcao para registrar servico.
    printf("6 - Alterar nome de tutor\n"); // Opcao para alterar cadastro.
    printf("7 - Relatorio\n"); // Opcao para mostrar os totais.
    printf("0 - Sair\n"); // Opcao para encerrar o programa.
}

// Funcao principal: mostra o menu e chama a funcao escolhida.
int main() {
    int opcao; // Guarda a opcao digitada no menu.

    do { // Repete o menu pelo menos uma vez.
        mostrarMenu(); // Exibe as opcoes na tela.
        printf("Escolha uma opcao: "); // Pede a opcao ao usuario.

        if (scanf("%d", &opcao) != 1) { // Verifica se foi digitado um numero.
            printf("Entrada invalida. Digite um numero do menu.\n"); // Informa o erro.
            limparEntrada(); // Limpa a entrada que nao era numerica.
            opcao = -1; // Usa um valor invalido para continuar o laco.
        } else {
            limparEntrada(); // Limpa o Enter depois da opcao.
            switch (opcao) { // Escolhe qual funcao executar.
                case 1: cadastrarTutor(); break; // Chama o cadastro de tutor.
                case 2: cadastrarAnimal(); break; // Chama o cadastro de animal.
                case 3: listarCadastros(); break; // Chama a listagem.
                case 4: buscarRegistro(); break; // Chama a busca.
                case 5: registrarAtendimento(); break; // Chama o atendimento.
                case 6: alterarCadastro(); break; // Chama a alteracao.
                case 7: relatorio(); break; // Chama o relatorio.
                case 0: printf("Programa encerrado.\n"); break; // Encerra o sistema.
                default: printf("Opcao invalida. Tente novamente.\n"); // Trata numeros fora do menu.
            }
        }
    } while (opcao != 0); // Continua ate o usuario escolher zero.

    return 0; // Informa que o programa terminou normalmente.
}
