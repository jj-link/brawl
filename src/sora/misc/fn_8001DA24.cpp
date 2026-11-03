#pragma force_active on
extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSReport(const char*, ...);
void fn_8001B8E0(int, int);
int fn_8020AF84(char*, int, int);
void fn_8020D38C(char*);
int strncmp(const char*, const char*, unsigned long);
char* strncpy(char*, const char*, unsigned long);
char* strcat(char*, const char*);
extern char lbl_80494910[0x18];
extern char lbl_8059C57C[5];
extern char lbl_804212D4[];
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
    const char* name;
};

extern "C" int fn_8001DA24(Arg* arg) {
    Lock lock(lbl_80494910);
    char buf[0x80];
    char sp18[0x80];
    const char* name = arg->name;
    int result = 5;

    buf[0] = 0;
    if (strncmp(name, lbl_8059C57C, 4) == 0) {
        strcat(buf, name);
    } else {
        fn_8020D38C(sp18);
        strncpy(buf, sp18, 0x40);
        strcat(buf, name);
    }
    int r = fn_8020AF84(buf, 0x34, 0);
    if (r != 0 && r != -6) {
        fn_8001B8E0(r, 1);
        OSReport(lbl_804212D4, buf);
    } else {
        result = 0;
    }
    Lock* lp = &lock;
    lp->release();
    return result;
}