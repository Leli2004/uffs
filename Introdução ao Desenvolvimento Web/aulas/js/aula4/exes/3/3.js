/*
3) Escreva uma página que aumente o tamanho de um Emoji quando pressionar a seta para cima (arrowUp), e
diminua de tamanho quando pressionar a tecla para baixo (arrowDown).
*/

const emoji = document.getElementById("emoji");
let tamanho = emoji.width;

function changeEmoji(e) {
    if (e.key === "ArrowUp") {
        tamanho += 10;
    } else if (e.key === "ArrowDown") {
        tamanho -= 10;
    }
    emoji.width = tamanho;
};

document.addEventListener("keydown", (e) => changeEmoji(e));
