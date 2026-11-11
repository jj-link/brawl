#include <mv/mv_THPPlayer.h>
#include <revolution/OS/OSMessage.h>
#include <types.h>
#pragma force_active on
#pragma opt_common_subs off
extern int* lbl_805A01F8;
extern "C" int fn_801E9AB0(void);
extern "C" int fn_8007E958(int);
extern "C" void fn_802022DC(int, int);
extern "C" int fn_8007CF00(void);
#define P ((char*)&g_thpObject)
#define I(n) (*(int*)(P + (n)))
#define B(n) (*(u8*)(P + (n)))
#define Q (*(u64*)(P + 0xC8))
extern "C" void fn_8007CB98(int arg) {
    int r31;
    void (*cb)(int) = (void (*)(int))*(int*)((char*)lbl_805A01F8 + 0x7F4);
    if (cb) cb(arg);
    r31 = -1;
    if (I(0xA0) != 0 && B(0xA4) == 2) {
        if (I(0xA8) != 0 || I(0xAC) != 0) {
            B(0xA5) = 5; B(0xA4) = 5; return;
        }
        ++Q;
        if ((I(0xCC) | I(0xC8)) == 0) {
            int flags = I(0x88);
            int r;
            if (flags & 1) {
                if (fn_801E9AB0() == 0) r = 1;
                else goto fail;
            } else if (flags & 2) {
                if ((u32)fn_801E9AB0() == 1) r = 1;
                else goto fail;
            } else r = 1;
            goto done;
        fail: r = 0;
        done:
            if (r != 0) {
                if (B(0xA7) != 0) {
                    if (I(0xE0) - I(0xE4) <= 1) {
                        r31 = fn_8007E958(0);
                        I(0xE0) = I(0xE0) + 1;
                    } else {
                        int v = *(int*)((char*)lbl_805A01F8 + 0x7F8);
                        if (v != 0) fn_802022DC(v, 1);
                        v = *(int*)((char*)lbl_805A01F8 + 0x7FC);
                        if (v != 0) fn_802022DC(v, 1);
                        B(0xA5) = 2;
                    }
                } else r31 = fn_8007E958(0);
            } else { I(0xCC) = -1; I(0xC8) = -1; }
        } else {
            if (B(0xA7) != 0 && ((I(0xCC) ^ 1) | I(0xC8)) == 0 && B(0xA5) != 2) {
                int v = *(int*)((char*)lbl_805A01F8 + 0x7F8);
                if (v != 0) fn_802022DC(v, 1);
                v = *(int*)((char*)lbl_805A01F8 + 0x7FC);
                if (v != 0) fn_802022DC(v, 1);
                B(0xA5) = 2;
            }
            if (fn_8007CF00() != 0) {
                if (B(0xA7) != 0) {
                    if (I(0xE0) - I(0xE4) <= 1) {
                        r31 = fn_8007E958(0);
                        I(0xE0) = I(0xE0) + 1;
                    }
                } else r31 = fn_8007E958(0);
            }
        }
        if (r31 != 0 && (u32)r31 != 0xffffffffUL) {
            if (I(0xE8) != 0)
                OSSendMessage((OSMessageQueue*)((char*)lbl_805A01F8 + 0x7C0), (void*)I(0xE8), 0);
            I(0xE8) = r31;
        }
        if ((B(0xA6) & 1) == 0) {
            if (B(0xA7) != 0) {
                u32 count = (u32)(I(0xE4) + I(0xC0));
                if (count == (u32)I(0x50) && I(0xEC) == 0) {
                    B(0xA5) = 3; B(0xA4) = 3;
                }
            } else {
                u32 target;
                if (I(0xE8) != 0) target = *(u32*)(I(0xE8) + 0xC) + (u32)I(0xC0);
                else target = (u32)I(0xC0) - 1;
                if (target == (u32)(I(0x50) - 1) && r31 == 0) {
                    B(0xA5) = 3; B(0xA4) = 3;
                }
            }
        }
    }
}