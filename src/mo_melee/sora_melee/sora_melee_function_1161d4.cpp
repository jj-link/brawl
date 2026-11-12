#include <types.h>
#pragma force_active on

typedef unsigned char u8x;

struct Self {
    unsigned int unk0, unk4;
    char pad8[0x20];
    void* unk28;
    char pad2c[0x24];
    int unk50;
};

struct Entry {
    char pad0[4];
    void* field4;
    char pad8[0x20];
    void* field28;
};

struct Pack {
    void* vt;
    short a, b;
    int c, d;
};

struct FtSub {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual int f21();
};

struct FtMgr {
    char pad[0xb4];
    FtSub sub;
};

struct SysView {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual int f8(int);
};

struct MgrView {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void* f6(int); virtual void f7(); virtual void f8(); virtual void f9();
    virtual void* f10(int);
};

struct UnitView {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual int f9();
};

extern "C" {
extern char lbl_27_data_261F0[], lbl_27_data_261B0[], lbl_27_data_26440[], __RTTI__11soEventUnit[];
extern char** g_ftEntryManager;
extern FtMgr* g_ftManager;
void fn_27_111BF4(void*, int);
u8 fn_27_111D70(void*);
void fn_27_1156C4(void*, void*, short);
void fn_27_158320(void*, int);
void fn_27_158738(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
}

inline int getUnit(MgrView* m, short id) {
    UnitView* u = (UnitView*)__dynamic_cast(m->f10(id), 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
    if (u == 0) return 0;
    return u->f9();
}

extern "C" int fn_27_1161D4(Self* self, int arg1, unsigned int arg2) {
    Pack pk;
    Pack pk2;
    unsigned int blk2[4];
    unsigned int blk[4];
    unsigned int unk4;
    short n;
    MgrView* m2b;
    int res;
    unsigned int unk4b;

    if (arg2 == 1) {
        int idx = self->unk50;
        if (idx != -1) {
            Entry* e = (Entry*)(*g_ftEntryManager + (u8x)idx * 0x244);
            fn_27_111BF4(e->field28, arg1);
            int t = g_ftManager->sub.f21();
            fn_27_1156C4(blk, e->field4, (short)t);
            fn_27_158320(blk, arg1);
            if (fn_27_111D70(e->field28) > 2) {
                int t2 = g_ftManager->sub.f21();
                fn_27_1156C4(blk2, e->field4, (short)t2);
                fn_27_158738(blk2);
                return 1;
            }
            return 0;
        }
    }
    fn_27_111BF4(self->unk28, arg1);
    n = (short)g_ftManager->sub.f21();
    unk4 = self->unk4;
    res = 0;
    pk.vt = lbl_27_data_261F0;
    pk.a = n;
    pk.b = 0;
    pk.c = 0;
    if (n > 0 && n > -1) {
        if (((SysView*)getInstance__13soEventSystemFv())->f8(n) != 0) {
            MgrView* m1 = (MgrView*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), pk.a);
            if (m1->f6(pk.b) == 0) {
                pk.c = res;
            } else {
                MgrView* m2;
                short r27 = pk.b;
                m2 = (MgrView*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), pk.a);
                if (m2->f6(r27) == 0) {
                    res = 0;
                } else {
                    res = getUnit(m2, r27);
                }
                pk.c = res;
            }
        }
    }
    pk.d = unk4;
    pk.vt = lbl_27_data_261B0;
    fn_27_158320(&pk, arg1);
    if (fn_27_111D70(self->unk28) > 2) {
    short nb;
        nb = (short)g_ftManager->sub.f21();
        unk4b = self->unk4;
        res = 0;
        pk2.vt = lbl_27_data_261F0;
        pk2.a = nb;
        pk2.b = 0;
        pk2.c = 0;
        if (nb > 0 && nb > -1) {
            if (((SysView*)getInstance__13soEventSystemFv())->f8(nb) != 0) {
                MgrView* m1 = (MgrView*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), pk2.a);
                if (m1->f6(pk2.b) == 0) {
                    pk2.c = res;
                } else {
                    short r27 = pk2.b;
                    m2b = (MgrView*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), pk2.a);
                    if (m2b->f6(r27) == 0) {
                        res = 0;
                    } else {
                        res = getUnit(m2b, r27);
                    }
                    pk2.c = res;
                }
            }
        }
        pk2.d = unk4b;
        pk2.vt = lbl_27_data_261B0;
        fn_27_158738(&pk2);
        return 1;
    }
    return 0;
}
