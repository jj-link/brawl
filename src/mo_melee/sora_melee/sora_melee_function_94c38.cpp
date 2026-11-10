#include <types.h>
#pragma force_active on

class Mgr {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(s16 a, s16 b);
};

class soEventSystem {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual u32 v6(s16 id);
};

extern "C" soEventSystem* getInstance__13soEventSystemFv();
extern "C" Mgr* getManager__13soEventSystemFl(soEventSystem*, s32);

class Container {
public:
    virtual void fn08();
    virtual void* fn0c(s32);
    virtual void fn10();
    virtual s32 fn14();
    virtual void fn18();
    virtual void fn1c();
    virtual void fn20();
    virtual void fn24();
    virtual void fn28();
    virtual void fn2c();
    virtual void fn30();
    virtual void fn34();
    virtual void fn38(s32);
};

class Event {
public:
    virtual void fn08();
    virtual void fn0c();
    virtual void fn10();
    virtual void fn14();
    virtual void fn18();
    virtual void fn1c();
    virtual void fn20();
    virtual s32 fn24();
    virtual void* fn28();
    virtual void fn2c();
    virtual void fn30();
    virtual void fn34();
    virtual void fn38();
    virtual void fn3c();
    virtual void fn40();
    virtual void fn44();
    virtual void fn48();
    virtual void fn4c();
    virtual void fn50();
    virtual void fn54();
    virtual void fn58();
    virtual void fn5c();
    virtual void fn60();
    virtual void fn64();
    virtual void fn68();
    virtual void fn6c();
    virtual void fn70(s32);
};

struct Ev { s16 m0; s16 m2; s16 m4; s16 m6; s16 m8; };

struct Self { char pad[0x2C]; Container* m_2c; char pad30[4]; Container* m_34; };

extern "C" void fn_27_94C38(Self* self, void* arg1) {
    s32 j;
    Event* ev;
    s16 t;
    s32 i;
    s32 n;
    Ev* entry;
    s32 id;

    for (i = self->m_2c->fn14() - 1; i >= 0; i--) {
        if (*(Event**)self->m_2c->fn0c(i) != 0 && arg1 == (*(Event**)self->m_2c->fn0c(i))->fn28()) {
            ev = *(Event**)self->m_2c->fn0c(i);
            n = self->m_34->fn14();
            for (j = 0; j < n; j++) {
                id = ev->fn24();
                entry = (Ev*)self->m_34->fn0c(j);
                if ((s16)id != -1) {
                    t = entry->m4;
                    if ((s16)id == t) {
                        if (getInstance__13soEventSystemFv()->v6(t) == 1) {
                            getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), entry->m4)->v3(entry->m6, entry->m8);
                        }
                        entry->m8 = -1;
                        entry->m4 = -1;
                    }
                }
            }
            self->m_2c->fn38(i);
            ev->fn70(1);
        }
    }
}
