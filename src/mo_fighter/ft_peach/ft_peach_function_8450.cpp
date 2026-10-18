#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_71CC(void* owner, u8 flag);
extern u8 lbl_103_data_183C[];

void* fn_103_8450(void* owner, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    fn_103_71CC(owner, 0);
    u32* words = static_cast<u32*>(owner);
    u8* data = lbl_103_data_183C;
    words[2] = reinterpret_cast<u32>(data);
    words[0] = reinterpret_cast<u32>(data + 8);
    words[3] = a;
    words[4] = b;
    words[5] = c;
    words[6] = d;
    words[7] = e;
    words[8] = f;
    return owner;
}
}
