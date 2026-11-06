#pragma force_active on

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;

s32 OSEnableScheduler(void);
s64 OSGetTime(void);
void fn_801D80B4(void* ctx);
void fn_801E0760(void);
void fn_801E0CA8(void);
s32 __cntlzw(u32 value);

extern u32 lbl_80468950[];
extern void (**lbl_805A06D0)(s32, void*);
extern s16 lbl_805A06C4;
extern s32 lbl_805A06C8;
extern u32 lbl_805A06CC;
extern s32 lbl_805A06C0;

void fn_801DD3A0(s32 unused, void* arg1) {
    s32 temp_r31;
    s32 temp_r0;
    s32 var_r0;
    s32 temp_r3;
    void (*fp)(s32, void*);
    s16 idx;
    u32* p;
    s32 t;
    s64 time;
    u16 temp_r4;
    s32 temp_r4_3;
    s32 temp_r4_4;
    s32 temp_r4_5;

    temp_r31 = *(s32*)0xCC003000;
    temp_r0 = *(s32*)0xCC003004;
    temp_r31 &= 0xFFFEFFFF;
    if (temp_r31 == 0 || !(temp_r31 & temp_r0)) {
        fn_801D80B4(arg1);
    }
    var_r0 = 0;
    if (temp_r31 & 0x80) {
        temp_r4 = *(u16*)0xCC00401E;
        if (temp_r4 & 1) {
            var_r0 |= 0x80000000;
        }
        if (temp_r4 & 2) {
            var_r0 |= 0x40000000;
        }
        if (temp_r4 & 4) {
            var_r0 |= 0x20000000;
        }
        if (temp_r4 & 8) {
            var_r0 |= 0x10000000;
        }
        if (temp_r4 & 0x10) {
            var_r0 |= 0x08000000;
        }
    }
    if (temp_r31 & 0x40) {
        temp_r4 = *(u16*)0xCC00500A;
        if (temp_r4 & 8) {
            var_r0 |= 0x04000000;
        }
        if (temp_r4 & 0x20) {
            var_r0 |= 0x02000000;
        }
        if (temp_r4 & 0x80) {
            var_r0 |= 0x01000000;
        }
    }
    if ((temp_r31 & 0x20) && (*(s32*)0xCD006C00 & 8)) {
        var_r0 |= 0x00800000;
    }
    if (temp_r31 & 0x10) {
        temp_r4_3 = *(s32*)0xCD006800;
        if (temp_r4_3 & 2) {
            var_r0 |= 0x00400000;
        }
        if (temp_r4_3 & 8) {
            var_r0 |= 0x00200000;
        }
        if (temp_r4_3 & 0x800) {
            var_r0 |= 0x00100000;
        }
        temp_r4_4 = *(s32*)0xCD006814;
        if (temp_r4_4 & 2) {
            var_r0 |= 0x00080000;
        }
        if (temp_r4_4 & 8) {
            var_r0 |= 0x00040000;
        }
        if (temp_r4_4 & 0x800) {
            var_r0 |= 0x00020000;
        }
        temp_r4_5 = *(s32*)0xCD006828;
        if (temp_r4_5 & 2) {
            var_r0 |= 0x00010000;
        }
        if (temp_r4_5 & 8) {
            var_r0 |= 0x00008000;
        }
    }
    if (temp_r31 & 0x2000) {
        var_r0 |= 0x20;
    }
    if (temp_r31 & 0x1000) {
        var_r0 |= 0x40;
    }
    if (temp_r31 & 0x400) {
        var_r0 |= 0x1000;
    }
    if (temp_r31 & 0x200) {
        var_r0 |= 0x2000;
    }
    if (temp_r31 & 0x100) {
        var_r0 |= 0x80;
    }
    if (temp_r31 & 0x8) {
        var_r0 |= 0x800;
    }
    if (temp_r31 & 0x4) {
        var_r0 |= 0x400;
    }
    if (temp_r31 & 0x2) {
        var_r0 |= 0x200;
    }
    if (temp_r31 & 0x800) {
        var_r0 |= 0x4000;
    }
    if (temp_r31 & 0x1) {
        var_r0 |= 0x100;
    }
    if (temp_r31 & 0x4000) {
        var_r0 |= 0x10;
    }
    temp_r3 = var_r0 & ~(*(s32*)0x800000C4 | *(s32*)0x800000C8);
    if (temp_r3 != 0) {
        p = lbl_80468950;
        for (;;) {
            t = temp_r3 & *p;
            if (t != 0) {
                idx = __cntlzw(t);
                break;
            }
            p++;
        }
        fp = lbl_805A06D0[idx];
        if (fp != 0) {
            if (idx > 4) {
                lbl_805A06C4 = idx;
                time = OSGetTime();
                lbl_805A06CC = (u32)time;
                lbl_805A06C8 = (s32)(time >> 32);
                lbl_805A06C0 = *(s32*)((u8*)arg1 + 0x198);
            }
            fn_801E0760();
            fp(idx, arg1);
            OSEnableScheduler();
            fn_801E0CA8();
            fn_801D80B4(arg1);
        }
    }
    fn_801D80B4(arg1);
}
