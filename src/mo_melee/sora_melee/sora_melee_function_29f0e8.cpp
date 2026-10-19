#include <types.h>
#pragma force_active on

class StageObject;

class soExternalValueAccesser {
public:
    static s32 getWorkInt(StageObject* obj, u32 index);
};

extern "C" bool fn_27_29F0E8(u32 unused0, u32 unused1, StageObject* obj) {
    return soExternalValueAccesser::getWorkInt(obj, 0x12000023) == 0;
}
