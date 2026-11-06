#pragma force_active on
extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSReport(const char*, ...);
void fn_8001B8E0(int, int);
int fn_8020B9BC(char*, void*, int);
void fn_8020BC3C(void*);
void fn_8020D38C(char*);
int strncmp(const char*, const char*, unsigned long);
char* strncpy(char*, const char*, unsigned long);
char* strcat(char*, const char*);
extern char lbl_80494910[0x18];
extern char lbl_8059C57C[5];
extern char lbl_80421508[];
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

extern "C" int fn_8001F390(const char** arg0) {
    Lock lock(lbl_80494910);
    char buf[0x80];
    char sp10[0x80];
    char sp110[0x8C];
    const char* name = *arg0;
    int result = 0x11;

    buf[0] = 0;
    if (strncmp(name, lbl_8059C57C, 4) == 0) {
        strcat(buf, name);
    } else {
        fn_8020D38C(sp10);
        strncpy(buf, sp10, 0x40);
        strcat(buf, name);
    }
    int r = fn_8020B9BC(buf, sp110, 1);
    if (r != 0) {
        if (r != -12) {
            OSReport(lbl_80421508, r);
            fn_8001B8E0(r, 0);
        }
    } else {
        fn_8020BC3C(sp110);
        result = 0;
    }
    Lock* lp = &lock;
    lp->release();
    return result;
}
