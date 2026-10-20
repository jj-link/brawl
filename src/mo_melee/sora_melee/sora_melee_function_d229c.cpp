#include <types.h>
#pragma force_active on

extern "C" {

struct sora_melee_fn27_X {
    u32 a;
    u32 b;
    u32 flags;
};

u32 fn_27_D229C(struct sora_melee_fn27_X* p)
{
    return (p->flags >> 19) & 1;
}

}
