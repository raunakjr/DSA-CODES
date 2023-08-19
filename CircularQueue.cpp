class MyCircularQueue {
public:
    vector<int>arr;
    int start=0;
    int end=-1;
    int maxSize;
    int currSize=0;
    MyCircularQueue(int k) 
    {
        maxSize=k;
        arr.resize(k);
    }
    
 
  
    bool enQueue(int newElement) 
    {
    if (currSize == maxSize) return 0;
    end = (end + 1) % maxSize;
    arr[end] = newElement;
    currSize++;
    return 1;
    }
    
    bool deQueue() 
    {
    if (currSize==0)    return 0;
    start = (start + 1) % maxSize;
    currSize--;
    return 1;


    }
    
    int Front() {
      if(currSize==0) return -1;
        return arr[start];
    }
    
    int Rear() {
         if(currSize==0) return -1;
        return arr[end];
    }
    
    bool isEmpty() {
        return currSize==0;
    }
    
    bool isFull() {
        return currSize==maxSize;
    }
};

