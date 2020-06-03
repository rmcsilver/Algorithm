#! /usr/bin/python
# -*- coding:utf-8 -*-


class HashTable:
    def __init__(self, size=13):
        self.size = size
        self.table = [0 for i in range(size)]
        self.entry_count = 0

    def hash(self, key):
        # print(id(key))
        # return ord(key) % size
        return id(key) % self.size

    def hash_horner(self, key):
        prime = 577
        return (id(key) * prime) % self.size

    def add(self, key, value):
        self.add_internal(key, value, self.table, self.size)

    def add_internal(self, key, value, table, size, resizing=False):
        if table[self.hash(key)] == 0:
            table[self.hash(key)] = key, value
        else:
            result = False
            attempt_count = 0
            while result is False:
                hash_value = (self.hash_horner(key) + attempt_count) % size
                if table[hash_value] is None:
                    table[hash_value] = key, value
                    result = True
                else:
                    attempt_count += 1
        if resizing is False:
            self.entry_count += 1
            if self.entry_count > size * 0.7:
                self.resize()

    def resize(self):
        new_size = self.size * 2
        new_table = [None for _ in range(new_size)]
        for i in range(self.size):
            if self.table[i] != 0:
                self.add_internal(self.table[i][0], self.table[i][1], new_table, new_size, True)
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


