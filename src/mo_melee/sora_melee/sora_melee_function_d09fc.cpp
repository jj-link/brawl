#include <types.h>
#pragma force_active on

struct Unk_27 {
    u32 a;
    u32 b;
    u32 c;
};

extern "C" u32 fn_27_D09FC(const Unk_27* self) {
    return (self->c >> 10) & 1;
}
