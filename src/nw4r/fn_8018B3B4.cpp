#include <types.h>
#pragma force_active on

struct Inner {
    u8 pad[0x8];
    u16 value;
};

struct Outer {
    u8 pad[0xC];
    Inner* inner;
};

extern "C" {

u16 fn_8018B3B4(Outer* self) {
    return self->inner->value;
}

}
