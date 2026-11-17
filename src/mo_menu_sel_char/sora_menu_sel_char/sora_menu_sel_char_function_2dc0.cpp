#include <types.h>
#include <gm/gm_global.h>
#include <gf/gf_heap_manager.h>
#include <mt/mt_prng.h>
#pragma force_active on

extern "C" {
s32 fn_801AB6CC(void*, s32, s32);
s32 fn_10_C380(void*);
s32 fn_10_10CAC(void*);
void fn_10_13CAC(s32);
s32 fn_800B6AF0(s32, char*);
void fn_801B4CB0(s32, s32, s32);
s32 getNumCharColor__6muMenuFiii(s32);
int sprintf(char*, const char*, ...);
extern mtRand lbl_805A0420;
extern char lbl_10_data_18[];
extern f32 lbl_10_rodata_38;
}

struct Params {
    s32 w10, w14, w18, w1c, w20, w24, w28, w2c, w30, w34, w38, w3c, w40, w44, w48, w4c, w50;
    u8 b54;
    u8 pad55[3];
    s32 w58, w5c, w60, w64, w68, w6c, w70, w74, w78, w7c, w80, w84, w88, w8c;
};

struct SelArrays {
    char pad[0x44];
    s32 objects[4];
    s32 models[4];
};

static inline s32 getMode(s32 st) {
    s32 r;
    if (st >= 0 && st < 4) r = 1; else r = 0;
    if (r != 0) {
        r = 0;
    } else {
        s32 a;
        if (st >= 4 && st < 0xc) a = 1; else a = 0;
        if (a != 0) {
            r = 1;
        } else {
            s32 b;
            if (st >= 0xc && st < 0x10) b = 1; else b = 0;
            r = 3;
            if (b != 0) r = 2;
        }
    }
    return r;
}

static inline s32 randomInt(s32 max) {
    return (s32)((f32)max * lbl_805A0420.mtRand::randf());
}

extern "C" void fn_10_2DC0(char* self, s32 arg1, s32* __restrict arg2, s32 arg3) {
    Params p;
    char buf[8];
    u8* sel;
    u8* player;
    s32 st;
    s32 r;
    s32 v;
    s32 model;
    void* mem;
    f32 f;

    sel = (u8*)g_GameGlobal->m_selCharData;

    p.w10 = 0; p.w14 = 0; p.w18 = 0; p.w1c = 0;
    p.w20 = 0; p.w24 = 0; p.w28 = 0; p.w2c = 0;
    p.w30 = 0; p.w34 = 0; p.w38 = 0; p.w3c = 0;
    p.w40 = 0; p.w44 = 0; p.w48 = 0; p.w4c = 1;
    p.w50 = 0; p.b54 = 0; p.w58 = -1; p.w5c = 0;
    p.w60 = 0; p.w64 = 0; p.w68 = 0; p.w6c = 0;
    p.w70 = 0; p.w74 = 0; p.w78 = 0; p.w7c = 0;
    p.w80 = 0; p.w84 = 0; p.w88 = 0; p.w8c = 0;

    mem = gfHeapManager::getMEMAllocator((Heaps::HeapType)0x2a);
    model = fn_801AB6CC(mem, 0, 0x28);

    s32 a3;
    s32 a2;
    s32 a1;
    s32 a0;
    a0 = arg2[0];
    a1 = arg2[2];
    a2 = arg2[5];
    a3 = arg2[7];
    p.w20 = model;
    p.w10 = a0;
    p.w14 = a1;
    p.w18 = a2;
    p.w1c = a3;
    p.w24 = *(s32*)(self + 0x6c);
    p.w2c = arg1;
    p.w30 = 0xc;
    p.w34 = 0x50;
    p.w70 = (s32)self;
    p.w74 = fn_10_C380(self);
    p.w78 = 0x5a;
    p.w7c = arg1 + 0x4a;
    p.w80 = 0x62;
    p.w84 = arg1 + 0x63;
    p.w88 = arg2[11];
    p.w28 = *(s32*)(self + 0x430);

    p.w44 = *(s32*)(self + 0x70 + randomInt(*(s32*)(self + 0x138) - 1) * 4);

    if ((s32)((u8*)g_GameGlobal->m_selCharData)[4] == 17) {
        p.w48 = 0;
    } else {
        p.w48 = randomInt(getNumCharColor__6muMenuFiii(p.w44));
    }

    p.w4c = (s32)(lbl_10_rodata_38 * lbl_805A0420.mtRand::randf()) + 1;

    if (arg1 == 1 && (s32)((u8*)g_GameGlobal->m_selCharData)[4] == 0xa) {
        p.w6c = -1;
    } else {
        p.w6c = arg3;
    }

    player = sel + arg1 * 0x5c;
    st = ((u8*)g_GameGlobal->m_selCharData)[4];
    if (getMode(st) == 0 || getMode(st) == 1)
        r = 0;
    else
        r = 1;
    if (r != 0) {
        if (arg1 == 0) {
            v = 1;
        } else if ((s32)player[0xb9] == 0) {
            v = 1;
        } else {
            v = 0;
        }
    } else {
        s32 r0;
        if (st >= 0 && st < 4) r0 = 1; else r0 = 0;
        if (r0 != 0) {
            v = 0;
        } else {
            s32 a;
            if (st >= 4 && st < 0xc) a = 1; else a = 0;
            if (a != 0) {
                v = 1;
            } else {
                s32 b;
                if (st >= 0xc && st < 0x10) b = 1; else b = 0;
                v = 3;
                if (b != 0) v = 2;
            }
        }
        if (v == 1) {
            if (arg1 == 1 && st == 0xa) {
                v = 2;
            } else {
                v = 1;
            }
        } else {
            switch (player[0xb9]) {
            case 0:
                v = 1;
                break;
            case 1:
                v = 2;
                break;
            default:
                v = 0;
                break;
            }
        }
    }

    p.w38 = v;
    {
        s32 kind = sel[arg1 * 4 + 0xa];
        if (arg1 == 1 && (s32)((u8*)g_GameGlobal->m_selCharData)[4] == 0xa && kind == 0x28) {
            p.w3c = *(s32*)(self + 0x70 + randomInt(*(s32*)(self + 0x138) - 1) * 4);
            p.w40 = randomInt(getNumCharColor__6muMenuFiii(p.w3c));
        } else {
            p.w3c = kind;
            p.w40 = player[0xbd];
        }
    }
    p.w50 = player[0xc3];
    p.b54 = 0;
    if (p.w3c == 0x15 && p.w40 >= 6) {
        p.b54 = 1;
    }
    if (player[0xd0] == 0x78) {
        p.w58 = -1;
    } else {
        p.w58 = player[0xd0];
    }
    p.w5c = player[0xd1];
    if (*(u8*)(self + 0x5d0) != 0) {
        p.w60 = *(u16*)(player + 0xdc) / 10;
    } else {
        p.w60 = *(u16*)(player + 0xde) / 10;
    }
    p.w64 = player[0xd7];
    p.w68 = *(u16*)(sel + arg1 * 4 + 0xc);

    st = ((u8*)g_GameGlobal->m_selCharData)[4];
    switch (getMode(st)) {
    case 2:
    case 3:
        if (arg1 == 0) {
            p.w8c = 0;
        } else if (p.w38 == 1) {
            p.w8c = 0;
        } else {
            p.w8c = 1;
        }
        break;
    case 1:
        if (arg1 == 1) {
            if (st == 0xa) {
                p.w8c = 0;
            } else if (*(u8*)(self + 0x5fc) == 0) {
                p.w8c = 2;
            } else {
                p.w8c = 0;
            }
        }
        break;
    case 0:
        p.w8c = 0;
        break;
    }

    SelArrays* arrays = (SelArrays*)self;
    arrays->objects[arg1] = fn_10_10CAC(&p.w10);
    sprintf(buf, lbl_10_data_18,
            *(s32*)(self + 0x648) == 2 ? arg1 + 5 : arg1 + 1);
    fn_801B4CB0(*(s32*)(self + 0x430), model, fn_800B6AF0(*(s32*)(self + 0x168), buf));
    arrays->models[arg1] = model;
    if (p.w38 != 0) {
        fn_10_13CAC(arrays->objects[arg1]);
    }
}
