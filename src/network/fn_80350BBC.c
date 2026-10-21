#pragma force_active on
typedef struct Node {
    char pad[0x18];
    struct Node* next;
} Node;

extern Node* lbl_805A0FC8;
void fn_80335450(int a, void* b, int c);

int fn_80350BBC(void) {
    Node* node = lbl_805A0FC8;
    Node* next;

    while (node != 0) {
        next = node->next;
        fn_80335450(0xB, node, 0);
        lbl_805A0FC8 = next;
        node = next;
    }
    return 0;
}
