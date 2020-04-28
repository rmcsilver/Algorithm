#! /usr/bin/python
# -*- coding:utf-8 -*-

# 4. 파이썬 리스트 기능에서 제공하는 메서드로 스택 사용해보기

data_stack = list()

data_stack.append(1)
data_stack.append(2)

print(data_stack)

print(data_stack.pop())


# 5. 프로그래밍 연습
# 연습1: 리스트 변수로 스택을 다루는 pop, push 기능 구현해보기
# (pop, push 함수 사용하지 않고 직접 구현해보기)

stack = list()


def push(data):
    stack.append(data)
    print(data, ' -> push')


def pop():
    # data = stack[len(stack)-1]
    # del stack[len(stack)-1]
    data = stack[-1]
    del stack[-1]
    print(data, ' -> pop')
    return data


for index in range(10):
    push(index)

pop()
