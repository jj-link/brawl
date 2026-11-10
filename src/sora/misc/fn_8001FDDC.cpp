#include <revolution/OS/OSMutex.h>
#include <string.h>

#pragma force_active on

extern "C" {
int fn_8001B7F8(const char*);
int fn_8001FAD8(const char*);
int fn_8001F7C4(const char*);
extern OSMutex lbl_80494910;
extern char lbl_8059C58C[4];
extern char lbl_8059C598[4];
}

struct Flags {
    unsigned int res : 8;
    unsigned int drive : 8;
    unsigned int rest : 16;
};

struct Arg {
    const char* path;
    int pad4;
    int r8;
    int rC;
    int pad10;
    Flags flags;
};

struct Drive {
    unsigned char pad[0x15];
    unsigned char value : 8;
};

struct Lock {
    OSMutex* mutex;
    bool locked : 8;

    Lock(OSMutex* m, bool l = true) {
        mutex = m;
        locked = l;
        if (locked)
            OSLockMutex(mutex);
    }

    void release() {
        if (locked)
            OSUnlockMutex(mutex);
    }
};

extern "C" int fn_8001FDDC(Arg* arg) {
    char name[0x80];
    char path[0x80];
    Arg local;

    int type = fn_8001B7F8(arg->path);
    const char* p = arg->path;
    unsigned int len = strlen(p);
    const char* q = p;

    for (unsigned int i = 0; i < len; i++, q++) {
        if (*q == ':') {
            strncpy(name, q + 1, 0x80);
            goto done;
        }
    }
    strncpy(name, p, 0x80);

done:
    local.flags = arg->flags;
    char* n = name;
    int result = 0x11;
    int r = 0;

    switch (type) {
    case 3: {
        Lock lock(&lbl_80494910);
        strcpy(path, lbl_8059C598);
        if (n[0] == '/')
            path[2] = 0;
        strncat(path, n, 0x80);
        r = fn_8001FAD8(path);
        Lock* lp = &lock;
        lp->release();
        break;
    }
    case 4: {
        ((Drive*)&local)->value = arg->path[2] - '0';
        Lock lock(&lbl_80494910);
        strcpy(path, lbl_8059C58C);
        path[0] = ((Drive*)&local)->value + 'B';
        if (n[0] == '/')
            path[2] = 0;
        strncat(path, n, 0x80);
        r = fn_8001F7C4(path);
        Lock* lp = &lock;
        lp->release();
        break;
    }
    }

    if (r >= 0)
        result = 0;
    if (r < 0)
        r = 0;

    arg->r8 = r;
    arg->rC = 0;
    arg->flags.res = result;
    return result;
}
