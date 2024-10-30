class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None

    # Traverse and print the list
    def traversal(self):
        temp = self.head
        while temp:
            print(temp.data, end="\t")
            temp = temp.next
        print()

    # Insert a node at the end of the list
    def insert_last(self, value):
        new_node = Node(value)
        if not self.head:
            self.head = new_node
        else:
            temp = self.head
            while temp.next:
                temp = temp.next
            temp.next = new_node

    # Insert a node at the start of the list
    def insert_start(self, value):
        new_node = Node(value)
        new_node.next = self.head
        self.head = new_node

    # Insert a node at a given position
    def insert_position(self, value, k):
        new_node = Node(value)
        if k == 1:
            new_node.next = self.head
            self.head = new_node
        else:
            temp = self.head
            while (k - 2) > 0 and temp.next:
                temp = temp.next
                k -= 1
            new_node.next = temp.next
            temp.next = new_node

    # Delete the first node of the list
    def delete_first(self):
        if not self.head:
            print("\nList is empty")
            return
        temp = self.head
        self.head = self.head.next
        print(f"\nThe deleted node is {temp.data}")
        del temp

    # Delete the last node of the list
    def delete_last(self):
        if not self.head:
            print("\nList is empty")
            return
        if not self.head.next:
            temp = self.head
            self.head = None
            print(f"\nThe deleted node is {temp.data}")
            del temp
        else:
            T1 = None
            T2 = self.head
            while T2.next:
                T1 = T2
                T2 = T2.next
            T1.next = None
            print(f"\nThe deleted node is {T2.data}")
            del T2

    # Delete a node at a given position
    def delete_position(self, k):
        if not self.head:
            print("\nList is empty")
            return
        if not self.head.next:
            temp = self.head
            self.head = None
            print(f"\nThe deleted node is {temp.data}")
            del temp
        else:
            temp = self.head
            prev = None
            while (k - 1) > 0 and temp.next:
                prev = temp
                temp = temp.next
                k -= 1
            if prev:
                prev.next = temp.next
            else:
                self.head = temp.next
            print(f"\nThe deleted node is {temp.data}")
            del temp

# Example usage
sll = SinglyLinkedList()
sll.insert_start(10)
sll.insert_last(20)
sll.insert_position(15, 2)
sll.traversal()  # Expected: 10    15    20
sll.delete_first()
sll.traversal()  # Expected: 15    20
sll.delete_last()
sll.traversal()  # Expected: 15
sll.delete_position(1)
sll.traversal()  # Expected: (empty list)
