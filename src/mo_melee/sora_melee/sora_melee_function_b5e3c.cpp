#include <types.h>
#pragma force_active on

class soEventManager {
public:
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual void fn3(s16, s16);
};

class soEventSystem {
public:
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual void fn3();
    virtual void fn4();
    virtual void fn5();
    virtual u32 fn6(s16);
};

extern "C" {
soEventSystem* getInstance__13soEventSystemFv();
soEventManager* getManager__13soEventSystemFl(soEventSystem*, s32);
}

struct Self {
    char pad[0xC];
    s16 m_0C;
    s16 m_0E;
    s16 m_10;
    char pad12[0x26];
    s16 m_38;
    char pad3A[2];
    s32 m_3C;
};

extern "C" void fn_27_B5E3C(Self* self) {
    if (self->m_38 != -1) {
        self->m_38 = -1;
        if (self->m_38 > -1) {
            self->m_3C = 0;
        }
    }
    if (self->m_10 != -1) {
        s16 id = self->m_0C;
        soEventSystem* sys = getInstance__13soEventSystemFv();
        if (sys->fn6(id) == 1) {
            soEventManager* mgr = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->m_0C);
            mgr->fn3(self->m_0E, self->m_10);
        }
        self->m_10 = -1;
        self->m_0C = -1;
    }
}
