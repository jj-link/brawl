#include <types.h>
#pragma force_active on

extern "C" void* fn_8027E074(void* self, u32 a, u32 value);

extern "C" void* fn_803313A0(u8* arg0, void* arg1, u32 arg2) {
    void* result = fn_8027E074(arg0 + 8, arg2, 0);
    if (result != 0) {
        void (*fn)(void*) = (void (*)(void*)) ((void**)result)[1];
        if (fn != 0) {
            fn(arg1);
        }
    }
    return result;
}
