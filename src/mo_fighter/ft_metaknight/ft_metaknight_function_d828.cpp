#include <types.h>
#pragma force_active on

extern "C" void fn_111_D9D0(void* object);
extern "C" void fn_111_DA68(void* object);

extern "C" void fn_111_D828(void* unused, void* object, s32 code) {
    if (code != 0x121 && code != 0x120) {
        fn_111_D9D0(object);
        fn_111_DA68(object);
    }
}
