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
extern char lbl_8059E7F8[2];
extern OSMutex lbl_8049ED08;
void fn_80358960();
}
extern "C" int fn_80151CDC(Self* self) {
    char* base = lbl_80461390;
    OSReport(lbl_8059E7F8);
    OSReport(base + 0x78);
    if (self->flag48 == 0) {
        OSReport(base + 0x90);
        return 1;
    }
    int busy = 0;
    if (self->state40 == 1 || self->state44 != 0)
        busy = 1;
    if (busy != 0) {
        OSReport(base + 0xa8);
        return 0;
    }
    OSReport(base + 0xc4);
    Guard guard;
    Guard* p = &guard;
    p->flag = 1;
    p->mutex = &lbl_8049ED08;
    if (p->flag != 0)
        OSLockMutex(p->mutex);
    self->flag49 = 0;
    fn_80358960();
    if (p->flag != 0)
        OSUnlockMutex(p->mutex);
    OSReport(base + 0xe8);
    OSReport(lbl_8059E7F8);
    int busy2 = 0;
    if (self->state40 == 1 || self->state44 != 0)
        busy2 = 1;
    if (busy2 != 0)
        return 0;
    self->state44 = 3;
    self->state40 = 1;
    return 1;
}