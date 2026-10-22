#pragma force_active on
extern void fn_8037EF20(void);
extern void fn_80335450(int a, int b, int c);
extern void fn_80336260(void *p);
extern void *lbl_805A0F68;

typedef struct Node {
    int unk00[4];
    int unk10;
    int unk14;
    struct Node *unk18;
} Node;

void fn_803360BC(int arg0) {
    Node *var_r31;

    fn_8037EF20();
    var_r31 = (Node *)lbl_805A0F68;
    while (var_r31 != 0 && var_r31->unk14 != arg0) {
        var_r31 = var_r31->unk18;
    }
    if (var_r31 != 0) {
        if (var_r31->unk10 != 0) {
            fn_80335450(6, var_r31->unk10, 0);
        }
        fn_80336260(var_r31);
    }
}
