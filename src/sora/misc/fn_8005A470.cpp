#include <gf/gf_task.h>
#include <string.h>
#pragma force_active on

struct Obj { char pad[0xA0]; int a0; char pad2[0x4C]; int f0; };
struct Arg { char pad[0x8]; u32 state; int cnt; u8 flag; };

extern "C" {
void fn_800307B4();
int fn_800305B0(int);
Obj* fn_80030548(int);
int fn_80030DEC(Obj*, int);
int fn_80030F2C(Obj*);
int fn_80030F58(Obj*);
void fn_8004EEC8(int, int);
int fn_8014C61C();
int fn_8014C754();
int fn_8014C75C(int*);
}
extern int g_GameGlobal;
extern int lbl_8059CE48;
extern gfTask* lbl_805A00F0;
extern Obj* lbl_805A00F8;

extern "C" void fn_8005A470(Arg* arg) {
    gfTask* t = lbl_805A00F0;
    if (t != 0) {
        if (lbl_805A00F8) {
            fn_800307B4();
            lbl_805A00F8 = 0;
        }
        lbl_805A00F0 = 0;
        t->exit();
        return;
    }
    u32 state = arg->state;
    switch (state) {
    case 0: {
        if (!fn_800305B0(0)) {
            arg->state = 3;
            return;
        }
        lbl_805A00F8 = fn_80030548(lbl_8059CE48);
        if (!lbl_805A00F8) {
            arg->state = 3;
            return;
        }
        int r = fn_80030DEC(lbl_805A00F8, 0);
        if (!r) {
            arg->state = 3;
            return;
        }
        fn_8004EEC8(g_GameGlobal, r);
        if (!fn_80030F2C(lbl_805A00F8)) {
            arg->state = 3;
            return;
        }
        arg->state = 1;
        arg->cnt = 0;
        return;
    }
    case 1:
    case 4:
        arg->cnt++;
        if (lbl_805A00F8->f0 == 0) {
            if ((s32)state == 1) {
                arg->state = 2;
            } else {
                arg->state = 5;
            }
        }
        return;
    case 2:
    case 5:
        if ((s32)state == 2) {
            arg->state = 3;
        } else {
            arg->state = 6;
        }
        return;
    case 3:
        if (fn_8014C61C() != 0) {
            if (lbl_805A00F8 == 0) {
                lbl_805A00F8 = fn_80030548(lbl_8059CE48);
                if (!lbl_805A00F8) {
                    arg->state = 6;
                    return;
                }
            }
            int p = fn_80030DEC(lbl_805A00F8, 2);
            if (!p) {
                arg->state = 6;
                return;
            }
            int size = fn_8014C754();
            int src = 0;
            if (!fn_8014C75C(&src)) {
                arg->state = 6;
                return;
            }
            memcpy((void*)p, (void*)src, size);
            if (!fn_80030F58(lbl_805A00F8)) {
                arg->state = 6;
                return;
            }
            arg->cnt = 0;
            arg->state = 4;
            return;
        }
        /* fall through */
    case 6:
        if (lbl_805A00F8 != 0) {
            fn_800307B4();
            lbl_805A00F8 = 0;
        }
        arg->state = 7;
        return;
    case 7:
        arg->flag = 1;
        return;
    default:
        return;
    }
}
