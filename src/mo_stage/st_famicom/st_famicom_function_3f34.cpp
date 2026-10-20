#pragma force_active on
struct Node;
struct List {
    unsigned int count;
    Node* head;
};

extern "C" {
void fn_8015C2BC(List* list, Node** out);
void __dl__FPv(void* p);

void fn_68_3F34(void* unused, List* list) {
    Node* node;
    Node* tmp;
    unsigned int i;
    unsigned int n;

    if (list != 0) {
        n = list->count;
        for (i = 0; i != n; i++) {
            node = list->head;
            tmp = node;
            fn_8015C2BC(list, &tmp);
            if (node != 0) {
                __dl__FPv(node);
            }
        }
    }
}
}
