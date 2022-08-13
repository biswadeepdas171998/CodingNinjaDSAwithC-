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
string reverse(Node* head)
{
    if(head==NULL)
        return "";
    
    return reverse(head->next)+to_string(head->data);
}
bool isPalindrome(Node *head)
{
    //Write your code here
   string rev=reverse(head);
	string str="";
    
    while(head!=NULL)
    {
        str=str+to_string(head->data);
        head=head->next;
    }
    if(str.compare(rev)==0)
        return true;
    else 
        return false;
}