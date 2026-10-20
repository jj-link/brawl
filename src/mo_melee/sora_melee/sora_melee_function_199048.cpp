#include <types.h>
#pragma force_active on

extern "C" {

struct Foo {
    u32 unk0;
    u32 unk4;
    unsigned : 9;
    u32 field : 1;
};

u32 fn_27_199048(Foo* self) {
    return self->field;
}

}
