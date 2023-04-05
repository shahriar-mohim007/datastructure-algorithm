class Node:
    def __init__(self,val) -> None:
        self.val = val
        self.next = None

class linkedlist:
    def __init__(self) -> None:
        self.head = None
        self.tail = None

    def insertfront(self,val):
        newnode = Node(val)
        if self.head == None:
           self.head = newnode
           self.tail = newnode
        else:
            newnode.next = self.head
            self.tail.next = newnode
            self.head = newnode
            
    def inserttail(self,val):
        newnode = Node(val)
        if self.head == None:
           self.head = newnode
           self.tail = newnode
        else:
            self.tail.next = newnode
            newnode.next = self.head
            self.tail = newnode

    def delete(self,val):
        if self.head == None:
           return

        currentNode = self.head
        while currentNode.val != val:
             previousNode = currentNode
             currentNode = currentNode.next

        if currentNode == self.head:
           temp = self.head
           self.head = self.head.next
           self.tail.next =  self.head
           del temp
           
        elif currentNode == self.tail:
             temp = self.tail
             previousNode.next = self.head
             self.tail = previousNode
             del temp
        else:
             previousNode.next = currentNode.next
             del currentNode

    def printfront(self):
        currentNode = self.head.next
        print(self.head.val,end=" ")
        while currentNode != self.head:
            print(currentNode.val,end=" ")
            currentNode = currentNode.next

if __name__ == '__main__':
    list = linkedlist()
    list.insertfront(1)
    list.insertfront(2)
    list.insertfront(3)
    list.printfront()
    list.inserttail(4)
    list.inserttail(5)
    print("\n")
    list.printfront()
    print("\n")
    list.delete(3)
    list.delete(5)
    list.printfront()

        

        