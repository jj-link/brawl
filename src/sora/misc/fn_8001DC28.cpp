#pragma force_active on
extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSReport(const char*, ...);
int fn_803EBE4C(void);
char* strcpy(char*, const char*);
char* strncat(char*, const char*, unsigned long);
int gfFACreateDir__8gfFileIOFPCc(const char* filepath);
extern char lbl_80494910[0x18];
extern char lbl_8059C598[4];
extern char lbl_80421300[];
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

extern "C" int fn_8001DC28(const char** arg0) {
    Lock lock(lbl_80494910);
    char path[0x80];
    const char* name = *arg0;
    int result = 5;
    strcpy(path, lbl_8059C598);
    if (*name == '/') path[2] = 0;
    strncat(path, name, 0x80);
    int status = gfFACreateDir__8gfFileIOFPCc(path);
    if (status != 0 && fn_803EBE4C() != 0x11) {
        fn_803EBE4C();
        OSReport(lbl_80421300, path);
    } else {
        result = 0;
    }
    Lock* lp = &lock;
    lp->release();
    return result;
}