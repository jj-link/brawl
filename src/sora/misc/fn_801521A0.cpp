#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSError.h>
#pragma force_active on
struct Self {
    unsigned char pad[0x40];
    int state40;
    int state44;
    unsigned char flag48;
    unsigned char flag49;
};
struct Guard {
    OSMutex* mutex;
    unsigned char flag : 8;
};
extern "C" {
extern char lbl_80461390[];
extern OSMutex lbl_8049ED08;
void fn_80358C54();
}
extern "C" void fn_801521A0(Self* self) {
    char* base = lbl_80461390;
    OSReport(base + 0xf8);
    if (self->flag48 == 1 && self->flag49 == 1) {
        int busy = 0;
        if (self->state40 == 1 || self->state44 != 0)
            busy = 1;
        if (busy != 0) {
            Guard guard;
            Guard* p = &guard;
            p->flag = 1;
            p->mutex = &lbl_8049ED08;
            if (p->flag != 0)
                OSLockMutex(p->mutex);
            OSReport(base + 0x108);
            fn_80358C54();
            if (p->flag != 0)
                OSUnlockMutex(p->mutex);
            return;
        }
    }
    OSReport(base + 0x120);
}