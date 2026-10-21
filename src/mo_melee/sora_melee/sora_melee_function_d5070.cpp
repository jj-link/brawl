#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_21030[];
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
}

struct EventSystem {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual u32 getEvent(s16);
};

struct EventMgr {
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void send(s16, s16);
};

struct Obj {
    void* vtbl;
    s16 m4;
    s16 m6;
    s16 m8;
};

extern "C" Obj* fn_27_D5070(Obj* p, s32 flags) {
    if (p != nullptr) {
        s16 id = p->m4;
        p->vtbl = lbl_27_data_21030;
        EventSystem* sys = (EventSystem*)getInstance__13soEventSystemFv();
        if (sys->getEvent(id) == 1) {
            EventMgr* mgr = (EventMgr*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), (long)p->m4);
            mgr->send(p->m6, p->m8);
        }
        p->m8 = -1;
        p->m4 = -1;
        if (flags > 0)
            __dl__FPv(p);
    }
    return p;
}
