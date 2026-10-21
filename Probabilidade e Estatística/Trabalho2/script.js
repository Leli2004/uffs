// Valores de z conforme a tabela da aula
const Z = { 90: 1.65, 95: 1.96, 99: 2.58 };

const $ = (id) => document.getElementById(id);
const num = (id) => ($(id).value.trim() === "" ? NaN : Number($(id).value));
const f = (v, d = 2) =>
  v.toLocaleString("pt-BR", { minimumFractionDigits: d, maximumFractionDigits: d });
const valor_resultado = (v) => f(v);
const pct = (v) => f(v * 100) + "%";

// ---------- Fator de correção finita: √((N-n)/(N-1)), usado se n > 5% de N ----------
function correcao(n, N) {
  if (isNaN(N)) return { usa: false, fator: 1, texto: "População muito grande (N não informado): não usa correção." };
  const razao = n / N;
  const usa = razao > 0.05;
  const fator = usa ? Math.sqrt((N - n) / (N - 1)) : 1;
  const texto = `n/N = ${n}/${N} = ${f(razao * 100, 1)}% ${usa ? "> 5%: usa correção" : "≤ 5%: não usa correção"}`;
  return { usa, fator, texto };
}

function mostrarErro(el, msg) {
  el.innerHTML = `<div class="msg-erro">${msg}</div>`;
}

function cartao(titulo, valor) {
  return `<div class="cartao"><small>${titulo}</small><strong>${valor}</strong></div>`;
}

// ---------- MÉDIA ----------
function calcularMedia() {
  const out = $("res-media");
  const xbar = num("m-media"), s = num("m-desvio"), n = num("m-n"), N = num("m-N");
  const conf = $("m-conf").value, z = Z[conf];

  if ([xbar, s, n].some(isNaN)) return mostrarErro(out, "Preencha a média, o desvio padrão e o tamanho da amostra.");
  if (n < 2 || !Number.isInteger(n)) return mostrarErro(out, "O tamanho da amostra (n) deve ser um inteiro maior ou igual a 2.");
  if (s < 0) return mostrarErro(out, "O desvio padrão não pode ser negativo.");
  if (!isNaN(N) && (N < n || !Number.isInteger(N))) return mostrarErro(out, "N deve ser um inteiro maior ou igual a n.");

  const c = correcao(n, N);
  const e = z * (s / Math.sqrt(n)) * c.fator;
  const li = xbar - e, ls = xbar + e;

  let html = '<div class="cartoes">' +
    cartao("Estimativa pontual (μ = x̄)", valor_resultado(xbar)) +
    cartao(`Intervalo de ${conf}% de confiança`, `${valor_resultado(li)} a ${valor_resultado(ls)}`) +
    cartao("Erro de estimação (e)", valor_resultado(e));
  if (!isNaN(N)) html += cartao("Valor total (N × intervalo)", `${valor_resultado(N * li)} a ${valor_resultado(N * ls)}`);
  html += "</div>";

  if (n < 30) html += `<div class="aviso">Com n &lt; 30, este método só vale se a população tiver distribuição normal (ou aproximadamente normal).</div>`;
  
  out.innerHTML = html;
}

// ---------- PROPORÇÃO ----------
function calcularProporcao() {
  const out = $("res-prop");
  const x = num("p-x"), n = num("p-n"), N = num("p-N");
  const conf = $("p-conf").value, z = Z[conf];

  if ([x, n].some(isNaN)) return mostrarErro(out, "Preencha x e o tamanho da amostra.");
  if (n < 1 || !Number.isInteger(n) || x < 0 || !Number.isInteger(x)) return mostrarErro(out, "x e n devem ser inteiros (n ≥ 1, x ≥ 0).");
  if (x > n) return mostrarErro(out, "x não pode ser maior que n.");
  if (!isNaN(N) && (N < n || !Number.isInteger(N))) return mostrarErro(out, "N deve ser um inteiro maior ou igual a n.");

  const p = x / n;
  const c = correcao(n, N);
  const e = z * Math.sqrt((p * (1 - p)) / n) * c.fator;
  const li = p - e, ls = p + e;

  let html = '<div class="cartoes">' +
    cartao("Estimativa pontual (p = x/n)", pct(p)) +
    cartao(`Intervalo de ${conf}% de confiança`, `${pct(li)} a ${pct(ls)}`) +
    cartao("Erro de estimação (e)", pct(e));
  if (!isNaN(N)) html += cartao("Número de itens na população", `${f(N * li, 0)} a ${f(N * ls, 0)}`);
  html += "</div>";

  out.innerHTML = html;
}

$("btn-media").addEventListener("click", calcularMedia);
$("btn-prop").addEventListener("click", calcularProporcao);
