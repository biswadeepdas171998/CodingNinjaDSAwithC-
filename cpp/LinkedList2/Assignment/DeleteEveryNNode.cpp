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
Node* retain(Node* head,int M)
{
    if(head==NULL)
        return head;
    M--;
    while(head!=NULL && M>=1)
    {
        M--;
        head=head->next;
    }
    return head;
}
Node* del(Node *head,int N)
{
 	   if(head==NULL)
           return NULL;
    
    while(head!=NULL && N>0)
    {
        N--;
        Node *ptr=head;
        head=head->next;
        delete ptr;
        
    }
    return head;
    
}
Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
    Node *ptr=head,*retained=NULL,*delt=NULL;
    
    if(M==0 && N==0 || (M==0 && N!=0))
        return NULL;
    
    if(M!=0 && N==0)
        return head;
    
    
    while(ptr!=NULL)
    {
        retained=NULL;delt=NULL;
        //retain 

        retained=retain(ptr,M);
        if(retained==NULL)
            break;

        delt=del(retained->next,N);
        retained->next=delt;
        ptr=delt;
    }
    return head;
}