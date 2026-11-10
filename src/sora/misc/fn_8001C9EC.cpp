#pragma force_active on
#include <types.h>
#include <gf/gf_memory_pool.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_error_check.h>
#include <gm/gm_global.h>

extern "C" {
void OSReport(const char*, ...);
char* strcpy(char*, const char*);
char* strncat(char*, const char*, unsigned long);
int fn_803C374C(const char*, const char*, int);
int fn_803C3CB8(int);
void fn_803C3828(int);
void fn_803C3920(int, void*, int, unsigned int*);
extern OSMutex lbl_80494910;
extern char lbl_8059C58C[4];
extern char lbl_8059C590[2];
extern char lbl_8059C594[3];
extern const char* lbl_80421198[10];
}

struct Arg {
    const char* path;
    unsigned char pad4[4];
    int size;
    void* data;
    void* pool;
    unsigned char pad14;
    unsigned char drive;
};

struct Lock {
    OSMutex* mutex;
    bool locked : 8;
    Lock(OSMutex* m, bool l = true) {
        mutex = m;
        locked = l;
        if (locked) OSLockMutex(mutex);
    }
    void release() {
        if (locked) OSUnlockMutex(mutex);
    }
};

extern "C" int fn_8001C9EC(Arg* arg) {
    Lock lock(&lbl_80494910);
    char path[0x80];
    void* p;
    unsigned char drive;
    int result;
    int found;
    const char* name;
    void* pool;
    int sz;
    int h;
    unsigned int outSize;

    name = arg->path;
    pool = arg->pool;
    drive = arg->drive;
    result = 1;
    found = 0;

    strcpy(path, lbl_8059C58C);
    path[0] = drive + 0x42;
    if (*name == '/') path[2] = 0;
    strncat(path, name, 0x80);
    h = fn_803C374C(name, lbl_8059C590, 0);
    if (h != 0) {
        found = 1;
        sz = fn_803C3CB8(h);
        if (sz > 0) {
            unsigned long aligned = (sz + 0x1F) & ~0x1F;
            if (aligned != 0) {
                p = gfMemoryPool::alloc(pool, aligned, 0x20);
                if (p == 0) {
                    OSReport(lbl_80421198[2], lbl_8059C594, name, sz);
                    result = 4;
                } else {
                    fn_803C3920(h, p, sz, &outSize);
                    if (outSize >= (unsigned int)sz) {
                        int frame;
                        if (g_GameGlobal != 0) {
                            frame = (int)g_GameGlobal->getGameFrame();
                        } else {
                            frame = 0;
                        }
                        OSReport(lbl_80421198[0], lbl_8059C594, name, outSize, p, frame);
                        arg->size = sz;
                        result = 0;
                        arg->data = p;
                    } else {
                        OSReport(lbl_80421198[3], lbl_8059C594, name);
                        gfHeapManager::free(p);
                        result = 2;
                        gfErrorCheck::check();
                    }
                }
            }
        }
    }
    if (found) {
        fn_803C3828(h);
    } else {
        OSReport(lbl_80421198[1], lbl_8059C594, name);
    }
    Lock* lp = &lock;
    lp->release();
    return result;
}