#VERIFICA INTERSECAO
def SubArrayMaxInt(lista, ini, meio, fim):
  somaE = float('-inf')
  indiceE = -1
  soma = 0
  #VERIFICA A MAIOR SOMA DA ESQUERDA A PARTIR DO MEIO
  for i in range(meio, -1, -1):
    soma += lista[i]
    if soma > somaE:
      indiceE = i
      somaE = soma

  somaD = float('-inf')
  indiceD = -1
  soma = 0
  #VERIFICA A MAIOR SOMA DA DIREITA A PARTIR DO MEIO
  for i in range(meio+1, fim+1):
    soma += lista[i]
    if soma > somaD:
      indiceD = i
      somaD = soma

  return (indiceE, indiceD, somaE + somaD)


def SubArrayMax(lista, ini, fim):
  if ini == fim:
    return (ini, fim, lista[ini])

  meio = (ini+fim)//2
  #print(meio)

  maxE = SubArrayMax(lista, ini, meio)
  maxD = SubArrayMax(lista, meio+1, fim)
  maxI = SubArrayMaxInt(lista, ini, meio, fim)
  #print(maxI)

  if maxE[2] > maxD[2] and maxE[2] > maxI[2]:
    return maxE
  elif maxD[2] > maxE[2] and maxD[2] > maxI[2]:
    return maxE
  else:
    return maxI

#TESTE
def main():
  lista = []
  n = int(input("Tamanho: "))

  for i in range(n):
    lista.append(int(input()))

  maxArray = SubArrayMax(lista, 0, len(lista) - 1)

  print(maxArray)

if __name__ == "__main__":
  main()
