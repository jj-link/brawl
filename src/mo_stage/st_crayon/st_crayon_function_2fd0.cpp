#include <stddef.h>
#pragma force_active on

extern "C" {
void __dt__14snd3DGeneratorFv(void* self, int flags);
void __dt__16grCrayonYakumonoFv(void* self, int flags);
void __dl__FPv(void* ptr);

void* fn_56_2FD0(void* self, int deleteFlag) {
    void* result = self;
    if (self != NULL) {
        __dt__14snd3DGeneratorFv((char*)self + 0x1B8, -1);
        __dt__16grCrayonYakumonoFv(self, 0);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return result;
}
}
