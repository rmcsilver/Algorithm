#! /usr/bin/python
# -*- coding:utf-8 -*-

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


if __name__ == "__main__":
    save_data("Dave", 211011213)
    save_data("ANdy", 110212313)
    print(read_data("Dave"))
    print(hash_table)
