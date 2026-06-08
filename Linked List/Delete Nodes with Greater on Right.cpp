/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution
{
public:
    Node *reverseList(Node *head)
    {
        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL)
        {
            Node *next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }

    Node *compute(Node *head)
    {
        // code here
        Node *newHead = reverseList(head);
        Node *temp = newHead;
        int mx = temp->data;
        while (temp != NULL)
        {
            Node *next = temp->next;
            if (next != NULL && next->data < mx)
            {
                temp->next = next->next;
                next->next = NULL;
                delete next;
            }
            else
            {
                temp = temp->next;
                if (temp != NULL)
                    mx = max(mx, temp->data);
            }
        }

        head = reverseList(newHead);
        return head;
    }
};