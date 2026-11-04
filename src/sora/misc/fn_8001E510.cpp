#pragma force_active on
extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSReport(const char*, ...);
void fn_8001B9E8();
int fn_803C3BE8(char*);
char* strcpy(char*, const char*);
char* strncat(char*, const char*, unsigned long);
extern char lbl_80494910[0x18];
extern char lbl_8059C58C[4];
extern char lbl_8059C5B0[4];
extern char lbl_80421358[];
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

struct Arg {
    const char* path;
    char pad[0x11];
    unsigned char drive;
};

extern "C" int fn_8001E510(Arg* arg) {
    Lock lock(lbl_80494910);
    char sp90[0x80];
    char sp10[0x80];
    unsigned char drive = arg->drive;
    const char* path = arg->path;
    int result = 0x12;

    strcpy(sp90, lbl_8059C58C);
    sp90[0] = drive + 0x42;
    if (*path == '/') sp90[2] = 0;
    strncat(sp90, path, 0x80);

    strcpy(sp10, lbl_8059C5B0);
    sp10[0] += arg->drive;

    int r = fn_803C3BE8(sp90);
    if (r != 0) {
        if (r != 2) {
            fn_8001B9E8();
            OSReport(lbl_80421358, arg->path);
        }
    } else {
        fn_803C3BE8(sp10);
        result = 0;
    }

    Lock* lp = &lock;
    lp->release();
    return result;
}
