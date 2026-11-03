#include <types.h>
#pragma force_active on

extern s32 fn_8038A1B0(s32, const u8 *);
extern void fn_8035B078(void *, s32 *);

void fn_8038866C(void *arg0, const u8 *arg1, const u8 *arg2) {
    s32 pair[2];
    pair[0] = fn_8038A1B0(0, arg1);
    pair[1] = fn_8038A1B0(0, arg2);
    fn_8035B078(*(void **)((char *)arg0 + 0x18), pair);
}
