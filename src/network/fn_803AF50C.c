#include <types.h>
#pragma force_active on

typedef struct {
    u16 unk0;
    u8 pad2[6];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
} Node;

extern Node *fn_803AE7B4(u16 *a, s32 b, s32 c);
extern void fn_803A9644(s32 a, s32 b, u16 c);
extern s32 fn_803AE918(u16 *a, Node *b);
extern s32 fn_803C7F98(u16 *a, s32 b);
extern s32 fn_803AAA04(u16 *a, s32 b, s32 c, s32 d, u32 *e);

s32 fn_803AF50C(u16 *arg0, s32 *arg1, s32 arg2, s32 arg3) {
    Node *node;
    u32 sp8;
    s32 ret;
    s32 var = 0;

    node = fn_803AE7B4(arg0, *arg1, arg3);
    if (node != 0) {
        fn_803A9644(node->unk8, arg2, *arg0);
        if (node->unkC == 0) {
            node->unk0 |= 2;
            node->unkC = node->unk8;
            node->unk10 = node->unk8;
        } else if ((u32)node->unk8 < (u32)node->unkC) {
            node->unkC = node->unk8;
        } else if ((u32)node->unk8 > (u32)node->unk10) {
            node->unk10 = node->unk8;
        }
        if (node != 0 && (node->unk0 & 2) && (u32)(node->unk18 + 0x10000) != 0xFFFF) {
            var = 1;
        }
        ret = fn_803AE918(arg0, node);
        if (ret != 0) {
            return ret;
        }
        if (var != 0 && fn_803C7F98(arg0, 1) != 0) {
            return 0x11;
        }
        goto done;
    }
    ret = fn_803AAA04(arg0, arg2, arg3, 1, &sp8);
    if (ret != 0) {
        return ret;
    }
    if (sp8 != 1) {
        return 0x11;
    }
    if (fn_803C7F98(arg0, 1) != 0) {
        return 0x11;
    }
done:
    return 0;
}
