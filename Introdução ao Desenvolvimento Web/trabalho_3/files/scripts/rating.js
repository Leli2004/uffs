// Script para simular envio de formulário

// Ao clicar em 'adicionar avaliação', exibe o formulário
document.addEventListener('DOMContentLoaded', () => {
  const addReviewBtn = document.getElementById('add-review-btn');
  const reviewForm = document.getElementById('review-form');
  const reviewMessage = document.getElementById('review-form-message');

  addReviewBtn.addEventListener('click', () => {
    addReviewBtn.style.display = 'none';
    reviewForm.style.display = 'block';
    reviewMessage.textContent = '';
  });

  // Envio do formulário
  reviewForm.addEventListener('submit', (e) => {
    e.preventDefault();

    const email = reviewForm.email.value.trim();

    // Exibe mensagem de sucesso e substitui o formulário por mensagem de sucesso
    reviewForm.style.display = 'none';
    reviewMessage.textContent = `Avaliação enviada com sucesso! \nVerifique seu email "${email}" para confirmar.`;
  });
});
