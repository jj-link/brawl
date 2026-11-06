#pragma force_active on
#include <gf/gf_memory_pool.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_error_check.h>
#include <gm/gm_global.h>
#include <revolution/NAND/nand.h>
#include <revolution/OS/OSTime.h>

extern "C" {
void OSReport(const char*, ...);
void fn_8001B8E0(int, int);
int fn_8020B9BC(const char*, NANDFileInfo*, int);
int fn_8020B0E4(NANDFileInfo*, u32*);
int fn_8020AC38(NANDFileInfo*, int, int);
int fn_8020AA78(NANDFileInfo*, void*, u32);
int fn_8020BC3C(NANDFileInfo*);
void fn_8020D38C(char*);
int strncmp(const char*, const char*, unsigned long);
char* strncpy(char*, const char*, unsigned long);
char* strcat(char*, const char*);
extern OSMutex lbl_80494910;
extern char lbl_8059C57C[5];
extern char lbl_8059C584[5];
extern char lbl_80421278[];
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
    void release() {
        if (locked) OSUnlockMutex(mutex);
    }
};

inline int retryNAND(int status) {
    int retry = 0;
    if ((u32)(status + 3) <= 1) {
        OSSleepTicks((s64)((OS_BUS_CLOCK_SPEED / 4) / 1000) * 16);
        retry = 1;
    } else if (status != -12) {
        fn_8001B8E0(status, 0);
    }
    return retry;
}

extern "C" int fn_8001C5D4(gfFileIORequest* arg) {
    Lock lock(&lbl_80494910);
    NANDFileInfo handle;
    char path[0x80];
    char temp[0x80];
    u32 length;
    int result;
    const char* name = arg->m_pFilepath;
    void* data;
    int status;
    int opened = 0;
    int offset = arg->m_offset;
    result = 1;
    void* pool = (void*)arg->m_heap;
    path[0] = 0;
    if (strncmp(name, lbl_8059C57C, 4) == 0) {
        strcat(path, name);
    } else {
        fn_8020D38C(temp);
        strncpy(path, temp, 0x40);
        strcat(path, name);
    }
    do {
        status = fn_8020B9BC(path, &handle, 1);
    } while (retryNAND(status));
    if (status == 0) {
        opened = 1;
        do {
            status = fn_8020B0E4(&handle, &length);
        } while (retryNAND(status));
        if (status == 0) {
            if (arg->m_readLen != 0) length = arg->m_readLen;
            u32 size = (length + 31) & ~31;
            if (size != 0) {
                data = arg->m_dest;
                if (data == 0) {
                    data = gfMemoryPool::alloc(pool, size, 32);
                    if (data == 0) {
                        OSReport(lbl_80421198[2], lbl_8059C584, name, length);
                    }
                }
                if (offset != 0) {
                    if (fn_8020AC38(&handle, offset, 0) < 0) {
                        fn_8001B8E0(status, 0);
                        OSReport(lbl_80421278, offset, name);
                    }
                }
                do {
                    result = fn_8020AA78(&handle, data, size);
                } while (retryNAND(result));
                if ((u32)result >= length) {
                    OSReport(lbl_80421198[0], lbl_8059C584, name, result, data,
                             g_GameGlobal ? (int)g_GameGlobal->getGameFrame() : 0);
                    result = 0;
                    arg->m_readLen = length;
                    arg->m_dest = data;
                } else {
                    OSReport(lbl_80421198[3], lbl_8059C584, name);
                    gfHeapManager::free(data);
                    result = 2;
                    gfErrorCheck::check();
                }
            }
        }
    }
    if (status != 0 && status != -12) fn_8001B8E0(status, 0);
    if (opened) {
        int r;
        do {
            r = fn_8020BC3C(&handle);
        } while (retryNAND(r));
    } else {
        OSReport(lbl_80421198[1], lbl_8059C584, name);
    }
    Lock* lp = &lock;
    lp->release();
    return result;
}
