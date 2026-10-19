#include <types.h>
#pragma force_active on

extern "C" bool isReady__14gfFileIOHandleCFv(const void*);
extern "C" bool fn_8007EF64(void*);
extern "C" int fn_8007EF68(void*);

extern "C" bool fn_24_2C98(void* self) {
    if (!isReady__14gfFileIOHandleCFv((char*)self + 0x40)) {
        return true;
    }
    if (!isReady__14gfFileIOHandleCFv((char*)self + 0x44)) {
        return true;
    }
    if ((int)fn_8007EF64(*(void**)((char*)self + 0x54)) != 1) {
        return true;
    }
    *(int*)((char*)self + 0x58) = fn_8007EF68(*(void**)((char*)self + 0x54));
    return false;
}
