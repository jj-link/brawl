#pragma force_active on
extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSReport(const char*, ...);
void fn_8001B9E8();
int fn_8001BD04(const char*);
char* strcpy(char*, const char*);
char* strncat(char*, const char*, unsigned long);
extern char lbl_80494910[0x18];
extern char lbl_8059C58C[4];
extern char lbl_804212EC[0x14];
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
extern "C" int fn_8001DB34(Arg* arg) {
    Lock lock(lbl_80494910);
    char path[0x80];
    unsigned char drive;
    int result;
    const char* name = arg->path;
    drive = arg->drive;
    result = 5;
    strcpy(path, lbl_8059C58C);
    path[0] = drive + 0x42;
    if (*name == '/') path[2] = 0;
    strncat(path, name, 0x80);
    int status = fn_8001BD04(path);
    if (status != 0 && status != 0x11) {
        fn_8001B9E8();
        OSReport(lbl_804212EC, path);
    } else {
        result = 0;
    }
    Lock* lp = &lock;
    lp->release();
    return result;
}
