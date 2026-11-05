#pragma force_active on
#include <revolution/FA.h>

extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void OSReport(const char*, ...);
char* strcpy(char*, const char*);
char* strncat(char*, const char*, unsigned long);

extern char lbl_80494910[0x18];
extern char lbl_8059C598[4];
extern char lbl_8059C59C[4];
extern char lbl_8059C5A0[3];
extern char lbl_8059C5A4[3];
extern void* lbl_80421198[];
}

struct Lock {
    void* mutex;
    bool locked : 8;

    Lock(void* m, bool l = true) {
        mutex = m;
        locked = l;
        if (locked) {
            OSLockMutex(mutex);
        }
    }

    void release() {
        if (locked) {
            OSUnlockMutex(mutex);
        }
    }
};

struct FileWriteArgs {
    const char* name;
    int offset;
    int size;
    void* data;
};

extern "C" int fn_8001D740(FileWriteArgs* arg) {
    Lock lock(lbl_80494910);
    char path[0x80];
    int opened;
    int result;
    const char* name = arg->name;
    int size = arg->size;
    opened = 0;
    int offset = arg->offset;
    result = 1;
    void* data = arg->data;

    strcpy(path, lbl_8059C598);
    if (*name == '/') {
        path[2] = 0;
    }
    strncat(path, name, 0x80);

    FAHandle* handle;
    if (offset != 0) {
        handle = FAFopen(path, lbl_8059C5A4);
    } else {
        handle = FAFopen(path, lbl_8059C5A0);
    }

    if (handle != 0) {
        unsigned int num = (size + 0x1f) & ~0x1f;
        opened = 1;
        if (offset != 0) {
            FAFseek(handle, offset, 0);
        }

        unsigned int written = FAFwrite(data, 1, num, handle);
        if (written == num) {
            OSReport((const char*)lbl_80421198[4], lbl_8059C59C, name, size, data);
            arg->size = size;
            result = 0;
            arg->data = data;
        } else {
            OSReport((const char*)lbl_80421198[7], lbl_8059C59C, name);
            result = 3;
        }
    }

    if (opened) {
        FAFclose(handle);
    } else {
        OSReport((const char*)lbl_80421198[5], lbl_8059C59C, name);
    }

    Lock* lp = &lock;
    lp->release();
    return result;
}