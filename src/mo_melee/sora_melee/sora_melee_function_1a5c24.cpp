#include <types.h>
#pragma force_active on

extern "C" {

struct __fn27_struct {
    u32 unk0;
    u32 unk4;
    unsigned : 10;
    signed value : 10;
    unsigned : 12;
};

s32 fn_27_1A5C24(__fn27_struct* self) {
    return self->value;
}

}
