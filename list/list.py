#! /usr/bin/python
# -*- coding:utf-8 -*-


class Node:
    def __init__(self, data):
        self.data = data
        self.prevNode = None
        self.nextNode = None


class LinkedList:
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

    def InsertData(self, data):
        insertNode = Node(data)
        if self.headNode is None:
            self.headNode = insertNode
            self.tailNode = self.headNode
        else:
            currentNode = self.tailNode
            currentNode.nextNode = insertNode
            insertNode.prevNode = currentNode
            self.tailNode = insertNode
        self.headNode.prevNode = self.tailNode
        self.tailNode.nextNode = self.headNode
        self.elementCount += 1

    def DeleteData(self, data):
        if self.headNode is None:
            print("삭제할 데이터가 없습니다.")
            return False
        deleteNode = self.headNode
        if deleteNode.data == data:
            if deleteNode == self.tailNode:
                self.headNode = None
                self.tailNode = None
            else:
                self.headNode = deleteNode.nextNode
                self.headNode.prevNode = self.tailNode
                self.tailNode.nextNode = self.headNode
            deleteNode = None
            self.elementCount -= 1
            return True

        while deleteNode:
            if deleteNode.data == data:
                if deleteNode == self.tailNode:
                    self.tailNode = deleteNode.prevNode
                    self.tailNode.nextNode = self.headNode
                    self.headNode.prevNode = self.tailNode
                else:
                    deleteNode.prevNode.nextNode = deleteNode.nextNode
                    deleteNode.nextNode.prevNode = deleteNode.prevNode
                deleteNode = None
                self.elementCount -= 1
                return True
            deleteNode = deleteNode.nextNode

            if deleteNode is self.tailNode:
                print("데이터를 찾을 수 없습니다. 삭제 실패.")
                return False


if __name__ == '__main__':
    list = LinkedList()
    list.PrintData()
    print('링크드리스트 사이즈 : ', list.GetSize())

    list.InsertData(10)
    list.PrintData()
    print('링크드리스트 사이즈 : ', list.GetSize())

    for i in range(1, 10):
        list.InsertData(i)
    list.PrintData()
    print('링크드리스트 사이즈 : ', list.GetSize())

    list.DeleteData(100)
    list.DeleteData(10)
    list.DeleteData(5)
    list.PrintData()
    print('링크드리스트 사이즈 : ', list.GetSize())


