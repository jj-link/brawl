#include <types.h>
#pragma force_active on

extern "C" void fn_80281BBC(void*, void*, int);

struct Fn8032F030Data {
    u8 pad0[0x10];
    int unk10;
    void* unk14;
};

struct Fn8032F030Self {
    Fn8032F030Data* unk0;
    void* unk4;
    u8 pad8[0x14];
    u8* unk1C;
    u8 pad20[0x8];
    u8 unk28;
    u8 unk29;
};

extern "C" void fn_8032F030(Fn8032F030Self* self) {
    fn_80281BBC(self->unk4, self->unk0->unk14, self->unk0->unk10 * 0x30);
    for (int i = 0; i < self->unk0->unk10; i++) {
        self->unk1C[i] = 2;
    }
    self->unk28 = 0;
    self->unk29 = 1;
}
