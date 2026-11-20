#include <types.h>
#pragma force_active on

typedef struct {
    u32 a, b, c, d, e, f;
} Data;

extern void fn_802319E4(s32, const char *);
extern u8 lbl_804814C8[];
extern u8 lbl_80529CF8[];

s32 fn_8023F38C(Data *arg0) {
    u8 *base = lbl_80529CF8;
    *(Data *)(base + 0x190C) = *arg0;
    if (base[0x27C0] >= 4)
        fn_802319E4(0xD0003, (const char *)lbl_804814C8);
    return 1;
}
