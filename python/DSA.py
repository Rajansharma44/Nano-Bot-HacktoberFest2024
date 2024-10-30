
#1. Two Sum Problem
#Question: Given an array of integers, return the indices of the two numbers that add up to a specific target.
def two_sum(nums, target):
    hashmap = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in hashmap:
            return [hashmap[complement], i]
        hashmap[num] = i
#2. Reverse a Linked List
#Question: Reverse a singly linked list.
def reverse_linked_list(head):
    prev = None
    current = head
    while current:
        next_temp = current.next
        current.next = prev
        prev = current
        current = next_temp
    return prev
#3. Merge Intervals
#Question: Given a collection of intervals, merge all overlapping intervals.
def merge_intervals(intervals):
    if not intervals:
        return []
    intervals.sort(key=lambda x: x[0])
    merged = [intervals[0]]
    for current in intervals[1:]:
        last_merged = merged[-1]
        if current[0] <= last_merged[1]:
            last_merged[1] = max(last_merged[1], current[1])
        else:
            merged.append(current)
    return merged
#4. Binary Search
#Question: Implement binary search on a sorted array.
def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1
#5. Find the Missing Number
#Question: Given an array containing 
#n distinct numbers taken from 
#0,1,2,...,n, find the one number that is missing.
def missing_number(nums):
    n = len(nums)
    expected_sum = n * (n + 1) // 2
    actual_sum = sum(nums)
    return expected_sum - actual_sum
  
#6. Kth Largest Element in an Array
#Question: Find the kth largest element in an unsorted array.
def find_kth_largest(nums, k):
    nums.sort()
    return nums[-k]
#7. Valid Parentheses
#Question: Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
def is_valid(s):
    stack = []
    mapping = {')': '(', '}': '{', ']': '['}
    for char in s:
        if char in mapping:
            top_element = stack.pop() if stack else '#'
            if mapping[char] != top_element:
                return False
        else:
            stack.append(char)
    return not stack
  
#8. Flood Fill
#Question: Implement the flood fill algorithm (like a paint bucket tool in graphics).
def flood_fill(image, sr, sc, new_color):
    original_color = image[sr][sc]
    if original_color == new_color:
        return image
    
    def dfs(r, c):
        if image[r][c] == original_color:
            image[r][c] = new_color
            if r >= 1: dfs(r - 1, c)
            if r + 1 < len(image): dfs(r + 1, c)
            if c >= 1: dfs(r, c - 1)
            if c + 1 < len(image[0]): dfs(r, c + 1)

    dfs(sr, sc)
    return image
