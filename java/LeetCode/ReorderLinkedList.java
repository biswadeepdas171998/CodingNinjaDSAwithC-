class Solution {
    public int sizeL(ListNode head)
    {
        int count=0;
        while(head!=null)
        {
            count++;
            head=head.next;
        }
        return count;
    }
    public void reorderList(ListNode head) {
        Stack<ListNode> stack=new Stack<>();
        ListNode ptr=head;
        while(ptr!=null)
        {
            stack.push(ptr);
            ptr=ptr.next;
        }
        ptr=head;
        int count=sizeL(head);
        count=count/2;
        ListNode curr=null;
        while(count>0)
        {
            ListNode li=(ListNode)stack.pop();
            curr=ptr;
            ptr=ptr.next;
            
            curr.next=li;
            li.next=ptr;
            
            count--;
        }
        ptr.next=null;
    }
}