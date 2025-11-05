#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Estrutura para armazenar dados de um usuário
struct Usuario {
    string nome;
    string email;
    string cpf;
    string senha;
};

// Banco de dados em memória
vector<Usuario> usuarios;

// Função para limpar a tela (funciona em Windows)
void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Função para pausar
void pausar() {
    cout << "\nPressione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Função de cadastro
void cadastrarUsuario() {
    Usuario novo;
    cout << "\n=== Cadastro de Usuário ===\n";
    cout << "Nome: ";
    getline(cin >> ws, novo.nome);
    cout << "E-mail: ";
    getline(cin >> ws, novo.email);
    cout << "CPF: ";
    getline(cin >> ws, novo.cpf);
    cout << "Senha: ";
    getline(cin >> ws, novo.senha);

    usuarios.push_back(novo);

    cout << "\nUsuário cadastrado com sucesso!\n";
    pausar();
}

// Função para login
int loginUsuario() {
    string nome, senha;
    cout << "\n=== Login ===\n";
    cout << "Nome: ";
    getline(cin >> ws, nome);
    cout << "Senha: ";
    getline(cin >> ws, senha);

    for (int i = 0; i < usuarios.size(); i++) {
        if (usuarios[i].nome == nome && usuarios[i].senha == senha) {
            cout << "\nLogin realizado com sucesso!\n";
            pausar();
            return i; // retorna o índice do usuário logado
        }
    }

    cout << "\nNome ou senha incorretos!\n";
    pausar();
    return -1;
}

// Função para editar cadastro
void editarUsuario() {
    cout << "\n=== Editar Cadastro ===\n";
    int indice = loginUsuario();

    if (indice != -1) {
        cout << "\nNovo nome: ";
        getline(cin >> ws, usuarios[indice].nome);
        cout << "Nova senha: ";
        getline(cin >> ws, usuarios[indice].senha);
        cout << "\nDados atualizados com sucesso!\n";
    } else {
        cout << "\nNão foi possível editar.\n";
    }

    pausar();
}

// Função para excluir cadastro
void excluirUsuario() {
    cout << "\n=== Excluir Cadastro ===\n";
    int indice = loginUsuario();

    if (indice != -1) {
        usuarios.erase(usuarios.begin() + indice);
        cout << "\nCadastro excluído com sucesso!\n";
    } else {
        cout << "\nNão foi possível excluir.\n";
    }

    pausar();
}

// Menu principal
void menu() {
    int opcao;

    do {
        limparTela();
        cout << "====== SISTEMA DE CADASTRO ======\n";
        cout << "1. Cadastrar usuário\n";
        cout << "2. Fazer login\n";
        cout << "3. Editar cadastro\n";
        cout << "4. Excluir cadastro\n";
        cout << "5. Sair\n";
        cout << "=================================\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore(); // evita problemas com getline

        limparTela();
        switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                loginUsuario();
                break;
            case 3:
                editarUsuario();
                break;
            case 4:
                excluirUsuario();
                break;
            case 5:
                cout << "Saindo do sistema...\n";
                break;
            default:
                cout << "Opção inválida!\n";
                pausar();
                break;
        }

    } while (opcao != 5);
}

// Função principal
int main() {
    setlocale(LC_ALL, "Portuguese");
    menu();
    return 0;
}

