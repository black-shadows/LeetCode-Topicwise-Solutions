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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1==NULL)
            return l2;
        
        if(l2==NULL)
            return l1;
        
        ListNode *temp1= l1,*prev1=temp1;
        ListNode *temp2=l2,*prev2=temp2;
        
        int sum =0, carry=0;
        while(temp1!=NULL && temp2!=NULL){
            
            sum = temp1->val + temp2->val +carry;
            temp1->val = sum%10;
            carry=sum/10;
            prev1=temp1;
            prev2=temp2;
            temp1=temp1->next;
            temp2=temp2->next;
            
            
        }
        
        if(temp1!=NULL && temp2==NULL){
            
            while(temp1){
                sum = temp1->val+carry;
                temp1->val = sum%10;
                carry = sum/10;
                prev1 = temp1;
                temp1=temp1->next;
            }
        }
        
        else if(temp2!=NULL && temp1==NULL){
            while(temp2){
                
                sum = temp2->val+carry;
                temp2->val = sum%10;
                carry = sum/10;
                prev1->next = temp2;
                prev1=temp2;
                temp2=temp2->next;
            }
        }
        
        if(carry){
            prev1->next = new ListNode(carry);
        }
        
        return l1;
    }
};