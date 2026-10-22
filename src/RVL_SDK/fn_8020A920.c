#pragma force_active on

typedef int s32;

s32 fn_8020CAD4(void);
s32 fn_8020CAEC(void);
void fn_8020CC4C(s32 *, s32);
void fn_802147EC(s32 *);

s32 fn_8020A920(s32 arg0) {
    s32 buf[16];
    s32 i;

    if (fn_8020CAD4() == 0) {
        return -0x80;
    }
    for (i = 0; i < 16; i++) {
        buf[i] = 0;
    }
    fn_8020CC4C(buf, arg0);
    fn_802147EC(buf);
    return fn_8020CAEC();
}
