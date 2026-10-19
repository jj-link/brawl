#include <types.h>
#pragma force_active on

class fn27Obj {
public:
    virtual void f0();
    virtual fn27Obj* f1(void* p);
};

extern "C" {
void fn_27_1E4D80(fn27Obj* self, fn27Obj* other, void* p) {
    fn27Obj* r = self->f1(p);
    *(u32*)r = *(u32*)other;
}
}
