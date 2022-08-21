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

Node *merge(Node *head1, Node *head2)
{
    
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
Node *mergeSort(Node *head)
{
	//Write your code here
    if(head==NULL || head->next==NULL)
        return head;
    
    Node* mid=midPoint(head);
    
    Node* next=mid->next;
    
    mid->next=NULL;
    
    Node* left=mergeSort(head);
    Node* right=mergeSort(next);
    return merge(left,right);
}