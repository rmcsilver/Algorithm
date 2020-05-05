#! /usr/bin/python
# -*- coding:utf-8 -*-


class Node:
    def __init__(self, data):
        self.data = data
        self.prevNode = None
        self.nextNode = None


class Queue:
    def __init__(self):
        self.headNode = None
        self.tailNode = None
        self.elementCount = 0

    def GetSize(self):
        return self.elementCount

    def PrintData(self):
        if self.headNode is None:
            print("출력할 데이터가 없습니다.")
            return
        count = 0
        currentNode = self.headNode
        while currentNode:
            count += 1
            print(count, '번째 데이터 : ', currentNode.data)
            currentNode = currentNode.nextNode
            if currentNode is self.headNode:
                return

    def Enqueue(self, data):
        insertNode = Node(data)
        if self.headNode is None:
            self.headNode = insertNode
            self.tailNode = self.headNode
        else:
            currentNode = self.headNode
            currentNode.prevNode = insertNode
            insertNode.nextNode = currentNode
            self.headNode = insertNode

        self.headNode.prevNode = self.tailNode
        self.tailNode.nextNode = self.headNode
        self.elementCount += 1

    def Dequeue(self):
        if self.headNode is None:
            print("데이터가 없습니다.")

        popNode = self.tailNode
        data = popNode.data
        if popNode == self.headNode:
            self.HeadNode = None
            self.TailNode = None
        else:
            self.tailNode = popNode.prevNode
            self.tailNode.nextNode = self.headNode
            self.headNode.prevNode = self.tailNode
        popNode = None
        self.elementCount -= 1
        return data


if __name__ == '__main__':
    queue = Queue()
    queue.PrintData()
    print('큐 사이즈 : ', queue.GetSize())

    queue.Enqueue(10)
    queue.PrintData()
    print('큐 사이즈 : ', queue.GetSize())

    for i in range(1, 10):
        queue.Enqueue(i)
    queue.PrintData()
    print('큐 사이즈 : ', queue.GetSize())

    print('Dequeue : ', queue.Dequeue())
    print('Dequeue : ', queue.Dequeue())
    queue.PrintData()
    print('큐 사이즈 : ', queue.GetSize())


