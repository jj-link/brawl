#include <types.h>
#pragma force_active on

class fnCopyBase {
public:
    virtual void vf0();
    virtual fnCopyBase* vf1(void* p);
};

extern "C" void fn_27_1C1ED0(fnCopyBase* self, fnCopyBase* src, void* arg) {
    fnCopyBase* r = self->vf1(arg);
    *(u32*)r = *(u32*)src;
}
