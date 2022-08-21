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

Node *midPoint(Node *head)
{
    // Write your code here
    Node* slow=NULL;
    Node* fast=head;
    
    while(fast!=NULL)
    {
        if(slow==NULL)
        {
            slow=fast;
            fast=fast->next;
            if(fast==NULL)
                break;
            fast=fast->next;
        }
        else
        {
            slow=slow->next;
            fast=fast->next;
            if(fast==NULL)
                break;
            fast=fast->next;
        }
    }
    return slow;
}