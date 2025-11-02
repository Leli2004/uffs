
document.addEventListener("DOMContentLoaded", function () {
  const btn = document.getElementById("toggle-sidebar");
  const sidebar = document.querySelector(".sidebar");

  btn.addEventListener("click", function () {
    if (sidebar.style.display === "none") {
      sidebar.style.display = "block";
      btn.textContent = "Ocultar menu de personagens";
    } else {
      sidebar.style.display = "none";
      btn.textContent = "Mostrar menu de personagens";
    }
  });
});
