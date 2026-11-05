#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern "C" char* fn_801CC2E4();

class Class_80466A60 {
public:
    virtual void fn_801C49AC();
    virtual int fn_801C46C4(int);

    char pad04[1];
    unsigned char flag05;
    char pad06[0x4e];
    int field54;
    int field58;
    char pad5c[2];
    unsigned char flag5e;
    char pad5f[0x5d];
    int fieldbc;
};

extern "C" int fn_801C4FA4(Class_80466A60* self, int arg) {
    OSLockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
    if (self->flag05 == 0) {
        OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
        return 0;
    }
    if (self->flag5e != 0) {
        if (self->fieldbc != 0) {
            OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
            return 1;
        }
        self->flag5e = 0;
    }
    if (self->field58 > 0) {
        if (--self->field58 > 0) {
            OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
            return 1;
        }
    }
    if (self->field54 != 0) {
        while (self->field58 == 0 && self->flag5e == 0) {
            if (self->fn_801C46C4(arg) == 1) {
                OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
                return -1;
            }
        }
    }
    OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
    return 1;
}