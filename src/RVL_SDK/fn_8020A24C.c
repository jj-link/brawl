#pragma force_active on
extern struct Node *lbl_805A0B8C;
extern struct Node *lbl_805A0B90;
extern struct Node *lbl_805A0B94;

struct Node {
    int field0;
    unsigned int key;
    char pad[0x30];
    struct Node *next;
    struct Node *prev;
};

void fn_8020A24C(struct Node *node) {
    struct Node *cur;
    struct Node *tmp;

    cur = lbl_805A0B90;
    if (cur == 0) {
        lbl_805A0B94 = node;
        lbl_805A0B8C = node;
        lbl_805A0B90 = node;
        node->prev = 0;
        node->next = 0;
        return;
    }
    while (cur != 0) {
        if (node->key < cur->key) {
            node->prev = cur->prev;
            cur->prev = node;
            tmp = node->prev;
            node->next = cur;
            if (tmp == 0) {
                lbl_805A0B90 = node;
            } else {
                tmp->next = node;
            }
            break;
        }
        cur = cur->next;
    }
    if (cur != 0) {
        return;
    }
    lbl_805A0B8C->next = node;
    node->next = 0;
    node->prev = lbl_805A0B8C;
    lbl_805A0B8C = node;
}
