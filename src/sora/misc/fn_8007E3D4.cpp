#include <revolution/OS/OSMessage.h>
#include <revolution/OS/OSThread.h>
#pragma force_active on

extern "C" void* fn_8007E504(void*);
extern "C" void* fn_8007E5D0(void*);
extern char* lbl_805A0208;

extern "C" int fn_8007E3D4(int prio, void* arg) {
    if (arg) {
        if (!OSCreateThread((OSThread*)(lbl_805A0208 + 8), fn_8007E5D0, arg,
                            lbl_805A0208 + 0x1320, 0x1000, prio, 1))
            return 0;
    } else {
        if (!OSCreateThread((OSThread*)(lbl_805A0208 + 8), fn_8007E504, 0,
                            lbl_805A0208 + 0x1320, 0x1000, prio, 1))
            return 0;
    }
    OSInitMessageQueue((OSMessageQueue*)(lbl_805A0208 + 0x1320),
                       (OSMessage*)(lbl_805A0208 + 0x1360), 3);
    OSInitMessageQueue((OSMessageQueue*)(lbl_805A0208 + 0x1340),
                       (OSMessage*)(lbl_805A0208 + 0x136c), 3);
    *(int*)(lbl_805A0208 + 0) = 1;
    *(int*)(lbl_805A0208 + 0x1378) = 1;
    return 1;
}