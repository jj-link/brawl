#include <revolution/OS/OSMutex.h>
#pragma force_active on

class Class_80466C38 {
public:
    virtual void fn_801CD370();
    virtual void fn_801CD6B8();
    virtual void fn_801CD9C4();
};

extern "C" {
char* fn_801CC2E4();
void fn_801C093C(void*, void*, int);
void fn_801CDB9C(void*);
}

extern "C" int fn_801CD478(char* p, int arg) {
    OSLockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
    if (*(unsigned char*)(p + 0xb8) != 0) {
        OSLockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
        ((Class_80466C38*)p)->fn_801CD9C4();
        if (*(unsigned char*)(p + 0xb8) == 0) {
            OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
        } else {
            *(int*)(p + 0x7b8) = 0;
            fn_801C093C(p + 0x134, p + 0x138, 0x680);
            *(unsigned char*)(p + 0xb8) = 0;
            OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
        }
    }
    fn_801CDB9C(p);
    *(int*)(p + 0x7b8) = arg;
    *(unsigned char*)(p + 0xb8) = 1;
    OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
    return 1;
}
