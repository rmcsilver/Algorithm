#! /usr/bin/python
# -*- coding:utf-8 -*-


class HashTable:
    def __init__(self, size=10):
        self.size = size
        self.value_array = []
        self.total_entries = 0
        for i in range(self.size):
            self.value_array.append(None)

    def hash1(self, key):
        return id(key) % self.size

    def hash2(self, key):
        hashval = (id(key) + 501) % self.size
        return hashval

    def add(self, key, value):
        self.add_internal(key, value, self.value_array, self.size)

    def add_internal(self, key, value, value_array, size, during_resize=False):
        if value_array[self.hash1(key)] is None:
            value_array[self.hash1(key)] = key, value
        else:
            # find the next slot
            added = False
            attempt_count = 1
            while (not added):
                newhash = \
                    (self.hash1(key) + attempt_count * self.hash2(key)) % size
                if value_array[newhash] is None:
                    value_array[newhash] = key, value
                    added = True
                else:
                    attempt_count += 1
        if not during_resize:
            self.total_entries += 1
            if self.total_entries > size / 2:
                self.resize()

    def get(self, key):
        got_value = self.value_array[self.hash1(key)]
        if got_value is None:
            return None
        retrieved_key, retrieved_value = got_value
        if retrieved_key != key:
            found = False
            attempt_count = 1
            while (not found and attempt_count < 50):
                newhash = (self.hash1(key) + attempt_count * self.hash2(key)) \
                    % self.size
                value_at_hash = self.value_array[newhash]
                if value_at_hash is not None:
                    retrieved_key, retrieved_value = value_at_hash
                    if retrieved_key == key:
                        found = True
                    attempt_count += 1
                else:
                    attempt_count += 1
        return retrieved_value

    def resize(self):
        new_value_array = []
        new_size = 2 * self.size
        for i in range(self.size*2):
            new_value_array.append(None)
        for i in range(self.size):
            if self.value_array[i] is not None:
                self.add_internal(self.value_array[i][0], self.value_array[i][1], \
                                  new_value_array, new_size, True)
        self.value_array = new_value_array
        self.size = new_size



"""
hash_table = list([0 for i in range(8)])


def get_key(data):
    return hash(data)


def hash_function(key):
    return key % 8

def save_data(data, value):
    hash_address = hash_function(get_key(data))
    hash_table[hash_address] = value


def read_data(data):
    hash_address = hash_function(get_key(data))
    return hash_table[hash_address]
"""

if __name__ == "__main__":
    hash = HashTable(2)
    hash.add("Meo", "Smith")
    print(hash.get("Meo"))
    print("hash size :", hash.size)
    hash.add("Kao", "Talk")
    print(hash.get("Kao"))
    print("hash size :", hash.size)
    # save_data("Dave", 211011213)
    # save_data("ANdy", 110212313)
    # print(read_data("Dave"))
    # print(hash_table)


