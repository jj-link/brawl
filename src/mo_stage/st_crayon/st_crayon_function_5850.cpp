#include <types.h>
#pragma force_active on

extern "C" {

struct UnkCrayonState {
    u32 pad0;
    u32 pad4;
    struct {
        u32 : 2;
        s32 v : 2;
    } flags;
};

s32 fn_56_5850(const UnkCrayonState* p) {
    return p->flags.v;
}

}
