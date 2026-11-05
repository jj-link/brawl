#include <revolution/OS/OSThread.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern char lbl_804602D0[];

extern "C" void fn_801498B0(void* arg0) {
    unsigned char* self = static_cast<unsigned char*>(arg0);
    if (self[0x11] == 0) {
        self[0x33CD] = 1;
    } else if (self[0x33CC] == 0) {
        self[0x33CC] = 1;
        OSResumeThread(reinterpret_cast<OSThread*>(self + 0xA0));
        netReport(lbl_804602D0);
    }
}
