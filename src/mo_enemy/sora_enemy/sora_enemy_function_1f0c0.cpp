#include <types.h>
#pragma force_active on

extern "C" {
int fn_41_1AE30(void*);

struct Fn41Obj {
    u8 pad[8];
    void* unk08;
};

bool fn_41_1F0C0(Fn41Obj* self, int val) {
    return fn_41_1AE30(self->unk08) == val;
}
}
