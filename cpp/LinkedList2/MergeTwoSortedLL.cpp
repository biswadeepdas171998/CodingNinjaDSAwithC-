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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    Node* ans=NULL;
    Node* ptr=NULL;
    
    if(head1==NULL && head2== NULL)
        return ans;
    
    if(head1==NULL)
        return head2;
    
    if(head2==NULL)
        return head1;

    while(head1!=NULL && head2!=NULL)
    {
        if(ans==NULL)
        {
            if(head1->data <= head2->data)
            {
                ans=head1;
                ptr=ans;
                head1=head1->next;
            }
            else
            {
                ans=head2;
                ptr=ans;
                head2=head2->next;
            }
        }
        else
        {
            if(head1->data <= head2->data)
            {
                ptr->next=head1;
                ptr=ptr->next;
                head1=head1->next;
            }
            else
            {
                ptr->next=head2;
                ptr=ptr->next;
                head2=head2->next;
            }
        }
    }
    while(head1!=NULL)
    {
        ptr->next=head1;
        ptr=ptr->next;
        head1=head1->next;
    }
    while(head2!=NULL)
    {
        ptr->next=head2;
        ptr=ptr->next;
        head2=head2->next;
    }
    ptr->next=NULL;
    return ans;
}