class list:
    class Node:
        def __init__(self,data,next=None,prev=None):
            self.data=data
            self.next=next
            self.prev=prev

    def __init__(self):
        self.head=self.Node(None,None,None)
        self.tail=self.Node(None,None,self.head)
        self.head.next=self.tail
        self.sizze=0

    def size(self): return self.size
    def isEmpty(self): return self.size==0

    def insertBefore(self,p,data):
        t=p.prev
        n=self.Node(data,p,t)
        t.next=n
        p.prev=n
        self.size+=1

    def insertAfter(sefl,p,data):
        t=p.next
        n=self.Node(data,t,p)
        t.prev=n
        p.next=n
        self.size+=1

    def delete(self,x):
        f=x.prev
        r=x.next
        f.next=r
        r.prev=f
        self.size-=1
        return x.data

    def printList(self):
        if self.isEmpty():
            print("The list is empty")
        else:
            p=self.head.next
            while p!=self.tail:
                if p.next!=self.tail:
                    print(p.data,"<=>" end='')
                else:
                    print(p.data)
                p=p.next