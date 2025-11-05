# Sistema de Cadastro em C++

Bem-vindo ao **Sistema de Cadastro**, um projeto simples em C++ que demonstra o gerenciamento básico de usuários em memória. Este sistema possibilita o cadastro, login, edição e exclusão de usuários, simulando uma interface de manipulação de dados de pessoas. 

---

## 🌟 Funcionalidades

- **Cadastro de Usuário:** Permite salvar nome, e-mail, CPF e senha.
- **Login:** Realiza autenticação por nome e senha.
- **Edição de Cadastro:** O usuário pode atualizar seu nome e senha, após se autenticar.
- **Exclusão de Cadastro:** O usuário pode remover seus próprios dados, também mediante autenticação.
- **Menu interativo:** Interface via terminal com opções numeradas.

---

## 💻 Como funciona

O sistema utiliza um vetor (`std::vector`) para armazenar as informações dos usuários via estrutura (`struct Usuario`). 

**Fluxo Principal:**
1. O usuário escolhe uma opção no menu.
2. As funções são chamadas conforme a escolha: cadastrar, logar, editar ou excluir cadastro.
3. Em todas as operações sensíveis, é solicitado login para autenticação do usuário.
4. Não são utilizados arquivos externos: ao encerrar o programa, as informações cadastradas são perdidas.

---

## 🎯 Como usar

1. **Compile o código:**  
   No terminal, navegue até a pasta do projeto e execute:
   ```bash
   g++ -o sistema main.cpp
   ```
2. **Execute o binário:**
   ```bash
   ./sistema
   ```
3. **Siga as instruções exibidas no console.**

---

## ✨ Demonstração do Menu

```css
====== SISTEMA DE CADASTRO ======
1. Cadastrar usuário
2. Fazer login
3. Editar cadastro
4. Excluir cadastro
5. Sair
=================================
Escolha uma opção:
```

---

## ⚠️ Observações

- Todas as operações ocorrem em memória RAM, sem persistência em arquivo ou banco de dados.
- O CPF não é validado quanto à autenticidade e não é utilizado para login.
- A função limparTela utiliza comandos `system("cls"|"clear")`, podendo ser incompatível em alguns ambientes não suportados.
- Para evitar problemas de leitura no `getline`, o `cin.ignore()` é utilizado após capturar a opção do menu.

---

## 📝 Estrutura do Código

O código está organizado em funções separadas para cada operação:
- `cadastrarUsuario()`, `loginUsuario()`, `editarUsuario()`, `excluirUsuario()`, além do `menu()` principal.

---

## 👨‍💻 Autor

Desenvolvido para aprendizado de C++, manipulação de vetores e structs, e prática com entrada/saída no console.

Sinta-se à vontade para contribuir ou dar sugestões!

```
