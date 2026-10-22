#pragma force_active on
extern void fn_80335638(int, const char *, ...);
extern void fn_8037EAA0(void);
extern void fn_80335450(int, int, int);
extern char lbl_80489320[];
extern int lbl_805A0F6C;
extern void *lbl_805A0F68;

typedef struct Node {
    int unk00[4];
    int unk10;
    int unk14;
    struct Node *unk18;
} Node;

int fn_803359CC(void) {
    Node *node;
    Node *next;

    fn_80335638(4, lbl_80489320);
    if (lbl_805A0F6C <= 0) {
        return 1;
    }
    fn_8037EAA0();
    lbl_805A0F6C = lbl_805A0F6C - 1;
    if (lbl_805A0F6C == 0) {
        next = (Node *)lbl_805A0F68;
        while (next != 0) {
            node = next;
            next = node->unk18;
            if (node->unk10 != 0) {
                fn_80335450(6, node->unk10, 0);
            }
            fn_80335450(6, (int)node, 0);
        }
        lbl_805A0F68 = 0;
    }
    return 1;
}
