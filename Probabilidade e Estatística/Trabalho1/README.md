# Probabilidade e Estatística — 2026.2

**Universidade Federal da Fronteira Sul (UFFS) — Campus Chapecó**  
**Curso:** Ciência da Computação  

**Estudantes:**  
| Nome | GitHub |
|------|--------|
| Danieli N. Dalla Vecchia | [@Leli2004](https://github.com/Leli2004) |
| Marina de A. Canal | [@marinacanal](https://github.com/marinacanal) |

---

## Trabalho 1 — Distribuição Binomial

**Linguagem escolhida:** C++

**Para executar, rodar no terminal:**

```bash
make run
```

Este trabalho consiste na implementação, em uma linguagem de programação de preferência, da fórmula da **distribuição binomial**:

```P(x) = Cn,x . (p)^x. (q)^(n-x) ```  

Onde:

- \(n\) representa o número total de experimentos;
- \(x\) representa o número de sucessos;
- \(p\) representa a probabilidade de sucesso;
- \(q = 1 - p\) representa a probabilidade de fracasso;

### Funcionalidades

O programa deve calcular:

1. **Probabilidade Binomial Individual**  
   Calcula a probabilidade de ocorrer exatamente \(x\) sucessos: P = x

2. **Probabilidade Binomial Acumulada**  
   Calcula a probabilidade de ocorrerem até \(x\) sucessos: P <= x
