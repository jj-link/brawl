#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_8014E070(void);
s32 fn_8014DD34(void*, s32);
s32 fn_8014F320(void*, s32, void*, s32);
s32 fn_8014E0DC(void*, s32);
s32 fn_8039AA1C(void*, s32);
s32 fn_8039AC0C(void*, s32, s32, s32);
s32 fn_8039AC70(void*, void*, s32);
s32 fn_8039ACE4(void*, void*, s32, s32, s32);
s32 fn_8039AE1C(void*, s32, s32, s32);
s32 fn_8039B030(void*, u16);
s32 fn_8039B070(void*, s32);
void* fn_80037DD0(void*);
s32 fn_80037F04(void*, u32, u32, u32);
void* fn_80037E64(void*, s32);
s32 fn_8014D2F0(void*, u32, s32*);
int sprintf(char*, const char*, ...);
u32 strlen(const char*);
void OSSleepTicks(s64);
extern char lbl_8059E7E0[6];
}

extern "C" s32 fn_8014E720(void* arg) {
    char sp430[0x390];
    char sp230[0x200];
    char sp130[0x100];
    char sp30[0x100];
    char sp10[0x20];
    s32 sp8[2];
    s32 r31;
    s32 r;
    s32 t0;
    s32 t1;
    u16 i;

    if (*(s32*)((u8*)arg + 0x7c) == 0) {
        return -1;
    }
    fn_8014E070();
    if (fn_8014DD34(arg, 1) == 0) {
        return -1;
    }
    sprintf(sp10, lbl_8059E7E0, *(s32*)((u8*)arg + 0x7c));
    r31 = fn_8014F320(arg, *(s32*)((u8*)arg + 0x7c), sp230, 0x100);
    r = fn_8039AA1C(sp130, 1);
    if (r != 0) {
        fn_8014E0DC(arg, r);
        return -1;
    }
    for (i = 0; i < *(u16*)((u8*)arg + 0x70); i++) {
        u8* e = (u8*)arg + (u32)i * 8;
        r = fn_8039AC0C(sp130, (s32)e, *(s32*)(e + 0x30), *(s32*)(e + 0x34));
        if (r != 0) {
            fn_8014E0DC(arg, r);
            return -1;
        }
    }
    r = fn_8039AC70(sp130, sp10, strlen(sp10));
    if (r != 0) {
        fn_8014E0DC(arg, r);
        return -1;
    }
    fn_80037DD0(sp430);
    ((u8*)sp430)[0x380] = 1;
    if (*(s32*)((u8*)arg + 0x78) != 0 && *(s32*)((u8*)arg + 0x74) != 0) {
        if (fn_80037F04(sp430, *(u32*)((u8*)arg + 0x74),
                        *(u32*)((u8*)arg + 0x78), *(u32*)((u8*)arg + 0x4)) == 0) {
            fn_80037E64(sp430, -1);
            return -1;
        }
        while (*(u8*)(sp430 + 0x370) == 0) {
            OSSleepTicks((s64)((*(u32*)0x800000F8 >> 2) / 1000));
        }
        if (*(s32*)(sp430 + 0x374) != 0) {
            fn_80037E64(sp430, -1);
            return -1;
        }
        t0 = *(s32*)(sp430 + 0x378);
        t1 = *(s32*)(sp430 + 0x37C);
        r = fn_8039AE1C(sp130, t0, t1, 0x30000);
        if (r != 0) {
            fn_8014E0DC(arg, r);
            fn_80037E64(sp430, -1);
            return -1;
        }
    }
    fn_80037E64(sp430, -1);
    r = fn_8039AA1C(sp30, 2);
    if (r != 0) {
        fn_8014E0DC(arg, r);
        return -1;
    }
    for (i = 0; i < *(u16*)((u8*)arg + 0x70); i++) {
        u8* e = (u8*)arg + (u32)i * 8;
        r = fn_8039AC0C(sp30, (s32)e, *(s32*)(e + 0x30), *(s32*)(e + 0x34));
        if (r != 0) {
            fn_8014E0DC(arg, r);
            return -1;
        }
    }
    r = fn_8039ACE4(sp30, sp230, r31 * 2, 0x10010, 2);
    if (r != 0) {
        fn_8014E0DC(arg, r);
        return -1;
    }
    r = fn_8039B030(sp30, (u16)(*(s32*)((u8*)arg + 0x7c) + 1));
    if (r != 0) {
        fn_8014E0DC(arg, r);
        return -1;
    }
    r = fn_8039B070(sp30, 0x2019);
    if (r != 0) {
        fn_8014E0DC(arg, r);
        return -1;
    }
    sp8[0] = (s32)sp130;
    sp8[1] = (s32)sp30;
    r = fn_8014D2F0(arg, 2, sp8);
    return -(r == 0);
}
