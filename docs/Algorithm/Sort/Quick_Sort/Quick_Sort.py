table=[4,1,7,6,3,8,2,5]

def Quick_Sort(low,high):
    global table

    if high-low<1:
        return

    tlow=low
    thigh=high
    pivot=high
    high-=1
    while high>=low:
        while table[low]<table[pivot] and low<=thigh:
            low+=1
        while table[high]>table[pivot] and high>=tlow:
            high-=1
        if high>low:
            temp=table[high]
            table[high]=table[low]
            table[low]=temp
            low+=1
            high-=1
    temp=table[low]
    table[low]=table[pivot]
    table[pivot]=temp
    Quick_Sort(tlow,low-1)
    Quick_Sort(low+1,thigh)

if __name__ == "__main__":
    Quick_Sort(0,len(table)-1)
    print(table)