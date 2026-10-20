#include <types.h>
#pragma force_active on

class soTarget {
public:
    u8 m_pad[5];
    u8 m_flag7 : 1;
    u8 m_rest : 7;
};

class soCaller {
public:
    virtual ~soCaller();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual soTarget* vfunc8(void* p);
    virtual u32 vfunc9();
};

extern "C" {
void fn_27_89544(soCaller* self, void* p) {
    if (self->vfunc9() == 1) {
        soTarget* t = self->vfunc8(p);
        t->m_flag7 = 0;
    }
}
}
