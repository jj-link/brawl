#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;

struct Rec {
    char pad[0x9c];
    u16 b15 : 1;
    u16 b14 : 1;
    u16 b13 : 1;
    u16 b12 : 1;
    u16 b11 : 1;
    u16 rest : 11;
    char pad2[0xb4 - 0x9e];
    u32 unkB4;
    char pad3[0xc0 - 0xb8];
    u32 unkC0;
    u32 unkC4;
};

struct Sub {
    char pad[0x34d4];
    u16 b15 : 1;
    u16 b14 : 1;
    u16 b13 : 1;
    u16 b12 : 1;
    u16 b11 : 1;
    u16 rest : 11;
};

struct GG {
    char pad[0x24];
    Sub* sub;
};

extern "C" Rec* fn_8004E5D8(GG*, int);
extern "C" GG* g_GameGlobal;

extern "C" int fn_800589C8(int arg0) {
    int result = 0;
    u32 count = 0;
    u32 minv = 0x4650;
    for (int i = 0; i < 0x23; i++) {
        if (fn_8004E5D8(g_GameGlobal, i)->b13 == 1) {
            count++;
            u32 v = fn_8004E5D8(g_GameGlobal, i)->unkB4;
            if (v < minv) {
                minv = v;
            }
        }
    }
    Sub* s = g_GameGlobal->sub;
    bool a = s->b13 == 1;
    bool b = s->b11 == 1;
    switch (arg0) {
    case 0x52:
        if (count != 0 || a == true) {
            result = 1;
        }
        break;
    case 0x6:
        if (count >= 0x23) {
            result = 1;
        }
        break;
    case 0x14:
        if (minv <= 0x3138) {
            result = 1;
        }
        break;
    case 0x60:
        if (minv <= 0x3840) {
            result = 1;
        }
        break;
    case 0x54:
        if (b == true) {
            result = 1;
        } else {
            for (int i = 0; i < 0x23; i++) {
                if (fn_8004E5D8(g_GameGlobal, i)->b11 == 1) {
                    result = 1;
                    break;
                }
            }
        }
        break;
    case 0x3F:
        for (int i = 0; i < 0x23; i++) {
            if (fn_8004E5D8(g_GameGlobal, i)->unkC4 >= 10) {
                result = 1;
                break;
            }
        }
        break;
    case 0x44:
        for (int i = 0; i < 0x23; i++) {
            if (fn_8004E5D8(g_GameGlobal, i)->unkC4 >= 5) {
                result = 1;
                break;
            }
        }
        break;
    case 0x74:
        for (int i = 0; i < 0x23; i++) {
            if (fn_8004E5D8(g_GameGlobal, i)->unkC0 >= 100) {
                result = 1;
                break;
            }
        }
        break;
    case 0x79:
        for (int i = 0; i < 0x23; i++) {
            if (fn_8004E5D8(g_GameGlobal, i)->unkC0 >= 50) {
                result = 1;
                break;
            }
        }
        break;
    }
    return result;
}
