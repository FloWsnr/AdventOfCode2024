"""
Advent of Code 2024, Day 1

By: Florian Wiesner
Date: 2024-12-01
"""

from pathlib import Path


def read_file(path: Path) -> tuple:
    l1 = []
    l2 = []

    with open(path) as f:
        for line in f.readlines():
            line = line.strip()
            elements = line.split()
            l1.append(int(elements[0]))
            l2.append(int(elements[1]))

    return l1, l2


def sort(list_to_sort: list) -> list:
    sorted_list = []
    while len(list_to_sort) > 0:
        max_element = 0
        max_index = 0
        for i in range(len(list_to_sort)):
            element = list_to_sort[i]
            if element > max_element:
                max_element = element
                max_index = i

        sorted_list.insert(0, max_element)
        del list_to_sort[max_index]

    # print(sorted_list)
    return sorted_list


def sum_distances(list1: list, list2: list) -> int:
    length = len(list1)

    sum_dist = 0
    for i in range(length):
        l1_entry = list1[i]
        l2_entry = list2[i]

        distance = abs(l1_entry - l2_entry)
        sum_dist = sum_dist + distance

    return sum_dist


def similarity_score(list1: list, list2: list) -> int:
    score = 0
    for i in list1:
        count = 0
        for j in list2:
            if i == j:
                count = count + 1

        score = (i * count) + score

    return score


if __name__ == "__main__":
    x, y = read_file("/home/flwi/Coding/AdventOfCode2024/day1/day1_input.txt")
    # test_x = [3, 4, 2, 1, 3, 3]
    # test_y = [4, 3, 5, 3, 9, 3]

    # sorted_x = sort(x)
    # sorted_y = sort(y)

    # sum_dist = sum_distances(sorted_x, sorted_y)
    # print(sum_dist)

    score = similarity_score(x, y)
    print(score)
