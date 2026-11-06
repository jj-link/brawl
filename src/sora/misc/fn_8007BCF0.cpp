#include <mv/mv_THPPlayer.h>
#include <revolution/OS/OSMessage.h>
#include <string.h>
#pragma force_active on

extern "C" void fn_801D78F0();
extern "C" int fn_8025F46C();
extern int* lbl_805A01F8;

extern "C" int fn_8007BCF0() {
    memset(&g_thpObject, 0, 0x1B0);
    fn_801D78F0();
    OSInitMessageQueue((OSMessageQueue*)((char*)lbl_805A01F8 + 0x7C0),
                       (OSMessage*)((char*)lbl_805A01F8 + 0x7E8), 3);
    if (fn_8025F46C() == 0)
        return 0;
    *lbl_805A01F8 = 1;
    return 1;
}