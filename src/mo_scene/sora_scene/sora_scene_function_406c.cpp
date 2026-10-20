#include <types.h>
#pragma force_active on

class gfHeapManager {
public:
    static void free(void* ptr);
};

struct UnkFlags {
    u8 bit7 : 1;
    u8 bit6 : 1;
    u8 bit5 : 1;
    u8 rest : 5;
};

struct UnkObj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    void* unk10;
    u32 unk14;
    u32 unk18;
    UnkFlags unk1C;
};

extern "C" void fn_1_406C(UnkObj* self) {
    if (self->unk10) {
        gfHeapManager::free(self->unk10);
    }
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    self->unk10 = nullptr;
    self->unk18 = 0;
    self->unk14 = 0xFF;
    self->unk1C.bit7 = 0;
    self->unk1C.bit5 = 0;
}
