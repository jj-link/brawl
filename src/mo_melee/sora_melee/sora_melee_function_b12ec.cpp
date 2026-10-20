#include <types.h>
#pragma force_active on

extern "C" {

struct unk_27 {
    void *unk0;
    void *unk4;
    s32 unk8;
};

s32 fn_27_B12EC(const struct unk_27 *p) {
    return p->unk8 >> 27;
}

}
