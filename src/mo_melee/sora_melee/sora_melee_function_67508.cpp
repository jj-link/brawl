#include <types.h>
#pragma force_active on

class ModA {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24();
    virtual void v25();
};

class ModB {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(void*, bool, bool);
};

struct Table {
    char pad0[0x54];
    ModA* a;
    char pad1[0x70 - 0x58];
    ModB* b;
};

struct Acc {
    char pad[0xd8];
    Table* t;
};

struct World {
    char pad[0xc];
    u8 flag;
};

extern World* g_soWorld;

class soStopModuleImpl {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void cancelHitStop();

    char pad4[0xc];
    s32 a;
    s32 b;
    char pad18[4];
    u8 m_isStop : 1;
    u8 m_isHit : 1;
    u8 m_isDamage : 1;
    u8 b4 : 1;
    u8 b3 : 1;
    u8 m_isSpecialStop : 1;
    u8 b1 : 1;
    u8 b0 : 1;
    Acc* acc;
};

void soStopModuleImpl::cancelHitStop() {
    a = 0;
    b = 0;
    m_isHit = 0;
    if (m_isHit == 0 && !b4 && !b3 && !m_isSpecialStop && g_soWorld->flag == 0) {
        if (m_isStop == 1) {
            bool hit = m_isHit != 0;
            bool dmg = m_isDamage != 0;
            a = 0;
            b = 0;
            m_isStop = 0;
            m_isHit = 0;
            b3 = 0;
            m_isDamage = 0;
            acc->t->a->v25();
            acc->t->b->v15(acc, hit, dmg);
        }
    } else {
        if (!m_isStop) {
            m_isStop = 1;
            acc->t->a->v24();
        }
    }
}
