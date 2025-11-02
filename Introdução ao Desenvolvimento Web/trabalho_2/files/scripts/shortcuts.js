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

    document.addEventListener('keydown', (e) => {
      if (e.ctrlKey && !e.repeat) {
        switch (e.key) {
          case 'ArrowDown':
            e.preventDefault();
            if (currentFontSize > minFontSize) {
              currentFontSize--;
              setFontSize(currentFontSize);
            }
            break;
          case 'ArrowUp':
            e.preventDefault();
            if (currentFontSize < maxFontSize) {
              currentFontSize++;
              setFontSize(currentFontSize);
            }
            break;
          case '0':
            e.preventDefault();
            currentFontSize = defaultFontSize;
            setFontSize(currentFontSize);
            break;
        }
      }
    });

    const alertEl = document.getElementById('font-alert');
    alertEl.addEventListener('click', () => {
      alert(`Atalhos do teclado:\n\nCtrl + Seta para cima: Aumentar fonte\nCtrl + Seta para baixo: Diminuir fonte\nCtrl + 0: Restaurar fonte padrão`);
    });
});
