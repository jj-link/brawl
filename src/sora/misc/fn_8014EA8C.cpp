#include <types.h>
#pragma force_active on

extern "C" {
void OSSleepTicks(s64);
void fn_80037DD0(void*);
void fn_80037E64(void*, s32);
s32 fn_80037F74(void*, s32, s32, s32);
s32 fn_80039B04(void*, s32);
s32 fn_8003CD6C(void*);
void fn_8014CD5C(void);
void fn_8014D54C(void*, s32);
s32 fn_8014D598(void*, void*, s32*);
s32 fn_8014E0DC(void*, s32);
s32 fn_8039B160(void*, u32*);
s32 fn_8039B17C(void*, s32, s32*);
s32 fn_8039B1B0(void*, s32*);
s32 fn_8039B5AC(s32, s32);
s32 fn_8039FD68(void*, u8*, s32);
s32 fn_8039FEB0(void*, s32, s32, s32);
void* memset(void*, s32, u32);
u32 srGetAppInitialCodeLocaleNum__Fv(void);
s32 srGetAppInitialCodeLocale__FUl(u32);
u32 strlen(const char*);
}

class Object_vptr_0 {
public:
    virtual u8 slot0(s32 a, s32 b, void* c);
};

#define WAIT_TICKS() OSSleepTicks((s64)(((*(u32*)0x800000F8) >> 2) / 1000))

inline s32 parseName(const char* name) {
    s32 result = 0;
    if (name == NULL || strlen(name) != 3) return 0;
    if (name[0] == 'd' && name[1] == '0') result = name[2] - '0';
    if (result < 0 || result >= 4) result = 0;
    return result;
}

extern "C" s32 fn_8014EA8C(void* arg0, void* arg1, u16* arg2) {
    s32 r21;
    void* r20;
    u8 sp160[0x384];
    u8 sp60[0x100];
    u8 sp40[0x20];
    u16 sp38[4];
    u32 sp30;
    s32 sp2c;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1c;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spc;
    s32 sp8;
    s32 r29;
    u32 i;
    u32 count;
    s32 t;
    s32 rr;

    if (arg1 == NULL) {
        arg1 = arg0;
        if (arg0 != NULL) {
            arg1 = (u8*)arg0 + 0x18;
        }
    }
    r21 = -1;
    memset(arg2, 0, 8);
    memset(sp38, 0, 8);
    r20 = *(void**)((u8*)arg0 + 0x20);
    if (r20 == NULL) {
        return -1;
    }
    if (fn_8003CD6C(r20) == 0) {
        goto done;
    }
    if (fn_80039B04(r20, 1) == 0) {
        goto done;
    }
    while (*(u8*)((u8*)r20 + 0x5C) == 0) {
        WAIT_TICKS();
    }
    if (*(s32*)((u8*)r20 + 0x60) != 0) {
        goto done;
    }
    sp38[1] = (u16)*(u32*)((u8*)r20 + 0xE8);
    if (fn_80039B04(r20, 2) == 0) {
        goto done;
    }
    while (*(u8*)((u8*)r20 + 0x5C) == 0) {
        WAIT_TICKS();
    }
    if (*(s32*)((u8*)r20 + 0x60) != 0) {
        goto done;
    }
    sp38[2] = (u16)*(u32*)((u8*)r20 + 0xE8);
    if (fn_80039B04(r20, 3) == 0) {
        goto done;
    }
    while (*(u8*)((u8*)r20 + 0x5C) == 0) {
        WAIT_TICKS();
    }
    if (*(s32*)((u8*)r20 + 0x60) != 0) {
        goto done;
    }
    sp38[3] = (u16)*(u32*)((u8*)r20 + 0xE8);
    r21 = 0;
    count = srGetAppInitialCodeLocaleNum__Fv();
    for (i = 0; i < count; i++) {
        sp2c = 0;
        fn_8014D54C(arg0, srGetAppInitialCodeLocale__FUl(i));
        while (fn_8014D598(arg0, sp60, &sp2c) != 0) {
            t = fn_8039FD68(sp60, sp40, 0x20);
            if (t != 0) {
                if ((t <= -0x10 && t >= -0x15) || t == -0x26 || t == -0x29 || t == -0x2B || t == -0x2E) {
                    fn_8039B1B0(sp60, &sp28);
                    fn_8039B5AC(1, sp28);
                }
                if (sp2c == 0) {
                    break;
                }
                continue;
            }
            r29 = parseName((const char*)sp40);
            if (r29 == 0) {
                fn_8039B1B0(sp60, &sp24);
                fn_8039B5AC(1, sp24);
                if (sp2c == 0) {
                    break;
                }
                continue;
            }
            if (r21 == -2) {
                arg2[r29] += 1;
                if (sp2c == 0) {
                    break;
                }
                continue;
            }
            if (sp38[r29] >= 0x3E8) {
                r21 = -3;
                arg2[r29] += 1;
                if (sp2c == 0) {
                    break;
                }
                continue;
            }
            if (fn_8039B160(sp60, &sp30) != 0) {
                fn_8014CD5C();
                if (sp2c == 0) {
                    break;
                }
                continue;
            }
            if (sp30 != 1) {
                fn_8039B1B0(sp60, &sp20);
                fn_8039B5AC(1, sp20);
                if (sp2c == 0) {
                    break;
                }
                continue;
            }
            sp1c = 0;
            t = fn_8039B17C(sp60, 0, &sp1c);
            if (t != 0) {
                if ((t <= -0x10 && t >= -0x15) || t == -0x26 || t == -0x29 || t == -0x2B || t == -0x2E) {
                    fn_8039B1B0(sp60, &sp18);
                    fn_8039B5AC(1, sp18);
                }
                if (sp2c == 0) {
                    break;
                }
                continue;
            }
            t = fn_8039FEB0(sp60, 0, *(s32*)((u8*)arg0 + 0x88), 0x23000);
            if (t != 0) {
                if ((t <= -0x10 && t >= -0x15) || t == -0x26 || t == -0x29 || t == -0x2B || t == -0x2E) {
                    fn_8039B1B0(sp60, &sp14);
                    fn_8039B5AC(1, sp14);
                }
                if (sp2c == 0) {
                    break;
                }
                continue;
            }
            fn_80037DD0(sp160);
            sp160[0x380] = 1;
            if (fn_80037F74(sp160, *(s32*)((u8*)arg0 + 0x88), sp1c, *(s32*)((u8*)arg0 + 0x4)) == 0) {
                fn_8039B1B0(sp60, &sp10);
                fn_8039B5AC(1, sp10);
                if (sp2c == 0) {
                    fn_80037E64(sp160, -1);
                    break;
                }
                fn_80037E64(sp160, -1);
                continue;
            }
            while (sp160[0x370] == 0) {
                WAIT_TICKS();
            }
            if (*(s32*)(sp160 + 0x374) != 0) {
                fn_8039B1B0(sp60, &spc);
                fn_8039B5AC(1, spc);
                if (sp2c == 0) {
                    fn_80037E64(sp160, -1);
                    break;
                }
                fn_80037E64(sp160, -1);
                continue;
            }
            if (((Object_vptr_0*)arg1)->slot0(*(s32*)(sp160 + 0x378), *(s32*)(sp160 + 0x37C), r20) == 0) {
                fn_8039B1B0(sp60, &sp8);
                rr = fn_8039B5AC(1, sp8);
                if (rr != 0 && fn_8014E0DC(arg0, rr) == 0) {
                    fn_80037E64(sp160, -1);
                    goto done;
                }
                sp38[r29] += 1;
            } else {
                arg2[r29] += 1;
                r21 = -2;
                if (sp2c == 0) {
                    fn_80037E64(sp160, -1);
                    break;
                }
                fn_80037E64(sp160, -1);
                continue;
            }
            fn_80037E64(sp160, -1);
        }
    }
done:
    return r21;
}
