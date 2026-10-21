#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

typedef struct Node {
    struct Node* next;
    u16 id;
} Node;

void* fn_80256CF4(void** arg0, u32 arg1) {
    Node* n = (Node*)*arg0;
    while (n != 0) {
        if (n->id == arg1) {
            return n;
        }
        n = n->next;
    }
    return 0;
}
