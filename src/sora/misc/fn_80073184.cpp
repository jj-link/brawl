#include <revolution/OS/OSThread.h>
#pragma force_active on

extern "C" void fn_80073184(void* p) {
    OSResumeThread((OSThread*)((char*)*(void**)((char*)p + 0xb94) + 8));
}
