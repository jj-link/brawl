#pragma force_active on
extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void fn_8001B9E8();
int fn_803C3CF8(char*);
int fn_803C3F44(void);
char* strcpy(char*, const char*);
char* strncat(char*, const char*, unsigned long);
extern char lbl_80494910[0x18];
extern char lbl_8059C58C[4];
}

struct Lock {
    void* mutex;
    bool locked : 8;
    Lock(void* m) {
        mutex = m;
        locked = true;
        if (locked) OSLockMutex(mutex);
    }
    void release() {
        if (locked) OSUnlockMutex(mutex);
    }
};

struct Arg {
    const char* path;
    int unk4;
    int unk8;
    char pad[9];
    unsigned char drive;
};

extern "C" int fn_8001F4B0(Arg* arg) {
    Lock lock(lbl_80494910);
    char sp10[0x80];
    unsigned char drive = arg->drive;
    const char* path = arg->path;
    int result = 0x11;

    strcpy(sp10, lbl_8059C58C);
    sp10[0] = drive + 0x42;
    if (*path == '/') sp10[2] = 0;
    strncat(sp10, path, 0x80);

    int r = fn_803C3CF8(sp10);
    if (r < 0) {
        if (fn_803C3F44() != 2) {
            fn_8001B9E8();
        }
    } else {
        arg->unk8 = r;
        result = 0;
    }
    Lock* lp = &lock;
    lp->release();
    return result;
}