#pragma force_active on
#include <types.h>

struct Provider {
    virtual int m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual int m5();
    virtual void m6();
    virtual void m7();
};

struct Param {
    u32 w0, w4, w8, wC, w10, w14, w18, w1C;
    u8 port;
    u8 pad[3];
    void* p1;
    void* p2;
    void* p3;
};

struct Pair {
    union {
        bool flag;
        u32 word;
    } a;
    u32 b;
};

struct Adv {
    char pad[0x4928];
    u32 a;
    u32 b;
};

struct Global {
    char pad[0x30];
    Adv* adv;
};

struct Self {
    char pad0[0x220];
    Provider* a;
    Provider* b;
    Provider* c;
    char pad1[0x248 - 0x22C];
    u32 f248;
    char pad2[4];
    u32 f250;
    u32 f254;
    char pad3[8];
    void* work;
    char pad4[0x27C - 0x264];
    u32 f27C;
    u32 f280;
    char pad5[0x3F0 - 0x284];
    void* f3F0;
};

extern "C" {
extern const Param lbl_33_rodata_18;
extern Global* g_GameGlobal;
extern u8 lbl_33_data_3C8[];
extern u8 lbl_33_data_3D4[];
extern u8 lbl_33_data_3DC[];
void* fn_80015DB4(void*, int, int, int, u16);
void* fn_800F7CCC(Param*, int, int);
void fn_800FA7B8(void*, int, int, void*, int, void*, void*);
void exit__6gfTaskFv(void*);

void fn_33_1B3C(Self* self) {
    Param param = lbl_33_rodata_18;
    param.w0 = self->f248;
    param.w4 = self->f254;
    param.w10 = self->f27C;
    param.w14 = self->f280;
    param.w18 = self->f250;

    Pair fallback;
    Pair value;
    Pair copy;

    Adv* adv = g_GameGlobal->adv;
    if (adv) {
        value.a.word = adv->a;
        value.b = adv->b;
    } else {
        fallback.a.flag = false;
        fallback.b = -1;
        value = fallback;
    }

    copy = value;
    param.port = copy.b;
    param.p1 = fn_80015DB4(self->f3F0, 0, 1, 5, (u16)0xFFFE);
    param.p2 = fn_80015DB4(self->f3F0, 0, 1, 6, (u16)0xFFFE);
    param.p3 = fn_80015DB4(self->f3F0, 0, 1, 7, (u16)0xFFFE);

    void* w = fn_800F7CCC(&param, 0x2A, 0x2B);
    if (self->work != 0) {
        exit__6gfTaskFv(self->work);
    }
    self->work = w;

    if (self->a != 0) {
        for (int i = 0; i < self->a->m1(); ) {
            int id = self->a->m5();
            fn_800FA7B8(self->work, id, 1, (char*)self->work + 0x3A4, 0x400, (char*)self->work + 0x13A4, lbl_33_data_3C8);
            i++;
            self->a->m7();
        }
    }
    if (self->b != 0) {
        for (int i = 0; i < self->b->m1(); ) {
            int id = self->b->m5();
            fn_800FA7B8(self->work, id, 1, (char*)self->work + 0x13A6, 0x400, (char*)self->work + 0x23A6, lbl_33_data_3D4);
            i++;
            self->b->m7();
        }
    }
    if (self->c != 0) {
        for (int i = 0; i < self->c->m1(); ) {
            int id = self->c->m5();
            fn_800FA7B8(self->work, id, 1, (char*)self->work + 0x23A8, 0x100, (char*)self->work + 0x27A8, lbl_33_data_3DC);
            i++;
            self->c->m7();
        }
    }
}
}
