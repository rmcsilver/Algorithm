#! /usr/bin/python
# -*- coding:utf-8 -*-


class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class BinaryTree:
    def __init__(self, head):
        self.head = head

    def insert(self, value):
        self.current_node = self.head
        while True:
            if value < self.current_node.value:
                if self.current_node.left is not None:
                    self.current_node = self.current_node.left
                else:
                    self.current_node.left = Node(value)
                    break
            else:
                if self.current_node.right is not None:
                    self.current_node = self.current_node.right
                else:
                    self.current_node.right = Node(value)
                    break

    def search(self, value):
        self.current_node = self.head
        while self.current_node:
            if self.current_node.value == value:
                return True
            elif value < self.current_node.value:
                self.current_node = self.current_node.left
            else:
                self.current_node = self.current_node.right
        return False

    def delete(self, value):
        searched = False
        self.current_node = self.head
        self.parent = self.head
        while self.current_node:
            if self.current_node.value == value:
                searched = True
                break
            elif value < self.current_node.value:
                self.parent = self.current_node
                self.current_node = self.current_node.left
            else:
                self.parent = self.current_node
                self.current_node = self.current_node.right

        if searched is False:
            return False

        if self.current_node.left is None and self.current_node.right is None:
            if value < self.parent.value:
                self.parent.left = None
            else:
                self.parent.right = None
            del self.current_node

        if self.current_node is not None and self.current_node.right is None:
            if value < self.parent.value:
                self.parent.left = self.current_node.left
            else:
                self.parent.right = self.current_node.left
        elif self.current_node is None and self.current_node.right is not None:
            if value < self.parent.value:
                self.parent.left = self.current_node.right
            else:
                self.parent.right = self.current_node.right

        if self.current_node.left is not None and self.current_node.right is not None:
            if value < self.parent.value:
                self.change_node = self.current_node.right
                self.change_node_parent = self.current_node.right
                while self.change_node.left is not None:
                    self.change_node_parent = self.change_node
                    self.change_node = self.change_node.left
                if self.change_node.right is not None:
                    self.change_node_parent.left = self.change_node.right
                else:
                    self.change_node_parent.left = None
                    self.parent.left = self.change_node
                self.change_node.right = self.current_node.right
                self.change_node.left = self.change_node.left

        else:
            self.change_node = self.current_node.right
            self.change_node_parent = self.current_node.right
            while self.change_node.left is not None:
                self.change_node_parent = self.change_node
                self.change_node = self.change_node.left
            if self.change_node.right is not None:
                self.change_node_parent.left = self.change_node.right
            else:
                self.change_node_parent.left = None
                self.parent.right = self.change_node
            self.change_node.left = self.current_node.left
            self.change_node.right = self.current_node.right


def PrintTree(node):
    if node is not None:
        print(node.value, end="->")
    if node.left is not None:
        PrintTree(node.left)
    if node.right is not None:
        PrintTree(node.right)


if __name__ == "__main__":
    head = Node(10)
    tree = BinaryTree(head)
    tree.insert(5)
    tree.insert(15)
    tree.insert(3)
    tree.insert(4)
    tree.insert(19)
    tree.insert(3.5)
    tree.insert(6)
    PrintTree(tree.head)
    print(tree.search(10))
    tree.delete(19)
    PrintTree(tree.head)

