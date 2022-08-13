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
int length(Node* head)
{
    if(head==NULL)
        return 0;
    
    return 1+length(head->next);
}
Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here 
    int len=length(head);
    if(len==0 || n==0)
        return head;
    
    Node* ptr=head;
    int count=0;
    
    while(count<(len-n-1))
    {
        count++;
        ptr=ptr->next;
    }
    
    Node* prev=ptr->next;
    while(prev!=NULL && prev->next!=NULL)
        prev=prev->next;
    
    prev->next=head;
    head=ptr->next;
    ptr->next=NULL;
    return head;
    
    
    
}