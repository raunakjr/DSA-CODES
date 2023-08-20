class Node
{
    public:
    int val;
    Node *next;
    Node *prev;
    
    Node(int x)
    {
        val=x;
        prev=next=NULL;
    }
};

class MyCircularDeque {
public:
    Node * head,*tail;
    int cnt;
    int size;
    MyCircularDeque(int k) {
        cnt=0;
        size=k;
        head=NULL;
        tail=NULL;


    }
    
    bool insertFront(int value) {
        if(cnt==size) return false;
        Node * t=new Node(value);
        if(head==NULL)
        {
            head=t;
            tail=t;
        }
        else
        {
        head->prev=t;
        t->next=head;
        head=t;
        }
        cnt++;
        return 1;

    }
    
    bool insertLast(int value) {
       if(cnt==size) return false;
        Node * t=new Node(value);
        if(head==NULL)
        {
            head=t;
            tail=t;
        }
        else
        {
        tail->next=t;
        t->prev=tail;
        tail=t;
        }
        cnt++;
        return 1;

    }
    
    bool deleteFront() {
        if(cnt==0) return 0;
        if(cnt==1)
        {
            head=tail=NULL;

        }
        else
        head=head->next;
        cnt--;
        return 1;
    }
    
    bool deleteLast() {
        if(cnt==0) return 0;
        if(cnt==1)
        {
            head=tail=NULL;

        }
        else
        tail=tail->prev;
        cnt--;
        return 1;
    }
    
    int getFront() {
        if(cnt==0) return -1;
        return head->val;
    }
    
    int getRear() {
        if(cnt==0) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return cnt==0;
    }
    
    bool isFull() {
        return cnt==size;
    }
};

