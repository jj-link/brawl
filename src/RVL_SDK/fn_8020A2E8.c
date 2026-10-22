#pragma force_active on
struct Node;

extern struct Node *lbl_805A0B8C;
extern struct Node *lbl_805A0B90;
extern struct Node *lbl_805A0B94;

struct Node {
    int a;
    int b;
    int c;
    char pad[0x2C];
    struct Node *next;
    struct Node *prev;
};

void fn_8020A2E8(struct Node *node) {
    node->c = 0;
    node->a = 3;
    if (lbl_805A0B90 == node) {
        if (node->next != 0) {
            lbl_805A0B90 = node->next;
            node->next->prev = 0;
            return;
        }
        lbl_805A0B94 = 0;
        lbl_805A0B8C = 0;
        lbl_805A0B90 = 0;
        return;
    }
    if (lbl_805A0B8C == node) {
        lbl_805A0B8C = node->prev;
        node->prev->next = 0;
        lbl_805A0B94 = lbl_805A0B90;
        return;
    }
    lbl_805A0B94 = node->next;
    node->prev->next = node->next;
    node->next->prev = node->prev;
}
