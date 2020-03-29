# -*- coding: utf-8 -*-
#URI 1076
def criarLab():
    ini = input()
    labirinto = {}

    v, a = input().split()
    v = int(v)
    a = int(a)

    for vert in range(v):
        labirinto[str(vert)] = []

    for ares in range(a):
        iniA, fimA = input().split()

        labirinto[iniA].append(fimA)
        labirinto[fimA].append(iniA)

    return ini, labirinto


def percorrerLab(ini, labirinto, movim):
    if not labirinto[ini]:
        return movim

    while labirinto[ini]:
        movim += 1
        prox = labirinto[ini].pop(0)

        while prox in labirinto[ini]:
            labirinto[ini].remove(prox)

        while ini in labirinto[prox]:
            labirinto[prox].remove(ini)

        movim = percorrerLab(prox, labirinto, movim)
        movim += 1

    return movim


def main():
    testes = int(input())

    for i in range(testes):
        ini, labirinto = criarLab()
        movim = percorrerLab(ini, labirinto, 0)

        print(movim)

    return 0


if __name__ == '__main__':
    main()
