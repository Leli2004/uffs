
# Heap (prioridade)

## Conceitos

Representado por um vetor.  
Cada posição do vetor é pai de outras duas posições.  
Heap-min e heap-max.  
Adiciona no vetor e depois reorganiza pra ficar em ordem de prioridade.   
Size -> indica o tamanho e tbm é usado no índice da próxima posição.     

### Heap-max:
- usaremos nas aulas como exemplo
- pai sempre é maior que seus filhos
- 2i+1 → posição do filho da esquerda
- 2i+2 → posição do filho da direita
- (i-1)÷2 (int) → posição do pai
- na remoção, sempre irá remover e v[0] (maior valor numa heap-max)
