#pragma force_active on
typedef unsigned int u32;
typedef int s32;

typedef struct Node {
    char pad0[0x1c];
    s32 f1c;
    void *f20;
} Node;

typedef struct Ctx {
    char pad0[0x1f4];
    s32 st1f4;
    char pad1[0x438 - 0x1f8];
    s32 f438;
    char pad2[4];
    Node *f440;
} Ctx;

extern void fn_8035D774(u32 ms);
extern void fn_80368C10(void **p);
extern s32 fn_80368D50(void **p);
extern s32 fn_8036AE88(void **p, s32 arg);
extern s32 fn_8036C218(void **p);
extern void fn_8036C3A8(void **p, s32 arg);
extern void fn_8036E9EC(void **p, void *node);
extern void fn_8036EEE4(void **p, void *node);
extern s32 fn_8036EF30(void **p, void **out, s32 arg);
extern s32 fn_8036FB04(void **p);
extern s32 fn_80372A74(void **p);

s32 fn_80369034(void **arg0, s32 arg1) {
    Ctx *self;
    Node *sp8;
    s32 temp_r3_2;
    s32 var_r3;
    s32 var_r29;
    s32 temp_r0;
    s32 temp_r3;
    s32 temp_r28;

    self = (Ctx *)*arg0;
    var_r29 = 0;
    if (self->st1f4 == 1) {
        do {
            temp_r3_2 = fn_8036C218(arg0);
            var_r29 = temp_r3_2;
            var_r3 = 0;
            if (temp_r3_2 == 0 && arg1 != 0 && self->st1f4 == 1) {
                var_r3 = 1;
            }
            temp_r28 = (s32)((u32)(-var_r3 | var_r3) >> 31);
            if (temp_r28 != 0) {
                fn_8035D774(10);
            }
        } while (temp_r28 != 0);
        if (var_r29 != 0 && fn_8036EF30(arg0, (void **)&sp8, 1) != 0) {
            sp8->f1c = 4;
        }
    }
    temp_r0 = self->st1f4;
    if (temp_r0 == 3 || temp_r0 == 2 || temp_r0 == 5) {
        if (var_r29 == 0) {
            var_r29 = fn_80368D50(arg0);
        }
        if (var_r29 == 0) {
            var_r29 = fn_8036FB04(arg0);
        }
    }
    if (var_r29 == 0) {
        var_r29 = fn_80372A74(arg0);
    }
    sp8 = self->f440;
    while (sp8 != 0) {
        if (sp8->f1c != 0) {
            Node *node;
            fn_8036E9EC(arg0, sp8);
            node = sp8;
            sp8 = (Node *)node->f20;
            fn_8036EEE4(arg0, node);
        } else {
            sp8 = (Node *)sp8->f20;
        }
    }
    temp_r3 = fn_8036AE88(arg0, arg1);
    if (temp_r3 != 0) {
        return temp_r3;
    }
    if (self->f438 != 0) {
        fn_8036C3A8(arg0, 0);
        fn_80368C10(arg0);
    }
    return var_r29;
}
