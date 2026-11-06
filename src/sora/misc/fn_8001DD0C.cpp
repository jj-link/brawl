#include <revolution/OS/OSMutex.h>
#include <string.h>
#pragma force_active on
extern "C" {
int fn_8001B7F8(const char*);
extern OSMutex lbl_80494910;
extern char lbl_8059C58C[4];
extern char lbl_8059C598[4];
extern char lbl_8059C5A8[5];
}
struct S {
    const char* p;
    int a, b, c, d;
    unsigned r : 8;
    unsigned x : 8;
    unsigned y : 16;
};
struct B { unsigned char pad[0x15]; unsigned char x : 8; };
extern "C" int fn_8001DF68(S*);
extern "C" int fn_8001E10C(char*, S*);
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
extern "C" void fn_8001DD0C(S* self) {
    char buf[128];
    char sdPath[128];
    char vfPath[128];
    int t = fn_8001B7F8(self->p);
    const char* s = self->p;
    unsigned int n = strlen(s);
    const char* q = s;
    for (unsigned int i = 0; i < n; i++) {
        if (*q == ':') {
            strncpy(buf, q + 1, 128);
            goto done;
        }
        q++;
    }
    strncpy(buf, s, 128);
done:
    S l;
    ((int*)&l)[0] = ((int*)self)[0];
    ((int*)&l)[1] = ((int*)self)[1];
    ((int*)&l)[2] = ((int*)self)[2];
    ((int*)&l)[3] = ((int*)self)[3];
    ((int*)&l)[4] = ((int*)self)[4];
    ((int*)&l)[5] = ((int*)self)[5];
    l.p = buf;
    int r = 5;
    switch (t) {
    case 1: break;
    case 2: r = fn_8001DF68(&l); break;
    case 3: {
        Lock lock(&lbl_80494910);
        const char* path = l.p;
        strcpy(sdPath, lbl_8059C598);
        if (path[0] == '/') sdPath[2] = 0;
        strncat(sdPath, path, 128);
        strncat(sdPath, lbl_8059C5A8, 128);
        int result = fn_8001E10C(sdPath, &l);
        Lock* lp = &lock;
        lp->release();
        r = result;
        break;
    }
    case 4: {
        ((B*)&l)->x = ((const unsigned char*)self->p)[2] - '0';
        Lock lock(&lbl_80494910);
        unsigned char drive = ((B*)&l)->x;
        const char* path = l.p;
        strcpy(vfPath, lbl_8059C58C);
        vfPath[0] = drive + 'B';
        if (path[0] == '/') vfPath[2] = 0;
        strncat(vfPath, path, 128);
        strncat(vfPath, lbl_8059C5A8, 128);
        int result = fn_8001E10C(vfPath, &l);
        Lock* lp = &lock;
        lp->release();
        r = result;
        break;
    }
    }
    self->r = r;
}