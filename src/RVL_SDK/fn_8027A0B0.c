#pragma force_active on
typedef struct Node {
    unsigned char pad0[0xC];
    struct Node *next;
} Node;

Node *fn_8027A0B0(Node *node) {
    return node->next;
}