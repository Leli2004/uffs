// Script para sidebar
// a. para ocultar ou exibir o sidebar na tela
// b. para transformar sidebar num menu lateral

document.addEventListener("DOMContentLoaded", function () {
  const btn = document.getElementById("toggle-sidebar");
  const sidebar = document.querySelector(".sidebar");

  // Script para esconder ou exibir sidebar
  btn.addEventListener("click", function () {
    if (sidebar.style.display === "none") {
      sidebar.style.display = "block";
      btn.textContent = "Ocultar personagens";
    } else {
      sidebar.style.display = "none";
      btn.textContent = "Mostrar personagens";
    }
  });

  // Script para sidebar virar menu, para telas pequenas
  const openMobileBtn = document.getElementById("open-sidebar-mobile");
  const closeMobileBtn = document.getElementById("close-sidebar-mobile");

    if (openMobileBtn) {
        openMobileBtn.addEventListener("click", function () {
            sidebar.style.display = "block";
        });
    }

    if (closeMobileBtn) {
        closeMobileBtn.addEventListener("click", function () {
            sidebar.style.display = "none";
        });
    }

    window.addEventListener("resize", function () {
      if (window.innerWidth <= 600) {
          // no mobile, sidebar sempre começa oculto
          sidebar.style.display = "none";
      }
    });
});
