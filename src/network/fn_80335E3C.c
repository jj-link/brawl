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

extern char lbl_804893A8[];
extern char lbl_80489380[];
extern Node *lbl_805A0F68;

extern void fn_80335638(s32 level, const char *fmt, ...);
extern s32 fn_80335238(void);
extern void *fn_80335390(s32 type, s32 size);
extern void fn_80335450(s32 type, void *p, s32 flag);
extern void fn_80336138(s32 code);
extern void fn_80336260(Node *node);
extern void fn_80335AB8(void);
extern void fn_80335C14(void);
extern s32 fn_8037EAFC(s32 a0, s32 a1, void *a2, s32 a3, s32 a4, s32 a5, s32 a6, void *a7, void *s8, Node *s9);
extern void fn_8037EFB0(s32 a, s32 b);

s32 fn_80335E3C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, FnCb arg4, s32 arg5) {
    Spill spill;
    Node *node;
    Node *tmp;
    void *buf;
    s32 ret;

    buf = NULL;
    fn_80335638(4, lbl_804893A8);
    if (fn_80335238() != 0) {
        return -1;
    }
    spill.f0 = arg5;
    spill.f1 = arg4;
    spill.f2 = arg3;
    spill.f3 = arg2;
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
        arg4(0, 0, -6, arg5);
        return -6;
    }
    if (arg1 > 0) {
        buf = fn_80335390(6, arg1);
        if (buf == NULL) {
            fn_80336138(-6);
            fn_80335638(4, lbl_80489380);
            arg4(0, 0, -6, arg5);
            fn_80336260(node);
            return -6;
        }
        node->unk10 = buf;
    }
    if (arg3 != 0) {
        ret = fn_8037EAFC(arg0, 0, buf, arg1, 0, 0, 0, (void *)fn_80335C14, (void *)fn_80335AB8, node);
    } else {
        ret = fn_8037EAFC(arg0, 0, buf, arg1, 0, 0, 0, NULL, (void *)fn_80335AB8, node);
    }
    if (ret < 0) {
        fn_80336138(ret);
        arg4(0, 0, ret, arg5);
        if (node->unk10 != NULL) {
            fn_80335450(6, node->unk10, 0);
        }
        fn_80336260(node);
    }
    node->unk14 = ret;
    fn_8037EFB0(ret, 1);
    return ret;
}
