#include <revolution/OS/OSMutex.h>
#include <string.h>
#pragma force_active on

extern "C" {
extern OSMutex lbl_8049ECA0;
void fn_803512CC(int);
}

struct Self {
    char* data;
    char pad[4];
    unsigned char flag;
};

extern "C" int fn_8014CB7C(Self* self) {
    OSLockMutex(&lbl_8049ECA0);
    OSLockMutex(&lbl_8049ECA0);
    memset(self->data, 0, 0x2804);
    self->flag = 1;
    OSUnlockMutex(&lbl_8049ECA0);
    fn_803512CC((int)(self->data + 0x10));
    OSUnlockMutex(&lbl_8049ECA0);
    return 1;
}