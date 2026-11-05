#include <types.h>
#pragma force_active on

class ObjTarget {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(s32, void*);
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual s32 vf16();
};

struct ObjSub {
    u8 pad[0x70];
    ObjTarget* m_target;
};

struct ObjMod {
    u8 pad[0xd8];
    ObjSub* m_sub;
};

struct ObjSelf {
    u8 pad[0x60];
    ObjMod* m_mod;
};

extern "C" s32 fn_27_1DAF80(void*, s32);

extern "C" s32 fn_27_2EA124(ObjSelf* self, s32 arg1) {
    ObjMod* mod = self->m_mod;
    if (mod->m_sub->m_target->vf16() == 0 && (arg1 & 3)) {
        mod->m_sub->m_target->vf3(1, mod);
        return 0;
    }
    return fn_27_1DAF80(self, arg1);
}