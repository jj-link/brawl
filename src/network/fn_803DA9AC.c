#pragma force_active on
typedef struct Node Node;
struct Node { unsigned short flags; char pad[10]; int a,b; char pad14[4]; int c,d; Node *next,*prev; };
typedef struct Obj { char pad[0x1630]; Node *first,*second; } Obj;
void fn_803DA9AC(Obj *obj) {
    Node *n, *head, *n2, *head2;
    while ((n = obj->first)->flags & 1) {
        if (n != 0) {
            n->flags &= 0xfffc;
            n->a = 0; n->b = 0; n->c = -1; n->d = 0;
            head = obj->first;
            if (n == head) obj->first = n->next;
            else if (n != head->prev) {
                n->prev->next = n->next;
                n->next->prev = n->prev;
                head = obj->first;
                n->next = head;
                n->prev = obj->first->prev;
                n->next->prev = n;
                n->prev->next = n;
            }
        }
    }
    while ((n2 = obj->second)->flags & 1) {
        if (n2 != 0) {
            n2->flags &= 0xfffc;
            n2->a = 0; n2->b = 0; n2->c = -1; n2->d = 0;
            head2 = obj->second;
            if (n2 == head2) obj->second = n2->next;
            else if (n2 != head2->prev) {
                n2->prev->next = n2->next;
                n2->next->prev = n2->prev;
                head2 = obj->second;
                n2->next = head2;
                n2->prev = obj->second->prev;
                n2->next->prev = n2;
                n2->prev->next = n2;
            }
        }
    }
}