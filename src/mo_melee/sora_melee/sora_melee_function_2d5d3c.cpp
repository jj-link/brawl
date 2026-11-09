#include <types.h>
#include <ec/ec_mgr.h>
#include <mu/adv/mu_adv_seal.h>
#pragma force_active on

extern "C" {
extern muAdvSealTask* lbl_27_bss_7328;
}

struct FnObj27 {
    s32 m_0;
    s32 m_4;
    u32 m_8;
    u32 m_c;
};

class SealObj {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6(int, int);
};

struct SealMgr {
    char pad[0xc];
    SealObj* obj;
};

extern "C" void fn_27_2D5D3C(FnObj27* self) {
    SealObj* o;
    SealObj* o2;
    unsigned int off;

    g_ecMgr->setMdlAnmIdx(self->m_c, 1, 1);
    self->m_0 = 2;
    self->m_4 = 0;
    char* task;
    task = (char*)lbl_27_bss_7328;
    if (*(u8*)(task + 0x6a6) != 0 && *(s32*)(task + 0x4488) >= 2) {
        o = (**(SealMgr***)(task + 0x1AF10))->obj;
        if (o != NULL) {
            o->s6(1, 0);
            o->s6(6, 0);
            o->s6(7, 0);
        }
    int i;
        i = 0;
        off = 0;
        do {
            o2 = (*(SealMgr**)(*(char**)(task + 0x1AF0C) + off))->obj;
            if (o2 != NULL) {
                o2->s6(1, 0);
                o2->s6(6, 0);
                o2->s6(7, 0);
            }
            i += (1);
            off = off + (4);
        } while (i < 8);
    }
}
