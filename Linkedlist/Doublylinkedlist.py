class Node:
    def __init__(self,val) -> None:
        self.val = val
        self.prev = None
        self.next = None

class linkedlist:
    def __init__(self) -> None:
       self.head = None
       self.tail = None
    def Insertfront(self,val):
        newnode = Node(val)
        if self.head == None:
           self.head = newnode
           self.tail = newnode
        else:
           newnode.next = self.head
           self.head.prev = newnode
           self.head = newnode



    def Insertmiddle(self,val,position):
        newnode = Node(val)
        if self.head == None:
           self.head = newnode
           self.tail = newnode
        else:
            if position == 1:
               newnode.next = self.head
               self.head.prev = newnode
               self.head = newnode
               return

            count = 0
            currentNode = self.head
            previousNode = None

            while count!=position-1:
                  if currentNode.next == None:
                     self.Inserttail(val)
                     return
                  previousNode = currentNode
                  currentNode = currentNode.next
                  count+=1
            if previousNode!=None:
                previousNode.next = newnode
            newnode.next = currentNode
            newnode.prev = previousNode
            currentNode.prev = newnode

                 

    def Inserttail(self,val):
        newnode =  Node(val)
        if self.head == None:
           self.head = newnode
           self.tail = newnode
        else:
           self.tail.next = newnode
           newnode.prev = self.tail
           self.tail = newnode

    def delete(self,val):
        currentNode = self.head
        while currentNode.val!=val:
            previousNode = currentNode
            currentNode = currentNode.next
        if currentNode == self.head:
            temp = self.head
            self.head = self.head.next
            self.head.prev = None
            del temp
        elif currentNode == self.tail:
            temp = self.tail
            self.tail = self.tail.prev
            self.tail.next = None
        else:
            previousNode.next = currentNode.next
            currentNode.next.prev = previousNode
            del currentNode



        
           

    def Printback(self):
        currentNode = self.tail
        while currentNode != None:
            print(currentNode.val,end=" ")
            currentNode =  currentNode.prev

    def Printfront(self):
        currentNode = self.head
        while currentNode != None:
            print(currentNode.val,end=" ")
            currentNode =  currentNode.next

if __name__ == '__main__':
    list = linkedlist()
    list.Insertfront(1)
    list.Insertfront(2)
    list.Insertfront(3)
    list.Insertmiddle(5,1)
    list.Insertmiddle(4,2)
    list.Inserttail(6)
    list.Insertmiddle(7,7)
    list.Printfront()
    print("\n")
    list.delete(5)
    list.Printfront()
    print("\n")
    list.delete(7)
    list.Printfront()
    print("\n")
    list.delete(3)
    list.Printfront()
    print("\n")
    
    