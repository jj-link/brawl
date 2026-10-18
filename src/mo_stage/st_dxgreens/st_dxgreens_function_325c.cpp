#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void* p);

extern "C" {
class fn_79_325C_Obj {
public:
    ~fn_79_325C_Obj() {}
};

fn_79_325C_Obj* fn_79_325C(fn_79_325C_Obj* self, s32 shouldFree) {
    if (self != 0) {
        if (shouldFree > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
