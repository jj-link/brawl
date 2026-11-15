#include <types.h>
#include <string.h>
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

extern char lbl_80489334[];
extern char lbl_80489358[];
extern char lbl_8059F070[4];

extern void fn_80335638(s32 level, const char *fmt, ...);
extern void *fn_80335390(s32 type, s32 size);
extern void fn_80335450(s32 type, void *p, s32 flag);
extern void fn_80336138(s32 code);
extern void fn_80336260(Node *node);

s32 fn_80335AB8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 node_arg) {
    Node *node = (Node *)node_arg;
    FnCb cb;
    s32 var_r29;
    s32 buf;

    cb = node->unk4;
    var_r29 = node->unkC;
    fn_80335638(4, lbl_80489334, arg1);
    if (cb != NULL) {
        if (arg1 == 0) {
            cb(arg2, arg3, arg1, node->unk0);
        } else {
            if (arg3 > 0) {
                buf = (s32)fn_80335390(6, arg3 + 1);
                memcpy((void *)buf, (void *)arg2, arg3);
                *(char *)(buf + arg3) = 0;
                fn_80335638(4, lbl_8059F070, arg2);
                fn_80335450(6, (void *)buf, 0);
            }
            fn_80336138(arg1);
            cb(0, 0, arg1, node->unk0);
        }
    } else {
        fn_80335638(4, lbl_80489358);
    }
    if (arg1 != 0 || var_r29 == 1) {
        if (node->unk10 != NULL) {
            fn_80335450(6, node->unk10, 0);
        } else {
            var_r29 = 1;
        }
    }
    fn_80336260(node);
    return var_r29 != 0;
}