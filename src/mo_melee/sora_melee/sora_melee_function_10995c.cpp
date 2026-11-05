#include <so/event/so_event_system.h>
#include <ft/ft_entry_manager.h>
#include <types.h>
#pragma force_active on

struct Pack {
    void* vt;
    short a, b;
    int c;
    unsigned long d;
};

struct FtSub {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual int f21();
};

struct UnitView {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual int f9();
};

extern "C" {
extern char lbl_27_data_261F0[];
extern char lbl_27_data_261B0[];
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[];
extern char lbl_27_data_26100[];
extern void* g_ftSlotManager;

void fn_27_1135B4();
void fn_27_1137D4(void*);
void fn_27_121814(void*, int);
void fn_27_159184(void*);
void OSReport(const char*, ...);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

inline int getUnit(Pack* pk) {
    short id = pk->b;
    soEventManager* m = soEventSystem::getInstance()->getManager(pk->a);
    if (m->getObserverCapacity(id) == 0)
        return 0;

    UnitView* u = (UnitView*)__dynamic_cast(
        m->getEventUnit(id), 0, lbl_27_data_26440,
        __RTTI__11soEventUnit, 0);
    if (u == 0)
        return 0;
    return u->f9();
}

inline void doEvent(char* self, unsigned long id) {
    int r27;
    short n;

    n = (short)((FtSub*)(self + 0xb4))->f21();
    r27 = 0;
    Pack pk;
    pk.vt = lbl_27_data_261F0;
    pk.a = n;
    pk.b = 0;
    pk.c = 0;

    if (n > 0 && n > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(n)) {
            if (soEventSystem::getInstance()->getManager(pk.a)
                    ->getObserverCapacity(pk.b) == 0) {
                pk.c = r27;
            } else {
                r27 = getUnit(&pk);
                pk.c = r27;
            }
        }
    }

    pk.d = id;
    pk.vt = lbl_27_data_261B0;
    fn_27_159184(&pk);
}

inline void body(char* ent, char* self, unsigned long id, unsigned long flag) {
    fn_27_1135B4();
    doEvent(self, id);

    int idx = *(int*)(ent + 0x18);
    char* slot = *(char**)g_ftSlotManager + idx * 0x4d4;
    slot[0x15c] = 0x10;
    slot[0x159] = slot[0x159] - 1;

    if (flag == 1)
        fn_27_121814(g_ftSlotManager, *(int*)(ent + 0x18));

    fn_27_1137D4(ent);
    unsigned char b = *(unsigned char*)(self + 0x6f);
    self[0x6b] = 0x10;
    b |= 0x20;
    self[0x6f] = b;
    OSReport(lbl_27_data_26100, id, b);
}

extern "C" void fn_27_10995C(
    char* self, unsigned long id, unsigned long flag) {
    char* ent = (char*)((ftEntryManager*)*(void**)(self + 0x154))
        ->getEntity(id);
    body(ent, self, id, flag);
}
