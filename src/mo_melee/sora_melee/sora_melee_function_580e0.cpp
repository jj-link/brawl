#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

struct fn_27_Obj {
    ~fn_27_Obj() { }
};

extern "C" fn_27_Obj* fn_27_580E0(fn_27_Obj* self, s32 flags) {
    if (self != nullptr && flags > 0) {
        __dl__FPv(self);
    }
    return self;
}
