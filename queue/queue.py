#! /usr/bin/python
# -*- coding:utf-8 -*-

# 연습문제 : 리스트 변수로 큐로 다루는 enqueue, dequeue 기능 구현해보기

queue_list = list()

def enqueue(data):
    queue_list.append(data)

def dequeue():
    data = queue_list[0]
    del queue_list[0]
    return data

for index in range(10):
    enqueue(index)

print(len(queue_list))

print(dequeue())

