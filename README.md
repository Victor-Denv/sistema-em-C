📚 Sistema de Gestão de Biblioteca em C



⚠️ Importante: Este código foi desenvolvido em janeiro de 2025, quando eu ainda não tinha conhecimento sobre o uso de versionamento e commits no Git. Por isso, todo o código foi feito diretamente sem o uso de Git durante o desenvolvimento.

🎯 Descrição do Projeto
    Este projeto é um sistema simples e funcional de Gestão de Biblioteca, desenvolvido em linguagem C, com foco no aprendizado de programação estruturada, manipulação de arquivos e separação de funcionalidades por funções.


O sistema funciona 100% no terminal e permite:
    ✔️ Cadastrar livros

    ✔️ Cadastrar usuários

    ✔️ Realizar empréstimos

    ✔️ Fazer devoluções

    ✔️ Listar livros, usuários e empréstimos

    ✔️ Salvar dados em arquivos .txt para manter o histórico mesmo após fechar o programa



⚙️ Funcionalidades
    ✅ Cadastro de livros (código, título, autor, ano)

    ✅ Cadastro de usuários (ID, nome, CPF)

    ✅ Empréstimo e devolução de livros

    ✅ Listagem completa de livros, usuários e empréstimos

    ✅ Dados persistidos em arquivos .txt:
    
        .livros.txt

        .usuarios.txt

        .emprestimos.txt


🛠️ Tecnologias Utilizadas

Linguagem C padrão

Compilador GCC (MinGW para Windows)

Manipulação de arquivos .txt

 Estrutura de dados com structs e vetores


🗂️ Estrutura dos Arquivos
    biblioteca.c           --> Código-fonte completo
    livros.txt              --> Armazena livros cadastrados
    usuarios.txt            --> Armazena usuários cadastrados
    emprestimos.txt         --> Registra empréstimos e devoluções
    Os arquivos .txt são criados automaticamente na primeira execução do sistema.





🚀 Como Executar
    Pré-requisitos:
    ✔️ Ter o GCC instalado (MinGW no Windows)
     ✔️ Ter o VSCode ou outro editor de texto

Passos para compilar e executar:
    gcc sistema_biblioteca.c -o biblioteca.exe
    ./biblioteca.exe










💡 Possíveis Melhorias Futuras

Melhor validação de entrada do usuário

Controle de disponibilidade dos livros

Limitação de quantidade de empréstimos por usuário

Busca avançada por título, autor ou ID

Modularização do código em arquivos .h separados



👨‍💻 Autor
Sistema criado como projeto de prática de programação em C durante meus estudos em janeiro de 2025, com o objetivo de treinar lógica de programação, manipulação de arquivos e estruturas de dados.