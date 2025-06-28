📚 Sistema de Gestão de Biblioteca em C
⚠️ IMPORTANTE: Este projeto foi desenvolvido em janeiro de 2025, quando eu ainda não tinha conhecimento sobre o uso de versionamento e commits no Git. Por isso, o código foi feito diretamente sem histórico de commits.

🎯 Descrição do Projeto
Sistema simples e funcional de Gestão de Biblioteca em linguagem C, com menus interativos no terminal, permitindo o cadastro de livros e usuários, empréstimos, devoluções e listagem, com dados salvos em arquivos .txt para manter o histórico.

⚙️ Funcionalidades
✅ Cadastro de livros (código, título, autor, ano)
✅ Cadastro de usuários (ID, nome, CPF)
✅ Empréstimos e devoluções de livros
✅ Listagem de livros, usuários e empréstimos
✅ Dados armazenados nos arquivos:

livros.txt

usuarios.txt

emprestimos.txt

🛠️ Tecnologias Utilizadas
Linguagem C padrão

Compilador GCC (MinGW no Windows)

Manipulação de arquivos .txt

Structs e arrays fixos

🗂️ Estrutura dos Arquivos

sistema_biblioteca.c    --> Código-fonte completo
livros.txt               --> Dados dos livros
usuarios.txt             --> Dados dos usuários
emprestimos.txt          --> Registros de empréstimos
Os arquivos .txt são criados automaticamente.

🚀 Como Executar
Instalar GCC (MinGW no Windows)

No terminal:

gcc sistema_biblioteca.c -o biblioteca.exe
./biblioteca.exe
💡 Possíveis Melhorias Futuras
Validação de entradas

Busca avançada por título ou nome

Controle de disponibilidade dos livros

Modularização em .h e .c separados

👨‍💻 Autor
Sistema criado como prática de linguagem C durante meus estudos em janeiro de 2025.

