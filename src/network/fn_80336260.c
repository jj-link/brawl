#pragma force_active on
typedef struct Node {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    struct Node *next;
} Node;

extern void fn_80335450(int a, int b, int c);
extern Node *lbl_805A0F68;

void fn_80336260(Node *arg0) {
    Node *temp_r31;
    Node *prev;
    Node *node;

    temp_r31 = lbl_805A0F68;
    if (temp_r31 == 0)
        return;
    if (temp_r31 == arg0) {
        prev = temp_r31->next;
        fn_80335450(6, (int)temp_r31, 0);
        lbl_805A0F68 = prev;
        return;
    }
    prev = temp_r31;
    while ((node = prev->next) != 0) {
        if (node != arg0) {
            prev = node;
        } else {
            prev->next = node->next;
            fn_80335450(6, (int)node, 0);
            return;
        }
    }
}
