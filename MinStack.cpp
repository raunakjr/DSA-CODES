class Node
{
public:
  int val,min;
  Node *next;
  Node()
  {
      val=min=0;
      next=NULL;
  }    
   Node(int x, int y)
  {
      val=x;
      min=y;
      next=NULL;
  }  
    
    
};
Node  *head=NULL;
MinStack::MinStack() {
    head=NULL;
}


void MinStack::push(int x) {
    if(head==NULL)
    {
        Node *t=new Node(x,x);
        head=t;
    }
    else
    {
        Node *t=new Node(x,min(x,head->min));
        t->next=head;
        head=t;
    }
}

void MinStack::pop() {
     if(!head) return ;
    head=head->next;
}

int MinStack::top() {
    if(!head) return -1;
    return head->val;
}

int MinStack::getMin() {
     if(!head) return -1;
    return head->min;
}

