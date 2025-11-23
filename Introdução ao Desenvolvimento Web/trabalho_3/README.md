# Relatório do Trabalho 3

## Introdução ao Desenvolvimento Web - 2025/2

### Descrição Geral
O projeto desenvolvido tem como tema o “Universo Shrek”, apresentando uma página principal e páginas secundárias dedicadas a cada filme da franquia.
O site foi construído utilizando HTML, CSS e JavaScript, conforme as orientações do trabalho A2.
O trabalho 3 consiste em adicionar técnicas de responsividade vistas em aula.

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

### Responsividade

#### Responsividade por orientação (portrait vs landscape

O projeto adapta a interface usando media queries baseadas na orientação da tela:
➤ Tela vertical (portrait):
- Sidebar começa oculto
- Botão “Mostrar Personagens” aparece
- Sidebar vira um menu móvel (off-canvas)
- Dentro do menu existe o botão “← Voltar”
- Botão “Ocultar Personagens” fica invisível

➤ Tela horizontal (landscape):
- Sidebar é fixo e sempre visível
- Nenhum botão de sidebar aparece
- Sidebar nunca pode ser ocultado nessa orientação

#### Containers Flexíveis 
- .wrapper alterna entre colunas (desktop/landscape) e linhas empilhadas (portrait/mobile)
- Layout nunca “quebra” e evita overflow horizontal

#### Texto
- Tamanhos de fonte ajustados em telas pequenas
- Títulos têm melhor espaçamento vertical
- Layout evita cortes e mantém boa legibilidade

#### Imagens
- Todas as imagens usam max-width: 100%; height: auto;
- Mantém proporções em qualquer dispositivo
- Imagens da sidebar reduzem tamanho em dispositivos pequenos

#### Footer Responsivo
- Em telas menores, o footer muda para layout em coluna
- Links quebram linha automaticamente (word-break)
