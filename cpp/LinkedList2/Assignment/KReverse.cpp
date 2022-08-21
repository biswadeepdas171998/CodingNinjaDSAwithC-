/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node *reverse(Node *head)
{
    //Write your code here
    if(head==NULL || head->next==NULL)
        return head;
    
    Node* smallAns=reverse(head->next);
    
    Node* ptr=head->next;
    ptr->next=head;
    head->next=NULL;
    return smallAns;
}
Node *kReverse(Node *head, int k)
{
	//Write your code here
    Node *start=NULL,*ptr=head;
    
    int count=0;
    Node *prevStart=NULL;
    while(ptr!=NULL)
    {
        start=ptr;
        for(int i=0;ptr!=NULL &&i<k-1;i++)
        {
            ptr=ptr->next;
        }
        
        if(ptr==NULL)
        {
            Node* p=prevStart->next;
            Node *h1=reverse(p);
            prevStart->next=h1;
            break;
        }
        
        Node *nptr=ptr->next;
        ptr->next=NULL;
        
        Node *h=reverse(start);
        start->next=nptr;
        
        if(prevStart==NULL)
        {
            head=h;
            prevStart=start;
        }
        else
        {
        	prevStart->next=h;
            prevStart=start;
        }
        start=nptr;
        ptr=nptr;
    }
    return head;
}