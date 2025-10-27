/*
2) Coloque um chapéu em cima do gato (<img>) e faça com que o chapéu acompanhe o gato na tela através da
manipulação de estilos (style.top, style.left)
*/

// const gato = document.getElementById("gato");
// let angulo = Math.PI / 2;
// function animarGato(tempo, ultimoTempo) {
//     if (ultimoTempo != null) {
//         angulo += (tempo - ultimoTempo) * 0.001; // velocidade
//     }
//     // Pega o tamanho da caixa e do gato
//     const box = document.querySelector(".box");
//     const centroX = box.clientWidth / 2;
//     const centroY = box.clientHeight / 2;
//     const raioX = 300; // horizontal
//     const raioY = 150; // vertical
//     // Atualiza posição com base em seno e cosseno
//     gato.style.left = centroX + Math.cos(angulo) * raioX - gato.width / 2 + "px";
//     gato.style.top = centroY + Math.sin(angulo) * raioY - gato.height / 2 + "px";
//     requestAnimationFrame((novoTempo) => animarGato(novoTempo, tempo));
// };
// requestAnimationFrame(animarGato);

const gato = document.getElementById("gato");
const chapeu = document.getElementById("chapeu");
let angulo = Math.PI / 2;

function animarGato(tempo, ultimoTempo) {
    if (ultimoTempo != null) {
        angulo += (tempo - ultimoTempo) * 0.0006; // velocidade
    }

    // Pega o tamanho da caixa e do gato
    const box = document.querySelector(".box");
    const centroX = box.clientWidth / 2;
    const centroY = box.clientHeight / 2;
    const raioX = 300; // horizontal
    const raioY = 150; // vertical

    // Posição do gato
    const gatoX = centroX + Math.cos(angulo) * raioX - gato.width / 2;
    const gatoY = centroY + Math.sin(angulo) * raioY - gato.height / 2;

    // Atualiza posição com base em seno e cosseno
    gato.style.left = gatoX + "px";
    gato.style.top = gatoY + "px";

    // Posiciona o chapéu logo acima do gato
    const offsetChapeu = -43; // menor distância vertical (desce o chapéu)
    const ajusteHorizontal = gato.width * 0.10; // move o chapéu mais à direita

    chapeu.style.left = gatoX + ajusteHorizontal + "px";
    chapeu.style.top = gatoY - offsetChapeu + "px";

    // Anima
    requestAnimationFrame((novoTempo) => animarGato(novoTempo, tempo));
};

requestAnimationFrame(animarGato);
