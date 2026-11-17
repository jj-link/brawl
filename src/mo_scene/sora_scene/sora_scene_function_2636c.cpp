#include <types.h>
#pragma force_active on

extern "C" {
extern void* g_GameGlobal;
extern u8 lbl_1_data_7548[];
extern f64 lbl_1_rodata_A28;
extern f64 lbl_1_rodata_A30;
void* getInstance__14gfSceneManagerFv(void);
void* searchScene__14gfSceneManagerFPCc(void*, const char*);
int exchangeGmCharacterKind2MuStockchkind__6muMenuFi(int);
void* memset(void*, int, unsigned long);
}

struct Entry {
    s32 kind;
    s32 val;
};

struct Data {
    s32 a;
    s32 b;
    s32 count1;
    Entry e1[3];
    s32 count2;
    Entry e2[2];
};

extern "C" void fn_1_2636C(void* arg0) {
    Data d;
    u8* r31;
    u8* r30;
    s32* p29;
    s32* p28;
    u8* r27;
    s32 cnt26;
    s32 cnt25;
    s32 r24;
    s32 res;
    f64 f31;
    f64 f30;

    r30 = *(u8**)((u8*)g_GameGlobal + 8);
    d.a = 0;
    d.b = 0;
    d.count1 = 1;
    d.count2 = 0;
    memset(d.e1, 0, 0x18);
    memset(d.e2, 0, 0x10);
    d.a = *(s32*)((u8*)arg0 + 0x14);
    d.b = 0;
    if (*(u16*)(r30 + 0x1A) == 0x38) {
        d.b = 2;
    }
    if (*(u8*)(r30 + 0x14) == 4) {
        u8* t = *(u8**)((u8*)g_GameGlobal + 0x3C);
        d.b = 1;
        d.count1 = 10;
        res = exchangeGmCharacterKind2MuStockchkind__6muMenuFi(t[0xA]);
        d.e1[0].kind = res;
        d.e1[0].val = 0;
    } else {
        f30 = lbl_1_rodata_A28;
        f31 = lbl_1_rodata_A30;
        p29 = &d.a;
        p28 = &d.a;
        r31 = r30 + 0x5C;
        r27 = r30 + 0x10F;
        cnt26 = 0;
        cnt25 = 0;
        r24 = 1;
        do {
            if (*(u8*)(r31 + 0x99) == 1) {
                s32 r3 = exchangeGmCharacterKind2MuStockchkind__6muMenuFi(*(u8*)(r31 + 0x98));
                if (*(u8*)(r30 + 0x13) == 1 && *(u8*)(r30 + 0xA3) == *(u8*)(r31 + 0xA3)) {
                    p29[10] = r3;
                    p29 += 2;
                    cnt25 += 1;
                } else {
                    p28[3] = r3;
                    r3 = 0;
                    if (*(f32*)(r31 + 0xD8) >= f30) {
                        r3 = 2;
                    }
                    if (*(f32*)(r31 + 0xD8) <= f31) {
                        r3 = 1;
                    }
                    if ((((u32)*r27 >> 4) & 1U) == 1U) {
                        r3 = 3;
                    }
                    p28[4] = r3;
                    p28 += 2;
                    cnt26 += 1;
                }
            }
            r24 += 1;
            r31 += 0x5C;
            r27 += 0x5C;
        } while (r24 < 4);
        d.count1 = cnt26;
        d.count2 = cnt25;
    }
    u8* sc = (u8*)searchScene__14gfSceneManagerFPCc(getInstance__14gfSceneManagerFv(), (const char*)lbl_1_data_7548);
    *(Data*)(sc + 0x35C) = d;
}
