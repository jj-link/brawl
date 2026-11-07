#include <types.h>
#include <stdio.h>
#pragma force_active on
extern char lbl_8059FB90[3];
extern s32 fn_8038A1B0(s32, const u8 *);
extern void fn_8035B078(void *, s32 *);
void fn_803886C8(void *arg0, const u8 *arg1) {
    char buf[16];
    s32 pair[2];
    sprintf(buf, lbl_8059FB90);
    pair[0] = fn_8038A1B0(0, arg1);
    pair[1] = fn_8038A1B0(0, (const u8 *)buf);
    fn_8035B078(*(void **)((char *)arg0 + 0x18), pair);
}