#include <types.h>
#pragma force_active on

extern "C" void fn_27_199B5C(void* object, s32 a, s32 b);
extern "C" void fn_27_6A244(void* a, void* b, void* c);

extern "C" void* fn_111_6B4C(void* object, void* arg) {
    fn_27_199B5C(object, 12, 0);
    fn_27_6A244(static_cast<u8*>(object) + 0x27c, arg, object);
    return object;
}
