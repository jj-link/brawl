#include <types.h>
#pragma force_active on

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);

extern "C" void fn_27_FF24(void* self) {
    EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(self, 1);
    EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(self, 2);
    *(s16*)((u8*)self + 0x122) = 0;
}
