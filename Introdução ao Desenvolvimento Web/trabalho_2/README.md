# Relatório do Trabalho 2 

## Introdução ao Desenvolvimento Web - 2025/2

### Descrição Geral
O projeto desenvolvido tem como tema o “Universo Shrek”, apresentando uma página principal e páginas secundárias dedicadas a cada filme da franquia.
O site foi construído utilizando HTML, CSS e JavaScript, conforme as orientações do trabalho A2.

### Funcionalidades

#### Botão de Modo Escuro/Claro
- Alterna as cores da página entre tema claro e escuro
- Manipula o DOM ao adicionar ou remover a classe dark-mode no elemento <body>, alterando cores de fundo, textos e botões
- Evento utilizado: click
 
#### Botão Ocultar/Mostrar Personagens
- Controla a exibição da sidebar com a lista de personagens
- Altera dinamicamente o estilo display e o texto do botão
- Evento utilizado: click

#### Ícone “Ver Atalhos do Teclado”
- Exibe um alerta com os atalhos disponíveis para uso na página
- Evento utilizado: click

#### Atalhos de Teclado
- Ctrl + Seta para cima: aumenta o tamanho das fontes da página
- Ctrl + Seta para baixo: diminui o tamanho das fontes
- Ctrl + 0: restaura o tamanho padrão
- Essas ações manipulam diretamente o estilo do elemento <html> via font-size
- Evento utilizado: keydown

#### Botão “Adicionar Avaliação”
- Exibe um formulário oculto para o usuário enviar uma avaliação
- Ao clicar em “Enviar”, o formulário é ocultado e uma mensagem de confirmação é exibida, simulando o envio da avaliação
- Eventos utilizados: click e submit
