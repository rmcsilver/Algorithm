#! /usr/bin/python
# -*- coding:utf-8 -*-


class HashTable:
    def __init__(self, size=13):
        self.size = size
        self.table = list([0 for i in range(size)])
        self.entry_count = 0

    def hash(self, key):
        return id(key) % self.size

    def add(self, key, value):
        self.add_internal(key, value, self.table, self.size)

    def add_internal(self, key, value, table, size, resizing=False):
        index = self.hash(key)
        if table[index] == 0:
            table[index] = [[key, value]]
        else:
            for i in range(len(table[index])):
                if table[index][i][0] == key:
                    table[index][i][1] = value
                    return
            table[index].append([key, value])
        if resizing is False:
            self.entry_count += 1
            if self.entry_count > size * 0.7:
                self.resize()

    def resize(self):
        new_size = self.size * 2
        new_table = list([0 for i in range(new_size)])
        for i in range(self.size):
            if self.table[i] != 0:
                for j in range(len(self.table[i])):
                    self.add_internal(self.table[i][j][0], self.table[i][j][1], new_table, new_size, True)
        self.table = new_table
        self.size = new_size


if __name__ == "__main__":
    hash = HashTable(5)
    hash.add("Andy", "01Ta0123")
    print(hash.table)
    hash.add("bred", "1004Troy")
    hash.add("Tom", "andToms666")
    hash.add("Neyo", "becauseofyou")
    print(hash.table)

