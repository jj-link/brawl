#include <types.h>
#pragma force_active on

typedef void (*FnCb)(s32, s32, s32, s32);

typedef struct Node {
    s32 unk0;
    FnCb unk4;
    s32 unk8;
    s32 unkC;
    void *unk10;
    s32 unk14;
    struct Node *unk18;
} Node;

typedef struct Spill {
    s32 f0;
    FnCb f1;
    s32 f2;
    s32 f3;
} Spill;

extern char lbl_80489394[];
extern char lbl_80489380[];
extern Node *lbl_805A0F68;

extern void fn_80335638(s32 level, const char *fmt, ...);
extern s32 fn_80335238(void);
extern void *fn_80335390(s32 type, s32 size);
extern void fn_80336138(s32 code);
extern void fn_80336260(Node *node);
extern void fn_80335AB8(void);
extern s32 fn_8037ED14(s32 a, s32 b, s32 c, void *d, void *e);
extern void fn_8037EFB0(s32 a, s32 b);

s32 fn_80335CAC(s32 arg0, s32 *arg1, FnCb arg2, s32 arg3) {
    Spill spill;
    Node *node;
    Node *tmp;
    s32 ret;

    fn_80335638(4, lbl_80489394);
    if (fn_80335238() != 0) {
        return -1;
    }
    spill.f0 = arg3;
    spill.f1 = arg2;
    spill.f2 = 0;
    spill.f3 = 1;
    tmp = (Node *)fn_80335390(6, 0x1C);
    if (tmp == NULL) {
        node = NULL;
    } else {
        *(Spill *)tmp = spill;
        tmp->unk18 = NULL;
        tmp->unk10 = NULL;
        if (lbl_805A0F68 == NULL) {
            lbl_805A0F68 = tmp;
            node = tmp;
        } else {
            tmp->unk18 = lbl_805A0F68;
            node = tmp;
            lbl_805A0F68 = tmp;
        }
    }
    if (node == NULL) {
        fn_80336138(-6);
        fn_80335638(4, lbl_80489380);
        arg2(0, 0, -6, arg3);
        return -6;
    }
    ret = fn_8037ED14(arg0, *arg1, 0, (void *)fn_80335AB8, node);
    if (ret < 0) {
        fn_80336138(ret);
        arg2(0, 0, ret, arg3);
        fn_80336260(node);
    }
    node->unk14 = ret;
    fn_8037EFB0(ret, 1);
    return ret;
}