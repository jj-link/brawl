#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_2AC698(void* self, s32 a, s32 b);

class fnSelf {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 v3();
};

extern "C" void fn_27_2AC340(fnSelf* self, s32* val) {
    s32 idx = fn_27_2AC698(self, self->v3() - 1, -1);
    if (idx >= 0) {
        *(s32*)((char*)self + idx * 12 + 12) = *val;
    }
}
