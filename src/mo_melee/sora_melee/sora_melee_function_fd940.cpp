#include <types.h>
#pragma force_active on

class ObjBase {
public:
    virtual ~ObjBase();
    virtual void* vf1(void* p);
};

extern "C" {
void fn_27_FD940(ObjBase* self, u32* src, void* arg) {
    void* dst = self->vf1(arg);
    *(u32*)dst = *src;
}
}
