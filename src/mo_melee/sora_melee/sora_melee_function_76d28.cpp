#include <types.h>
#pragma force_active on

struct FlagData {
    u8 on : 1;
    u8 rest : 7;
};

struct FlagWork {
    virtual void vf0() {}
    virtual FlagData* getFlag(s32 index) = 0;
};

struct Owner {
    u32 unk0;
    FlagWork* m4;
    s32 m8;
};

extern "C" bool fn_27_76D28(Owner* self, s32 index) {
    return self->m4->getFlag(index <= -1 ? self->m8 : index)->on;
}
