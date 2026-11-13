#pragma force_active on
extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
int fn_8001D134(void*);
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
unsigned long strlen(const char*);
extern char lbl_80494910[0x18];
extern char lbl_8059C570[6];
}

struct S {
    const char* p;
    int a, b, c, d;
    unsigned r : 8;
    unsigned x : 8;
    unsigned y : 16;
};

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

extern "C" int fn_8001CFA4(S* arg) {
    Lock lock(lbl_80494910);
    S local;
    char buf2[0x80];
    char buf1[0x80];

    local = *arg;

    const char* s = arg->p;
    const char* p = &s[strlen(s) - 1];
    do {
        if (*(p - 1) == '/') break;
        p--;
    } while (p != s);
    strcpy(buf2, p);

    strcpy(buf1, lbl_8059C570);
    strcat(buf1, buf2);
    local.p = buf1;

    int result = fn_8001D134(&local);
    if (result == 0) {
        arg->c = local.c;
        arg->b = local.b;
        arg->r = result;
    }

    Lock* lp = &lock;
    lp->release();
    return result;
}
