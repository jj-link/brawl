#include <types.h>
#pragma force_active on

struct Foo {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" void fn_27_1A7094(Foo* self) {
    self->unk8 |= 0x80000;
}
