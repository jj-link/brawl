#include <types.h>
#pragma force_active on

struct Fn27Data {
    u32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unka;
};

extern "C" {
void fn_27_1BA408(Fn27Data* p) {
    p->unk4 = -1;
    p->unk8 = 0;
    p->unka = -1;
}
}
