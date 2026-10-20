#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_3EAB8[];

struct fn_27_1A2FF8_obj {
    char* unk0;
    char* unk4;
    u32 unk8;
};

void fn_27_1A2FF8(fn_27_1A2FF8_obj* p) {
    u32 flags = p->unk8;
    char* base = lbl_27_data_3EAB8;
    p->unk0 = base;
    p->unk4 = base + 0x48;
    p->unk8 = flags & 0x3FFFFF;
}
}
