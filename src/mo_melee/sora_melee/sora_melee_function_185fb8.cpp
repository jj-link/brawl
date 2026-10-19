#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

struct fn27_185FB8Obj {
    ~fn27_185FB8Obj() { }
};

extern "C" fn27_185FB8Obj* fn_27_185FB8(fn27_185FB8Obj* self, s32 flags) {
    if (self != nullptr && flags > 0) {
        __dl__FPv(self);
    }
    return self;
}
