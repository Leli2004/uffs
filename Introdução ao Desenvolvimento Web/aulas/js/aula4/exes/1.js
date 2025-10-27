/* 
1) Faça com que o conteúdo passado como input (<input>) seja inserido em uma lista 
não ordenada quando o botão for clicado.
*/

function addElementLi(isAddInInicio) {
    // 1) pega o valor do input
    let inputText = document.getElementById("textoInput");
    let text = inputText.value; 

    // 2) cria o novo <li>
    let newLi = document.createElement("li");
    let node = document.createTextNode(text);
    newLi.appendChild(node);

    // 3) encontra a <ul>
    let div = document.getElementById("div1");
    let ul = div.getElementsByTagName("ul");

    // 4) insere na lista
    if (isAddInInicio) {
        ul[0].insertBefore(newLi, ul[0].firstChild);
    } else {
        ul[0].appendChild(newLi);
    }
};

let botaoIni = document.getElementById("botao-ini");
botaoIni.addEventListener("click", () => addElementLi(true));

let botaoFim = document.getElementById("botao-fim");
botaoFim.addEventListener("click", () => addElementLi(false));
