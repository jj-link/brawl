#pragma force_active on
struct Node {
    Node* prev;
    Node* next;
};

struct NodeList {
    int unk0;
    Node* head;
    Node* tail;
    Node* cur;
    int count;
};

extern "C" void __dl__FPv(void*);

extern "C" {
void fn_1_106AC(NodeList* list) {
    Node* node = list->cur;
    if (node->prev != 0) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }

    node = list->cur;
    if (node->next != 0) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }

    node = list->cur;
    Node* next = node->next;
    list->cur = next;
    list->count = list->count - 1;
    if (next == 0) {
        return;
    }
    __dl__FPv(next);
}
}
