#include <StaticAssert.h>
#include <sora_adv_stage/gr_adventure_final.h>
#pragma force_active on

struct Unk8 {
    u32 pad[2];
    int field8;
};

extern "C" int fn_40_1E400(Unk8 *r3)
{
    return r3->field8 >> 26;
}
