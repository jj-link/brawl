#include <revolution/OS/OSThread.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern void* lbl_805A0208;

void fn_8007E4A8() {
    void* p = lbl_805A0208;
    if (*(int*)p)
        OSResumeThread((OSThread*)((char*)p + 8));
}
}
