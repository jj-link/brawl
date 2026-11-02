#pragma force_active on
#include <gf/gf_memory_pool.h>

extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSReport(const char*, ...);
void fn_8001B8E0(int, int);
int fn_8020AD88(char*, int, int*);
void fn_8020D38C(char*);
int strncmp(const char*, const char*, unsigned long);
char* strncpy(char*, const char*, unsigned long);
char* strcat(char*, const char*);
extern char lbl_80494910[0x18];
extern char lbl_8059C57C[5];
extern char lbl_8059C584[5];
extern char lbl_80421314[];
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
    char pad[0xC];
    gfMemoryPool* pool;
};

extern "C" int fn_8001DF68(Arg* arg) {
    Lock lock(lbl_80494910);
    char buf[0x80];
    char sp18[0x80];
    int sp8;
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
    int r = fn_8020AD88(buf, 0, &sp8);
    if (r != 0) {
        fn_8001B8E0(r, 0);
        OSReport(lbl_80421314, buf);
    } else {
        u32 size = (sp8 * 0xD + 0x1F) & ~0x1F;
        if (size != 0) {
            void* p = gfMemoryPool::alloc(arg->pool, size, 0x20);
            if (p == 0) {
                OSReport((const char*)lbl_80421198[2], lbl_8059C584, name, size);
                result = 4;
            } else {
                int r2 = fn_8020AD88(buf, (int)p, &sp8);
                if (r2 != 0) {
                    fn_8001B8E0(r2, 0);
                    OSReport(lbl_80421314, buf);
                } else {
                    result = 0;
                }
            }
        }
    }
    Lock* lp = &lock;
    lp->release();
    return result;
}
