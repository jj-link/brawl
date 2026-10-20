#include <types.h>
#pragma force_active on

extern "C" void fn_27_37960(void* self, float value, void* p);

class SoraInner {
public:
    virtual void* vfn0();
    virtual void* vfn3(float value);
};

extern "C" {
void fn_27_3A54C(u8* self, float value) {
    SoraInner* inner = *(SoraInner**)(self + 0x30);
    void* res = inner->vfn3(value);
    fn_27_37960(self + 0x68, value, *(void**)((u8*)res + 0x88));
}
}
