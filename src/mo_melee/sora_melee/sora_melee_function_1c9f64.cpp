#include <types.h>
#pragma force_active on

class stVirtualCopyBase {
public:
    virtual void vf0();
    virtual u32* vf1(void* dst);
};

extern "C" {
void fn_27_1C9F64(stVirtualCopyBase* self, u32* src, void* dst);
}

extern "C" void fn_27_1C9F64(stVirtualCopyBase* self, u32* src, void* dst) {
    u32* ret = self->vf1(dst);
    *ret = *src;
}
