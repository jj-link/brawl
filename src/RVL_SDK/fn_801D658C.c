#include <revolution/OS/OSError.h>
#pragma force_active on

extern int lbl_8059E994;

void OSRegisterVersion(unsigned int arg0) {
    OSReport((const char*)&lbl_8059E994, arg0);
}
