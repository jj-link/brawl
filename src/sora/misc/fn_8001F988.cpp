#pragma force_active on
#include <gf/gf_memory_pool.h>

extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSReport(const char*, ...);
int fn_8001F7C4(const char*);
void fn_8001F84C(char*, void*, u32, int);
char* strcpy(char*, const char*);
char* strncat(char*, const char*, unsigned long);
extern char lbl_80494910[0x18];
extern char lbl_8059C58C[4];
extern char lbl_8059C594[3];
extern void* lbl_80421198[];
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
    void* ptr;
    gfMemoryPool* pool;
    char pad14;
    unsigned char drive;
};

extern "C" int fn_8001F988(Arg* arg) {
    Lock lock(lbl_80494910);
    char buf[0x80];
    unsigned char drive = arg->drive;
    const char* name = arg->name;
    int result = 0x11;
    int count;
    void* p;
    strcpy(buf, lbl_8059C58C);
    buf[0] = drive + 0x42;
    if (*name == '/') buf[2] = 0;
    strncat(buf, name, 0x80);
    count = fn_8001F7C4(buf);
    if (count >= 0) {
        if (count == 0) {
            result = 0;
        } else {
            u32 size = count << 7;
            p = gfMemoryPool::alloc(arg->pool, size, 0x20);
            if (p == 0) {
                OSReport((const char*)lbl_80421198[2], lbl_8059C594, arg->name, size);
                result = 4;
            } else {
                arg->ptr = p;
                fn_8001F84C(buf, p, size, 0x80);
                arg->ptr = p;
                result = 0;
                arg->count = count;
            }
        }
    }
    Lock* lp = &lock;
    lp->release();
    return result;
}
