#include <revolution/OS/OSMessage.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern void* lbl_805A0208;
void fn_8007E944(OSMessage msg);
}

void fn_8007E944(OSMessage msg) {
    OSSendMessage(reinterpret_cast<OSMessageQueue*>(reinterpret_cast<char*>(lbl_805A0208) + 0x1320), msg, 0);
}
