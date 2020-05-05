#! /usr/bin/python
# -*- coding:utf-8 -*-


class Node:
    def __init__(self, data):
        self.data = data
        self.prevNode = None
        self.nextNode = None

class Stack:
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
            if currentNode == self.headNode:
                return

    def Append(self, data):
        appendNode = Node(data)
        if self.headNode is None:
            self.headNode = appendNode
            self.tailNode = self.headNode
        else:
            currentNode = self.tailNode
            currentNode.nextNode = appendNode
            appendNode.prevNode = currentNode
            self.tailNode = appendNode
        self.tailNode.nextNode = self.headNode
        self.headNode.prevNode = self.tailNode
        self.elementCount += 1

    def Pop(self):
        if self.headNode is None:
            print("데이터가 없습니다. pop실패")
            return
        popNode = self.tailNode
        data = popNode.data
        self.tailNode = popNode.prevNode
        self.tailNode.nextNode = self.headNode
        self.headNode.prevNode = self.tailNode
        popNode = None
        self.elementCount -= 1
        return data


if __name__ == '__main__':
    stack = Stack()
    stack.PrintData()
    print('스택 사이즈 : ', stack.GetSize())

    stack.Append(100)
    stack.PrintData()
    print('스택 사이즈 : ', stack.GetSize())

    for i in range(1, 10):
        stack.Append(i)
    stack.PrintData()
    print('스택 사이즈 : ', stack.GetSize())

    print('Pop 데이터 : ', stack.Pop())
    print('Pop 데이터 : ', stack.Pop())
    stack.PrintData()
    print('스택 사이즈 : ', stack.GetSize())



