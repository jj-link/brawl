#pragma force_active on
#include <types.h>
#include <revolution/FA.h>
#include <gf/gf_memory_pool.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_error_check.h>
#include <gm/gm_global.h>

extern "C" {
void OSReport(const char*, ...);
char* strcpy(char*, const char*);
char* strncat(char*, const char*, unsigned long);
int fn_803EBE4C();
extern OSMutex lbl_80494910;
extern char lbl_8059C598[4];
extern char lbl_8059C590[2];
extern char lbl_8059C59C[3];
extern const char* lbl_80421198[];
}
struct Lock {
    OSMutex* mutex;
    bool locked : 8;
    Lock(OSMutex* m, bool l = true) {
        mutex = m;
        locked = l;
        if (locked) OSLockMutex(mutex);
    }
    void release() { if (locked) OSUnlockMutex(mutex); }
};
struct Arg {
    char* m_name;
    int m_offset;
    int m_readLen;
    void* m_dest;
    void* m_heap;
};
extern "C" int readSDFile__8gfFileIOFP15gfFileIORequest(Arg* arg) {
    Lock lock(&lbl_80494910);
    char path[0x80];
    FAStat stat;
    const char* name;
    int filesize;
    void* pool;
    pool = arg->m_heap;
    name = arg->m_name;
    int opened = 0;
    int seek = arg->m_offset;
    int result = 1;
    strcpy(path, lbl_8059C598);
    if (*name == '/') path[2] = 0;
    strncat(path, name, 0x80);
    FAHandle* handle = FAFopen(path, lbl_8059C590);
    if (handle != 0) {
        opened = 1;
        if (FAFstat(path, &stat) != 0) {
            fn_803EBE4C();
            result = 1;
        } else if ((filesize = stat.filesize) == 0) {
            result = 1;
        } else if (seek != 0 && FAFseek(handle, seek, 0) != 0) {
            fn_803EBE4C();
            result = 1;
        } else {
            unsigned long size = (filesize + 0x1f) & ~0x1f;
            if (size != 0) {
                void* p = gfMemoryPool::alloc(pool, size, 0x20);
                if (p == 0) {
                    OSReport(lbl_80421198[2], lbl_8059C59C, name, size);
                    result = 4;
                } else {
                    unsigned int read = FAFread(p, 1, filesize, handle);
                    if (read >= (unsigned int)filesize) {
                        int frame;
                        if (g_GameGlobal != 0) frame = (int)g_GameGlobal->getGameFrame();
                        else frame = 0;
                        OSReport(lbl_80421198[0], lbl_8059C59C, name, read, p, frame);
                        arg->m_readLen = filesize;
                        result = 0;
                        arg->m_dest = p;
                    } else {
                        OSReport(lbl_80421198[3], lbl_8059C59C, name);
                        gfHeapManager::free(p);
                        result = 2;
                        gfErrorCheck::check();
                    }
                }
            }
        }
    }
    if (opened) FAFclose(handle);
    else OSReport(lbl_80421198[1], lbl_8059C59C, name);
    Lock* lp = &lock;
    lp->release();
    return result;
}