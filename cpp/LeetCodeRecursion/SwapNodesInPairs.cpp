/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* helperSwapPairs(ListNode* head,int count)
    {
        if(!head->next)
            return head;
        
        ListNode* li=helperSwapPairs(head->next,count+1);
        
        if(count%2!=0)
        {
            head->next=li->next;
            li->next=head;
            return li;
        }
        else
        {
            head->next=li;
            return head;
        }
            
    }
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return head;
        
        return helperSwapPairs(head,1);
    }
};