#! /user/bin/python
# -*- coding:utf-8 -*-


def draw_pyramid(inv=False, degree=10):
    print('pyramid')


def draw_halfpyramid(inv=False, degree=10):
    print('half pyramid')


def draw_whelk(w=10, h=10):
    whelk = [[0 for col in range(w)] for row in range(h)]

    num = 1
    lshell = 0
    rshell = 0
    tshell = 0
    bshell = 0

    while num <= (w*h):
        # T -> R
        for i in range(lshell, w-rshell):
            whelk[i][tshell] = num
            num += 1
        tshell += 1

        # T -> B
        for j in range(tshell, h-bshell):
            whelk[i][j] = num
            num += 1
        rshell += 1

        # R -> L
        for k in reversed(range(lshell, w-rshell)):
            whelk[k][j] = num
            num += 1
        bshell += 1

        # B -> T
        for l in reversed(range(tshell, h-bshell)):
            whelk[k][l] = num
            num += 1
        lshell += 1

    maxnum = 100

    for y in range(w):
        for x in range(h):
            if not whelk[x][y] == maxnum:
                print('%3d' % whelk[x][y], end='\t')
            else:
                print('%d' % whelk[x][y], end='\t')
        print('')

if __name__ == '__main__':
    draw_whelk(10, 10)
