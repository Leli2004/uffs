// Alterar cor do de um texto
let botao = document.getElementById("botao");
botao.addEventListener("click", function() {
    const e = document.getElementById("texto");
    let cor = prompt("Informe a cor RGB:");
    cor = cor.toLowerCase();

    switch (cor) {
        case "red": 
            e.style.color = "red";
            break;
        case "green": 
            e.style.color = "green";
            break;
        case "blue": 
            e.style.color = "blue";
            break;
        default: 
            e.style.color = "black";
            e.textContent = "Cor inválida. Tente Novamente!";
    }
});

// Manipular exibição de um texto
let botao1 = document.getElementById("b1");
botao1.addEventListener("click", function() {
    document.getElementById('p1').style.visibility = 'hidden';
});

let botao2 = document.getElementById("b2");
botao2.addEventListener("click", function() {
    document.getElementById('p1').style.visibility = 'visible';
});
