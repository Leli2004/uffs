# Sistema AmazonCC

#############################################################################################
# Clientes

clientes = [] # [cpf, nome, senha, email, limite]

def isValidCPF(cpf):
    if len(cpf) != 11:
        return False
    if not cpf.isdigit():
        return False
    return True

### newCliente adiciona um cliente à matriz clientes e valida o cpf
def newCliente(cpf, nome, senha, email):
    if len(senha) != 6:
        return "Erro: Senha deve conter 6 caracteres"
    
    if cpf == "":
        return "Erro: CPF é obrigatório"
    
    if not isValidCPF(cpf):
        return "Erro: Formato de CPF inválido"

    for c in clientes:
        if c[0] == cpf:
            return "Erro: CPJ já existe"
        
    limite = 1000
    cliente = [cpf, nome, senha, email, limite]
    clientes.append(cliente)
    return "Cliente cadastrado com sucesso!"

### getCliente retorna um cliente
def getCliente(cpf):
    for c in clientes:
        if c[0] == cpf:
            return c
    return None

### listarClientes retorna lista de clientes cadastrados
def listarClientes():
    print("\n=== Lista de Clientes ===")
    if len(clientes) == 0:
        print("Nenhum cliente cadastrado.")
        return

    for c in clientes:
        print(f"CPF: {c[0]}, Nome: {c[1]}, Email: {c[3]}, Limite: R$ {c[4]:.2f}")

#############################################################################################
# Produtos

items = [] # [codigo, descricao, valor]

### newItem adiciona novo item à matriz items
def newItem(codigo, descricao, valor):
    if codigo == "":
        return "Erro: Código do item é obrigatório"
    
    if valor <= 0:
        return "Erro: Valor do item deve ser maior que zero"
    
    for i in items:
        if i[0] == codigo:
            return "Erro: Código do item já existe"

    item = [codigo, descricao, valor]
    items.append(item)
    return "Item cadastrado com sucesso!"

### listarItens retorna os itens cadastrados
def listarItens():
    print("\n=== Lista de Itens ===")
    for i in items:
        print(f"{i[0]} - {i[1]} - R$ {i[2]:.2f}")

### getValorItem retorna o valor do item
def getValorItem(codigo):
    for i in items:
        if i[0] == codigo:
            return i[2]
    return 0

#############################################################################################
# Carrinho

carrinhos = [] # [ [cpf, [lista_de_codigos]] ]

# getCarrinho retorna o carrinho do cliente
def getCarrinho(cpf):
    for c in carrinhos:
        if c[0] == cpf:
            return c

    novo = [cpf, []]
    carrinhos.append(novo)
    return novo

# newCarrinho cria ou atualiza novo carrinho para o cliente
def newCarrinho(cpf, codigo, qtd):
    carrinho = getCarrinho(cpf)
    carrinho[1].append([codigo, qtd])
    return

# getTotalCarrinho retorna o valor total do carrinho do cliente
def getTotalCarrinho(cpf):
    carrinho = getCarrinho(cpf)
    total = 0
    for item in carrinho[1]:
        codigo = item[0]
        qtd = item[1]
        total += getValorItem(codigo) * qtd
    return total

# getItemsCarrinho retorna os itens do carrinho do cliente
def getItemsCarrinho(cpf):
    carrinho = getCarrinho(cpf)
    return carrinho[1]


#############################################################################################
# Compras

### compraAllowed verifica se o cliente ainda possui crédito para compra
def compraAllowed(cpf, valor):
    cliente = getCliente(cpf)
    if cliente is None:
        return False
    if cliente[4] < valor:
        return False
    return True

### diminuiLimite remove valor da compra do limite do cliente
def diminuiLimite(cpf, valor):
    cliente = getCliente(cpf)
    cliente[4] -= valor
    return

compras = [] # [cpf, codigo]

### newCompra cria nova compra
def newCompra(cpf, codigo, qtd):
    valorItem = getValorItem(codigo)

    if valorItem == 0:
        return "Erro: Item não encontrado"
    
    valorTotal = valorItem * qtd

    if not compraAllowed(cpf, valorTotal):
        return "Erro: Cliente não possui limite para realizar essa compra"

    diminuiLimite(cpf, valorTotal)
    newCarrinho(cpf, codigo, qtd)
    compras.append([cpf, codigo, qtd])
    return "Compra realizada com sucesso!"

#############################################################################################
# Pagamento

### aumentaLimite adiciona valor pago no limite do cliente
def aumentaLimite(cpf):
    cliente = getCliente(cpf)
    if cliente is None:
        return "Erro: Cliente não encontrado"
    
    total = getTotalCarrinho(cpf)
    cliente[4] += total  # devolve limite
    getCarrinho(cpf)[1].clear()  # esvazia carrinho

    return "Pagamento realizado! Carrinho zerado e limite restaurado."

#############################################################################################
# main - interação
def main():
    while True:
        print("\n=== SISTEMA AMAZON CC ===")
        print("1 - Cadastrar cliente")
        print("2 - Cadastrar item")
        print("3 - Comprar item")
        print("4 - Mostrar carrinho")
        print("5 - Pagar")
        print("6 - Listar itens")
        print("7 - Listar clientes")
        print("0 - Sair")

        op = input("\nEscolha uma opção: ")

        if op == "1":
            cpf = input("CPF: ")
            nome = input("Nome: ")
            senha = input("Senha (6 dígitos): ")
            email = input("Email: ")
            resultado = newCliente(cpf, nome, senha, email)
            if "Erro" in resultado:
                print("\nAÇÃO INVÁLIDA - ", resultado)
            else:
                print(resultado)

        elif op == "2":
            codigo = input("Código do item: ")
            descricao = input("Descrição: ")
            valor = float(input("Valor: "))
            resultado = newItem(codigo, descricao, valor)
            if "Erro" in resultado:
                print("\nAÇÃO INVÁLIDA - ", resultado)
            else:
                print(resultado)

        elif op == "3":
            cpf = input("CPF: ")
            codigo = input("Código do item: ")
            qtd = int(input("Quantidade: "))
            resultado = newCompra(cpf, codigo, qtd)
            if "Erro" in resultado:
                print("\nAÇÃO INVÁLIDA - ", resultado)
            else:
                print(resultado)

        elif op == "4":
            cpf = input("CPF: ")
            print("Itens no carrinho:", getItemsCarrinho(cpf))
            print("Total:", getTotalCarrinho(cpf))

        elif op == "5":
            cpf = input("CPF: ")
            print(aumentaLimite(cpf))

        elif op == "6":
            listarItens()

        elif op == "7":
            listarClientes()

        elif op == "0":
            print("Saindo...")
            break

        else:
            print("Opção inválida. Tente novamente")

# Inicializa main
main()
