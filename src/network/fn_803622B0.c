#include <types.h>
#pragma force_active on

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
    s32 unk18;
    u8 pad1[0x10];
    s32 unk2C;
    s32 unk30;
} Obj;

s32 fn_80362C98(void);
s32 fn_80362D50(s32, s32, s32);

s32 fn_803622B0(s32 a0, s32 a1, s32 a2, s32 a3, Obj* obj) {
    s32 r;

    obj->unk2C = a1;
    obj->unk30 = 1;
    obj->unk18 = a2;
    if (a1 == 0) {
        r = fn_80362C98();
        obj->unk14 = r;
        if (r == 0) {
            obj->unk2C = 1;
        } else if (fn_80362D50(r, a2, a3) == 0) {
            obj->unk2C = 7;
        }
    }
    return 0;
}
