#include <types.h>

#pragma force_active on

extern "C" void fn_27_1A8258(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_93_AE9C( void* a0,  s16 a1,  s32 a2,
                            s32 a3) {
     s32 r5 = a2;
    a2 = 0;
    fn_27_1A8258(a0, a1, a0, static_cast<s8>(r5));
}
