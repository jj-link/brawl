#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Obj {
    u8 pad00[0x80];
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    u16 unk98;
    u8 pad9A[2];
    s32 unk9C;
    u16 unkA0;
    u8 padA2[6];
    u16 unkA8;
    u8 padAA[2];
    s32 unkAC;
    u16 unkB0;
    u8 padB2[6];
    u16 unkB8;
    u8 padBA[2];
    s32 unkBC;
    u16 unkC0;
    u8 padC2[14];
    u16 unkD0;
    u8 padD2[2];
    s32 unkD4;
} Obj;

#define ABSV(x) ((((x) >> 31) ^ (x)) - ((x) >> 31))

s32 fn_80385A04(Obj *p) {
    s32 r6;
    u16 tA0;
    u16 t98;

    r6 = p->unk9C;
    p->unk8C = 6;
    p->unk88 = 4;
    p->unkD4 = 1;
    if (r6 == 0 || p->unkAC == 0 || p->unkBC == 0) {
        return 0;
    }
    if (p->unk84 == 0 && p->unk80 == 0 && (u32)r6 == (u32)p->unk94) {
        p->unk8C = 0;
    } else if ((u32)r6 == (u32)p->unk94) {
        p->unk8C = 1;
    } else {
        r6 = p->unk80;
        if (r6 == 0 && p->unk84 == 0 && ABSV((s32)p->unkC0 - (s32)p->unkB0) >= 1) {
            p->unk8C = 5;
            p->unk88 = 0;
        } else if (r6 != 0 && p->unk84 == 0 && ABSV((s32)p->unkC0 - (s32)p->unkB0) >= 1) {
            p->unk8C = 5;
            p->unk88 = 2;
        } else if (r6 == 0 && p->unk84 != 0 && ABSV((s32)p->unkC0 - (s32)p->unkB0) >= 1) {
            p->unk8C = 5;
            p->unk88 = 3;
        } else if (r6 != 0 && p->unk84 != 0 && ABSV((s32)p->unkC0 - (s32)p->unkB0) >= 1) {
            p->unk8C = 5;
            p->unk88 = 1;
        } else {
            if (p->unk84 != 0) {
                p->unk8C = 4;
            } else {
                if (r6 != 0 && p->unk84 == 0) {
                    p->unk8C = 3;
                } else if (r6 == 0 && p->unk84 == 0) {
                    p->unk8C = 2;
                } else {
                    p->unk8C = 6;
                }
            }
        }
    }

    t98 = p->unk98;
    tA0 = p->unkA0;
    if (tA0 == t98 && p->unkB0 == p->unkA8 && p->unkC0 == p->unkB8) {
        p->unk90 = 1;
    } else if (tA0 == p->unkB0 && p->unkB0 == p->unkC0) {
        p->unk90 = 2;
    } else if (tA0 == t98 && (s32)p->unkC0 - (s32)p->unkB0 == 1) {
        p->unk90 = 4;
    } else if ((s32)p->unkC0 - (s32)p->unkB0 == 1) {
        p->unk90 = 3;
    } else {
        p->unk90 = 0;
    }

    if (p->unkD0 != 0 && p->unkA0 != p->unkD0) {
        p->unkD4 = 0;
    }
    return 1;
}
