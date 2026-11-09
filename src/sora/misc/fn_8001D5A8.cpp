#pragma force_active on

extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSReport(const char*, ...);
int fn_803C374C(const char*, const char*, int);
int fn_803C3684(const char*, int);
void fn_803C3828(int);
int fn_803C39BC(int, int, int);
char* strcpy(char*, const char*);
char* strncat(char*, const char*, unsigned long);
extern char lbl_80494910[0x18];
extern char lbl_8059C58C[4];
extern char lbl_8059C5A0[3];
extern char lbl_8059C594[3];
extern const char* lbl_80421198[];
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
    char pad4[4];
    int count;
    int ptr;
    char pad16[5];
    unsigned char drive;
};

extern "C" int fn_8001D5A8(Arg* arg) {
    Lock lock(lbl_80494910);
    char path[0x80];
    unsigned char drive;
    int opened;
    int result;
    const char* name;
    int count;
    int ptr;
    int h;

    name = arg->name;
    count = arg->count;
    opened = 0;
    ptr = arg->ptr;
    result = 1;
    drive = arg->drive;

    strcpy(path, lbl_8059C58C);
    path[0] = drive + 0x42;
    if (*name == '/') path[2] = 0;
    strncat(path, name, 0x80);

    h = fn_803C374C(name, lbl_8059C5A0, 0);
    if (h != 0 || (h = fn_803C3684(name, 0)) != 0) {
        opened = 1;
        unsigned int num = (count + 0x1f) & ~0x1f;
        if (fn_803C39BC(h, ptr, num) == 0) {
            OSReport((const char*)lbl_80421198[4], lbl_8059C594, name, count, ptr);
            arg->count = count;
            result = 0;
            arg->ptr = ptr;
        } else {
            OSReport((const char*)lbl_80421198[7], lbl_8059C594, name);
            result = 3;
        }
    }

    if (opened) {
        fn_803C3828(h);
    } else {
        OSReport((const char*)lbl_80421198[5], lbl_8059C594, name);
    }

    Lock* lp = &lock;
    lp->release();
    return result;
}
