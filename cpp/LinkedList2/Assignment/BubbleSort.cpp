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

int len(Node *head){
    Node *temp=head;
    int count=1;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
Node* bubbleSort(Node* head)
{
    if(head==NULL || head->next==NULL)
        return head;
    
    for(int i=0;i<len(head);i++){
        Node *curr=head;
        Node *prev=NULL;
          // node *n=head->next;
        
        while(curr->next!=NULL) 
        {
            if(curr->data > curr->next->data)  
            {
				if(prev)  
                {
                    // swapping using those 4 steps
                    Node* t=curr->next->next;
                    curr->next->next= curr;
                    prev->next=curr->next;
                    curr->next=t;
                    prev=prev->next;
                }
                else  
                {
                    head= curr->next;
                    curr->next=head->next;
                    head->next=curr;
                    prev=head;
                }
                
            }
            else    
            {
                prev=curr;
                curr=curr->next;
            }
        }
    }

  
    return head;
}