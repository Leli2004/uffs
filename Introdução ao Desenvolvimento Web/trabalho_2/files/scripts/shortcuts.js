// Script para alterar tamanho das fontes (aumenta, diminui ou restaura padrão)

document.addEventListener('DOMContentLoaded', () => {
    const minFontSize = 10;  // px
    const maxFontSize = 30;  // px

    // Pega tamanho inicial do html definido no CSS
    const defaultFontSize = parseInt(window.getComputedStyle(document.documentElement).fontSize);

    let currentFontSize = defaultFontSize;

    function setFontSize(size) {
      document.documentElement.style.fontSize = size + "px";
    }

    setFontSize(currentFontSize);

    // Conforme cada tecla pressionada, altera o tamanho das fontes da página 
    document.addEventListener('keydown', (e) => {
      if (e.ctrlKey && !e.repeat) {
        switch (e.key) {
          // Diminuir fonte
          case 'ArrowDown':
            e.preventDefault();
            if (currentFontSize > minFontSize) {
              currentFontSize--;
              setFontSize(currentFontSize);
            }
            break;
          // Aumentar fonte
          case 'ArrowUp':
            e.preventDefault();
            if (currentFontSize < maxFontSize) {
              currentFontSize++;
              setFontSize(currentFontSize);
            }
            break;
          // Restaurar padrão definido no css
          case '0':
            e.preventDefault();
            currentFontSize = defaultFontSize;
            setFontSize(currentFontSize);
            break;
        }
      }
    });

    // Exibe alert com fontes disponíveis na página
    const alertEl = document.getElementById('font-alert');
    alertEl.addEventListener('click', () => {
      alert(`Atalhos do teclado:\n\nCtrl + Seta para cima: Aumentar fonte\nCtrl + Seta para baixo: Diminuir fonte\nCtrl + 0: Restaurar fonte padrão`);
    });
});
