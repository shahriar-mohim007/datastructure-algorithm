class Node:
    def __init__(self,val)->None:
        self.val = val
        self.next = None

class Linkedlist:
    def __init__(self) -> None:
        self.head = None

    def Insert(self,val):
        newnode = Node(val)

        if self.head == None:
           self.head = newnode
           return
        temp = self.head
        while temp.next !=None:
            temp = temp.next
        temp.next = newnode

    def Delete(self,val):
        currentNode = self.head
        while currentNode.val != val:
            previousNode = currentNode
            currentNode  = currentNode.next
        if currentNode == self.head:
            temp = self.head
            self.head = self.head.next
            del temp
        else:
            previousNode.next = currentNode.next
            del currentNode

    
    def Print(self):
        currentNode = self.head
        while currentNode != None:
            print(currentNode.val,end=" ")
            currentNode =  currentNode.next
        
if __name__ == '__main__':
    list = Linkedlist()
    list.Insert(1)
    list.Insert(2)
    list.Insert(3)
    list.Print()
    list.Delete(2)
    list.Print()

