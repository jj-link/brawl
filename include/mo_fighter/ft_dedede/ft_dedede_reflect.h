#pragma once

#include <gf/gf_task.h>
#include <so/so_module_accesser.h>

// Partial single-base view of the projectile's fighter interface. Adding
// Fighter's observer bases would change the virtual slots used by this object.
#define DEDEDE_REFLECT_SLOTS(n) \
    virtual void reserved##n##0(); virtual void reserved##n##1(); \
    virtual void reserved##n##2(); virtual void reserved##n##3(); \
    virtual void reserved##n##4(); virtual void reserved##n##5(); \
    virtual void reserved##n##6(); virtual void reserved##n##7()
class DededeReflectFighter : public gfTask {
public:
    unsigned char middle[0x20];
    soModuleAccesser* m_moduleAccesser;
    unsigned char suffix[0x40];
    u8 reflectEnabled : 1;
    u8 otherFlags : 7;
    // The intervening virtual slots are declarations only, not implementations.
    DEDEDE_REFLECT_SLOTS(A); DEDEDE_REFLECT_SLOTS(B);
    DEDEDE_REFLECT_SLOTS(C); DEDEDE_REFLECT_SLOTS(D);
    DEDEDE_REFLECT_SLOTS(E); DEDEDE_REFLECT_SLOTS(F);
    DEDEDE_REFLECT_SLOTS(G); DEDEDE_REFLECT_SLOTS(H);
    DEDEDE_REFLECT_SLOTS(I); DEDEDE_REFLECT_SLOTS(J);
    DEDEDE_REFLECT_SLOTS(K); DEDEDE_REFLECT_SLOTS(L);
    DEDEDE_REFLECT_SLOTS(M); DEDEDE_REFLECT_SLOTS(N);
    virtual int onReflect();
    virtual int onReflectHit();
    virtual void reserved22C();
    virtual void resetReflect(int);
};
#undef DEDEDE_REFLECT_SLOTS

extern "C" int fn_117_20610(DededeReflectFighter*, u32 flags);
