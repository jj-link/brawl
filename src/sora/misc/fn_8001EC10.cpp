#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSError.h>
#include <revolution/FA/FARemove.h>
#include <string.h>
#pragma force_active on

extern "C" {
int fn_8001B7F8(const char*);
void fn_8001B9E8(int);
int fn_8020A870(const char*);
void fn_8020D38C(char*);
int fn_803C3A48(const char*);
void fn_803EBE4C();
extern OSMutex lbl_80494910;
extern char lbl_8059C57C[5];
extern char lbl_8059C58C[4];
extern char lbl_8059C598[4];
extern char lbl_80421490[];
}

struct Flags {
    unsigned r : 8;
    unsigned x : 8;
    unsigned y : 16;
};
struct S {
    const char* p;
    int a, b, c, d;
    Flags flags;
};
struct B {
    unsigned char pad[0x15];
    unsigned char x : 8;
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

extern "C" int fn_8001EC10(S* self) {
    char name[128];
    char tmp[128];
    char nandPath[128];
    char vfPath[128];
    char sdPath[128];
    S local;
    int type = fn_8001B7F8(self->p);
    const char* s = self->p;
    unsigned int n = strlen(s);
    const char* q = s;
    for (unsigned int i = 0; i < n; i++) {
        if (*q == ':') {
            strncpy(name, q + 1, 128);
            goto copied;
        }
        q++;
    }
    strncpy(name, s, 128);
copied:
    local.flags = self->flags;
    const char* path = name;
    int status = 7;
    switch (type) {
    case 2: {
        Lock lock(&lbl_80494910);
        nandPath[0] = 0;
        if (strncmp(path, lbl_8059C57C, 4) == 0) {
            strcat(nandPath, path);
        } else {
            fn_8020D38C(tmp);
            strncpy(nandPath, tmp, 64);
            strcat(nandPath, path);
        }
        type = fn_8020A870(nandPath);
        if (type != 0 && type != -12) {
            OSReport(lbl_80421490, type, nandPath);
            fn_8001B9E8(type);
            status = 7;
        } else {
            status = 0;
        }
        Lock* lp = &lock;
        lp->release();
        break;
    }
    case 4: {
        ((B*)&local)->x = (unsigned char)self->p[2] - '0';
        strcpy(vfPath, lbl_8059C58C);
        vfPath[0] = ((B*)&local)->x + 'B';
        if (path[0] == '/') vfPath[2] = 0;
        strncat(vfPath, path, 128);
        int rv = fn_803C3A48(vfPath);
        if (rv != 0) {
            fn_8001B9E8(rv);
            status = 7;
        } else {
            status = 0;
        }
        break;
    }
    case 3: {
        status = 7;
        strcpy(sdPath, lbl_8059C598);
        if (path[0] == '/') sdPath[2] = 0;
        strncat(sdPath, path, 128);
        if (FARemove(sdPath) != 0) {
            fn_803EBE4C();
        } else {
            status = 0;
        }
        break;
    }
    }
    self->flags.r = status;
    return status;
}
