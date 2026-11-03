#include <types.h>
#pragma force_active on

extern void fn_803D6224(s32 a, s32 b, u16 c);
extern s32 fn_803D7248(u16 *a, s32 b, s32 c, s32 d, u32 *e);
extern void *fn_803D911C(u16 *a, s32 b, s32 c);
extern s32 fn_803D9280(u16 *a, void *b);

typedef struct {
    u16 unk0;
    u8 pad2[6];
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Node;

s32 fn_803D9D68(u16 *arg0, s32 *arg1, s32 arg2, s32 arg3) {
    Node *node;
    u32 sp8;
    s32 ret;

    node = (Node *)fn_803D911C(arg0, *arg1, arg3);
    if (node != 0) {
        fn_803D6224(node->unk8, arg2, *arg0);
        node->unk0 |= 2;
        if (node->unkC == 0) {
            node->unkC = node->unk8;
            node->unk10 = node->unk8;
        } else if ((u32)node->unk8 < (u32)node->unkC) {
            node->unkC = node->unk8;
        } else if ((u32)node->unk8 > (u32)node->unk10) {
            node->unk10 = node->unk8;
        }
        ret = fn_803D9280(arg0, node);
        if (ret != 0) {
            return ret;
        }
        goto done;
    }
    ret = fn_803D7248(arg0, arg2, arg3, 1, &sp8);
    if (ret != 0) {
        return ret;
    }
    if (sp8 != 1) {
        return 0x11;
    }
done:
    return 0;
}
