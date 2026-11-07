#include <types.h>
#pragma force_active on

struct Self {
    unsigned int unk0;
    unsigned int unk4;
    char pad8[0x9];
    unsigned char unk11;
    char pad12[0x16];
    void* unk28;
    char pad2c[0x24];
    int unk50;
};

struct Pack {
    void* vt;
    short a, b;
    int c, d;
};

struct FtEntryMgr {
    char* base;
    char pad4[0x38];
    unsigned char f3c;
    char pad3d[0x7];
    void* f44;
    void* f48;
};

struct FtSub {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4();
    virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
    virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14();
    virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18();
    virtual int f21();
};

struct FtMgr {
    char pad[0xb4];
    FtSub sub;
};

struct EvSys {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5();
    virtual int f8(int);
};

struct MgrView {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void* f6(int);
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void* f10(int);
};

struct UnitView {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6();
    virtual int f9();
};

extern "C" {
extern char lbl_27_data_261F0[], lbl_27_data_261B0[], lbl_27_data_26440[], __RTTI__11soEventUnit[];
extern FtEntryMgr* g_ftEntryManager;
extern FtMgr* g_ftManager;
void fn_27_111CF8(void*);
void fn_27_1156C4(void*, void*, short);
void fn_27_15894C(void*);
void fn_27_11967C(void*, unsigned int, void*, void*, unsigned int, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
}

inline int getUnit(MgrView* m, short id) {
    UnitView* u = (UnitView*)__dynamic_cast(m->f10(id), 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
    if (u == 0) return 0;
    return u->f9();
}

extern "C" void fn_27_1135B4(Self* self) {
    Pack pk;
    unsigned int blk[4];
    unsigned int unk4;
    short n;
    int res;

    if (self->unk50 != -1 && g_ftEntryManager->f3c == 1) {
        fn_27_11967C(g_ftEntryManager, 0, g_ftEntryManager->f44, g_ftEntryManager->f48, 0, -1);
    }
    if (self->unk50 != -1) {
        char* e = g_ftEntryManager->base + (unsigned char)self->unk50 * 0x244;
        fn_27_111CF8(*(void**)(e + 0x28));
        int t = g_ftManager->sub.f21();
        fn_27_1156C4(blk, *(void**)(e + 4), (short)t);
        fn_27_15894C(blk);
    } else {
        fn_27_111CF8(self->unk28);
        n = (short)g_ftManager->sub.f21();
        unk4 = self->unk4;
        res = 0;
        pk.vt = lbl_27_data_261F0;
        pk.a = n;
        pk.b = 0;
        pk.c = 0;
        if (n > 0 && n > -1) {
            if (((EvSys*)getInstance__13soEventSystemFv())->f8(n) != 0) {
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
        fn_27_15894C(&pk);
    }
    self->unk11 |= 2;
}
