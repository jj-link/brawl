#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_1999C4(void* ptr, s32 a, s32 b);
void fn_27_19BF3C(void* ptr, s32 a, s32 b);
void fn_27_150320(void* ptr, void* a, s16 b, void* c, void* d);

void* fn_103_7FA8(void* object, void* arg2, s32 arg3) {
    fn_27_1999C4(object, 10, 0);
    fn_27_19BF3C(static_cast<u8*>(object) + 0x584, 2, 0);
    fn_27_150320(static_cast<u8*>(object) + 0x5B8, arg2, static_cast<s16>(arg3), object, reinterpret_cast<void*>(reinterpret_cast<u32>(object) + 0x584));
    return object;
}
}
