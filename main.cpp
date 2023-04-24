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
        int num1 = assembleFullNomber(l1);
        int num2 = assembleFullNomber(l2);
        // cout << "num1:" << num1 << endl;
        // cout << "num2:" << num2 << endl;
        ListNode* tempRez = disassembleFullNomber(num1+num2);
        return tempRez;
    }

private:
    int assembleFullNomber(ListNode* ln) {
        int digits = 1; //10 100 1000 10000 ...
        int rez = ln->val*digits;
        ListNode *tempNext = ln->next;
        while (tempNext !=  nullptr){
            digits = digits * 10;
            rez += tempNext->val*digits;
            tempNext = tempNext->next;
        }
        return rez;
    }

    ListNode* disassembleFullNomber(int number) {
        int num = number;
        // cout << "num0:" << num << endl;
        int remainder = num % 10;
        // cout << "Remainder:" << remainder << endl;
        num /= 10;
        // cout << "New num0:" << num << endl;
        ListNode* rezLN = new ListNode(remainder);
        if (number > 9) {
            remainder = num % 10;
            // cout << "Remainder:" << remainder << endl;
            num /= 10;
            // cout << "New num1:" << num << endl;
            ListNode* tempLN = new ListNode(remainder);
            rezLN->next = tempLN;
            while (num > 0){
                remainder = num % 10;
                // cout << "Remainder:" << remainder << endl;
                num /= 10;
                // cout << "New num: " << num << endl;
                // Node* p = new Node(_val);
                ListNode* lnPtr = new ListNode(remainder);
                tempLN->next = lnPtr;
                tempLN = lnPtr;
            }
        }
        return rezLN;
    }
};
