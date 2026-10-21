#include <types.h>
#pragma force_active on

struct fnEv {
    u8 pad0[8];
    s16 a8;
    s16 aA;
    s16 aC;
};

class fnTarget {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(s32 a, void* b);
};

struct Holder {
    u8 pad0[0x70];
    fnTarget* target;
};

struct Ctx {
    u8 pad0[0xd8];
    Holder* holder;
};

class soEventManager {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(s32 a, s32 b);
};

class soEventSystem {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual u32 v6(s32 id);
};

extern "C" soEventSystem* getInstance__13soEventSystemFv();
extern "C" soEventManager* getManager__13soEventSystemFl(
    soEventSystem* self, s32 id);

extern "C" void fn_27_174B48(fnEv* arg0, s32* arg1, Ctx* arg2) {
    switch (*arg1) {
    case 0x34:
        s32 id = arg0->a8;
        soEventSystem* inst = getInstance__13soEventSystemFv();
        u32 r = inst->v6(id);
        if (r == 1) {
            soEventManager* mgr = getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), arg0->a8);
            mgr->v3(arg0->aA, arg0->aC);
        }
        arg0->aC = -1;
        arg0->a8 = -1;
        Holder* h = arg2->holder;
        h->target->v3(0xe, arg2);
        break;
    }
}
