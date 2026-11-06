#include <types.h>
#include <revolution/SO/SOBasic.h>
#pragma force_active on

extern int fn_8038CFA4(void *self, unsigned int a, unsigned short b, const void *data, int length);
extern unsigned int fn_8035C620(int arg);

void fn_80389760(void *arg0, unsigned int arg1, unsigned int arg2, const void *arg3, int arg4) {
    unsigned int v;
    v = SOHtoNs(arg2);
    fn_8038CFA4((char *)arg0 + 0x4c, fn_8035C620(arg1), (unsigned short)v, arg3, arg4);
}
