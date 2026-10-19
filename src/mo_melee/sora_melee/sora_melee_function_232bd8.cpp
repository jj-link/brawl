#include <gf/gf_callback.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" gfCallBack* __dt__10gfCallBackFv(gfCallBack* self, int deleteFlag) {
    if (self != 0 && deleteFlag > 0) {
        __dl__FPv(self);
    }
    return self;
}
