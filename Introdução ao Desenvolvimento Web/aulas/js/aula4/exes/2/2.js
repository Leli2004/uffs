/*
2) Coloque um chapéu em cima do gato (<img>) e faça com que o chapéu acompanhe o gato na tela através da
manipulação de estilos (style.top, style.left)
*/

// Mover gato e chapéu automaticamente dentro de box 
const gato = document.getElementById("gato");
const chapeu = document.getElementById("chapeu");
const box = document.querySelector(".box");

let angulo = Math.PI / 2;

function animarGato(time, lastTime) {
    if (lastTime != null) {
        angulo += (time - lastTime) * 0.0007; // velocidade
    }

    // Pega o tamanho da caixa e do gato
    const centroX = box.clientWidth / 2;
    const centroY = box.clientHeight / 2;
    const raioX = box.clientWidth * 0.40; // 40% da largura
    const raioY = box.clientHeight * 0.30; // 30% da altura

    // Posição do gato
    const gatoX = centroX + Math.cos(angulo) * raioX - gato.width / 2;
    const gatoY = centroY + Math.sin(angulo) * raioY - gato.height / 2;

    // Atualiza posição com base em seno e cosseno
    gato.style.left = gatoX + "px";
    gato.style.top = gatoY + "px";

    // Posiciona o chapéu logo acima do gato
    const offsetChapeu = -43; // distância vertical
    const ajusteHorizontal = gato.width * 0.10; // distância horizontal

    chapeu.style.left = gatoX + ajusteHorizontal + "px";
    chapeu.style.top = gatoY - offsetChapeu + "px";

    // Anima
    requestAnimationFrame((newTime) => animarGato(newTime, time));
};

requestAnimationFrame(animarGato);
