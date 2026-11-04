#include <revolution/FA.h>
#pragma force_active on

extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSReport(const char*, ...);
int fn_803EBE4C(void);
char* strcpy(char*, const char*);
char* strncat(char*, const char*, unsigned long);
extern char lbl_80494910[0x18];
extern char lbl_8059C598[4];
extern char lbl_8042136C[0x13];
}

struct Lock {
    void* mutex;
    bool locked : 8;
    Lock(void* m, bool l = true) {
        mutex = m;
        locked = l;
        if (locked) OSLockMutex(mutex);
    }
    void release() {
        if (locked) OSUnlockMutex(mutex);
    }
};

extern "C" int fn_8001E630(const char** arg0) {
    Lock lock(lbl_80494910);
    char path[0x80];
    const char* name = *arg0;
    int result = 0x12;
    FAHandle* dir;
    int found;
    strcpy(path, lbl_8059C598);
    if (*name == '/') path[2] = 0;
    strncat(path, name, 0x80);
    found = 0;
    dir = FAOpendir(path);
    if (dir == 0) {
        if (fn_803EBE4C() != 2) {
            fn_803EBE4C();
            OSReport(lbl_8042136C, *arg0);
        }
    } else {
        found = 1;
        result = 0;
    }
    if (found) {
        FAClosedir(dir);
    }
    Lock* lp = &lock;
    lp->release();
    return result;
}
