#include <types.h>
#pragma force_active on

class fnBase {
public:
    virtual ~fnBase();
    virtual fnBase* f1(void* p);
};

extern "C" {
void fn_27_264234(fnBase* self, fnBase* src, void* p) {
    fnBase* r = self->f1(p);
    *(u32*)r = *(u32*)src;
}
}
