#include <types.h>
#include <mt/mt_prng.h>
#include <string.h>
#pragma force_active on

extern "C" {
extern char lbl_80457158[];
extern mtRand lbl_805A0420;
extern f32 lbl_805A2310;
void netReport__FPCce(const char*, ...);

s32 fn_800C95C4(s32 unused, s32 n, s32* arr) {
    u8 sp[4];
    s32 i;
    s32 j;
    s32 cnt;
    s32 idx;
    char* base = lbl_80457158;

    if (n <= 2) {
        s32 r = (s32)((f32)n * lbl_805A0420.randf());
        netReport__FPCce(base + 0x58C, r);
        return r;
    }
    memset(sp, 0, 4);
    for (i = 0; i < n; i++) {
        sp[i] = 0;
        for (j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                sp[i]++;
            }
        }
    }
    if (n == 3) {
        netReport__FPCce(base + 0x5A8, arr[0], arr[1], arr[2], sp[0], sp[1], sp[2]);
    } else {
        netReport__FPCce(base + 0x5D8, arr[0], arr[1], arr[2], arr[3], sp[0], sp[1], sp[2], sp[3]);
    }
    if (sp[0] == 1 && sp[1] == 1) {
        if (n == 3) {
            netReport__FPCce(base + 0x60C);
            return (s32)((f32)n * lbl_805A0420.randf());
        }
        if (sp[2] == 1) {
            netReport__FPCce(base + 0x638);
            return (s32)((f32)n * lbl_805A0420.randf());
        }
    }
    if (sp[0] == n) {
        netReport__FPCce(base + 0x668);
        return (s32)((f32)n * lbl_805A0420.randf());
    }
    if (sp[0] == 2 && sp[1] == 2 && sp[2] == 2 && sp[3] == 2) {
        netReport__FPCce(base + 0x6A0);
        return (s32)((f32)n * lbl_805A0420.randf());
    }
    s32 nm1 = n - 1;
    if (sp[0] == nm1 || sp[1] == nm1 || sp[2] == nm1 || sp[3] == nm1) {
        netReport__FPCce(base + 0x6C8);
        cnt = (s32)((f32)nm1 * lbl_805A0420.randf());
        for (i = 0; i < n; i++) {
            if (sp[i] == nm1) {
                cnt--;
                if (cnt < 0) {
                    break;
                }
            }
        }
        if (i >= n) {
            netReport__FPCce(base + 0x6FC);
            i = 0;
        }
        return i;
    }
    if (n == 3) {
        netReport__FPCce(base + 0x71C);
        return (s32)((f32)n * lbl_805A0420.randf());
    }
    if (sp[0] == 2 || sp[1] == 2 || sp[2] == 2 || sp[3] == 2) {
        netReport__FPCce(base + 0x744);
        cnt = (s32)(lbl_805A2310 * lbl_805A0420.randf());
        for (i = 0; i < n; i++) {
            if (sp[i] == 2) {
                cnt--;
                if (cnt < 0) {
                    break;
                }
            }
        }
        if (i >= n) {
            netReport__FPCce(base + 0x76C);
            i = 0;
        }
        return i;
    }
    netReport__FPCce(base + 0x78C);
    return (s32)((f32)n * lbl_805A0420.randf());
}
}
