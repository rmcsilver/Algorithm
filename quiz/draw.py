#! /user/bin/python
# -*- coding:utf-8 -*-
import math


def draw_pyramid(inv=False, degree=10):
    width = (degree - 1) * 2 + 1
    pyramid = [[0 for col in range(width)] for row in range(degree)]

    index = 0
    for h in range(degree):
        index = 0
        if inv is True:
            blank = h * 2 + 1
            star = int((width - blank) / 2)
        else:
            star = h * 2 + 1
            blank = int((width - star) / 2)

        # left blank
        for i in range(blank):
            pyramid[h][index] = ' '
            index += 1

        # center star
        for j in range(width - (blank * 2)):
            pyramid[h][index] = "*"
            index += 1

        # right blank
        for k in range(blank):
            pyramid[h][index] = ' '
            index += 1

    for h in range(degree):
        for w in range(width):
            print(pyramid[h][w], end=' ')
        print(' ')


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
    # draw_whelk(10, 10)
    draw_pyramid(True, 10)
