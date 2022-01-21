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
    
    //vector of lists mei her linked list ke head pade hai to unmei se 
    //not null and minimum value nikal li O(k time mei )
    
    int minNode(vector<ListNode*> &lists){
        int min = INT_MAX;
        int idx = -1;
        
        for(int i = 0;i<lists.size();i++){
            
            if(lists[i] != NULL && lists[i]->val < min){
                idx = i;
                min = lists[i]->val;
            }
        }
        
        return idx;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0){
            return NULL;
        }
        
        ListNode *dummy = new ListNode(-1);
        
        //initailly head and tail dono dummy ko point ker rahe hongei.
        ListNode *head = dummy , *tail = dummy;
        
        //iski TC :
        //ek node ko adjust kerne mei O(k) ka kaam kerna padra hai
        //total nodes N = n*k hai to
        //TC = O(n * k^2) hai.
        
        while(true){
            
            int minIdx = minNode(lists);
            
            //ager beech mei koi bhi idx -1 mil jata hai to break ker do 
            if(minIdx == -1)break;
            
            tail->next = lists[minIdx];
            lists[minIdx] = lists[minIdx]->next;
            tail = tail->next;
        }
        
        return dummy->next;
    }
};
