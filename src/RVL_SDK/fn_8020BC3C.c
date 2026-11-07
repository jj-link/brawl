#include <types.h>
#pragma force_active on

extern s32 fn_8020CAD4(void);
extern s32 fn_802152E0(s32);
extern s32 fn_8020CAEC(void);

typedef struct {
    s32 unk0;
    u8 padding[0x86];
    u8 unk8A;
} struct_8020BC3C;

s32 fn_8020BC3C(struct_8020BC3C *arg0) {
    if (fn_8020CAD4() == 0) {
        return -0x80;
    }
    if (arg0->unk8A != 1) {
        return -8;
    }
    if (fn_802152E0(arg0->unk0) == 0) {
        arg0->unk8A = 2;
    }
    return fn_8020CAEC();
}