#pragma force_active on
#include <so/event/so_event_system.h>
typedef unsigned char u8x;
struct Self { unsigned int unk0, unk4; char pad8[0x20]; void* unk28; char pad2c[0x24]; int unk50; };
struct Pack { void* vt; short a,b; int c,d; };
struct FtSub {
 virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4();
 virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
 virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14();
 virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18(); virtual int f21();
};
struct FtMgr { char pad[0xb4]; FtSub sub; };
struct SysView { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual int f8(int); };
struct MgrView { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void* f6(int); virtual void f7(); virtual void f8(); virtual void f9(); virtual void* f10(int); };
struct UnitView { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual int f9(); };
extern "C" {
extern char lbl_27_data_261F0[], lbl_27_data_261B0[], lbl_27_data_26440[], __RTTI__11soEventUnit[];
extern char** g_ftEntryManager;
extern FtMgr* g_ftManager;
void fn_27_111CF8(void*);
void fn_27_1156C4(void*, void*, short);
void fn_27_15894C(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
inline int getUnit(MgrView* m, short id) {
    UnitView* u = (UnitView*)__dynamic_cast(m->f10(id), 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
    if (u == 0) return 0;
    return u->f9();
}
void fn_27_11676C(Self* self, unsigned int arg1) {
    int r31;
    short n;
    int r29;
    char* e;
    Pack pk;
    unsigned int blk[4];
    if (arg1 == 1) {
        int idx = self->unk50;
        if (idx != -1) {
            e = *g_ftEntryManager + (u8x)idx * 0x244;
            fn_27_111CF8(*(void**)(e + 0x28));
            int t = g_ftManager->sub.f21();
            fn_27_1156C4(blk, *(void**)(e + 4), (short)t);
            fn_27_15894C(blk);
            return;
        }
    }
    fn_27_111CF8(self->unk28);
    n = (short)g_ftManager->sub.f21();
    r31 = self->unk4;
    r29 = 0;
    pk.vt = lbl_27_data_261F0;
    pk.a = n;
    pk.b = 0;
    pk.c = 0;
    if (n > 0 && n > -1) {
        if (((SysView*)soEventSystem::getInstance())->f8(n) != 0) {
            MgrView* m1 = (MgrView*)soEventSystem::getInstance()->getManager(pk.a);
            if (m1->f6(pk.b) == 0) {
                pk.c = r29;
            } else {
                MgrView* m2;
                short r28 = pk.b;
                m2 = (MgrView*)soEventSystem::getInstance()->getManager(pk.a);
                if (m2->f6(r28) == 0) {
                    r29 = 0;
                } else {
                    r29 = getUnit(m2, r28);
                }
                pk.c = r29;
            }
        }
    }
    pk.d = r31;
    pk.vt = lbl_27_data_261B0;
    fn_27_15894C(&pk);
}
}