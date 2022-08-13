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

Node *removeDuplicates(Node *head)
{
    //Write your code here
    Node* ptr=head;
    Node* prev=NULL;
    
    while(ptr!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
        
        while(ptr!=NULL && prev->data==ptr->data)
        {
            Node *p=ptr;
            ptr=ptr->next;
            delete p;
        }
        prev->next=ptr;
    }
    return head;
}