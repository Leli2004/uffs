let botaoTema = document.getElementById("toggle-theme");

// Adiciona ouvinte para o evento de clique
botaoTema.addEventListener("click", function() {
  // Alterna a classe "dark-mode" no body
  document.body.classList.toggle("dark-mode");

  // Muda o texto do botão conforme o modo ativo
  if (document.body.classList.contains("dark-mode")) {
    botaoTema.textContent = "☀️ Modo Claro";
  } else {
    botaoTema.textContent = "🌙 Modo Escuro";
  }
});
