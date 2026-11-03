#include <types.h>
#include <revolution/SO/SOBasic.h>
#pragma force_active on

extern void fn_8038D0A8(void *arg0, unsigned int arg1, unsigned short arg2, unsigned int arg3);
extern unsigned int fn_8035C620(int arg);

void fn_803897C8(void *arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3) {
    unsigned int v;
    v = SOHtoNs(arg2);
    fn_8038D0A8((char *)arg0 + 0x4c, fn_8035C620(arg1), (unsigned short)v, arg3);
}