#include <types.h>
#pragma force_active on

extern "C" {
void __dt__14snd3DGeneratorFv(void* self, int flags);
void __dl__FPv(void* p);
}

extern "C" void* fn_81_518(void* self, int del)
{
    if (self != 0) {
        __dt__14snd3DGeneratorFv(self, -1);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
