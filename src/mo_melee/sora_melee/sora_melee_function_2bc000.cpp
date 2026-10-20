#include <types.h>
#pragma force_active on

class soSequenceBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual u32 vf3();
};

extern "C" void* fn_27_2BC3B0(void*, u32);
extern "C" void fn_27_2BBC24(void*, void*);

extern "C" void fn_27_2BC000(soSequenceBase* self) {
    u32 n = self->vf3();
    void* v = fn_27_2BC3B0(self, n - 1);
    fn_27_2BBC24(self, v);
}
