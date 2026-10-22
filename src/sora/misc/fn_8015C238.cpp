#pragma force_active on
extern "C" {
void __dl__FPv(void* p);

typedef int s32;

struct Node {
    Node* next;
    Node* prev;
};

struct List {
    s32 count;
    Node head;
};

void* fn_8015C238(List* arg0, s32 arg1) {
    if (arg0 != 0) {
        Node* sentinel = &arg0->head;
        Node* cur = arg0->head.next;
        while (cur != sentinel) {
            Node* nxt = cur->next;
            Node* prv = cur->prev;
            nxt->prev = prv;
            prv->next = nxt;
            arg0->count = arg0->count - 1;
            cur->next = 0;
            cur->prev = 0;
            cur = nxt;
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}
