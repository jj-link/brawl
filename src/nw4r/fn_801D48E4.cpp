#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern "C" char* fn_801CC2E4();
extern "C" void* fn_801BE5A8(int, int, int, void*, void*);
extern "C" void fn_801BF2E0(void*, unsigned char);
extern "C" void fn_801BF2F8(void*, unsigned char);
extern "C" void fn_801BF398(void*, unsigned char);
extern "C" void fn_801BF3A0(void*, unsigned char);
extern "C" void fn_801BE254(void*, void*, int, unsigned int);
extern "C" void fn_801D4EE8();
extern "C" long long fn_803F1470(long long, long long);

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual int slot1(void*, void*, void*, int, int, int, unsigned int);
};

struct A { unsigned char p[4]; unsigned char b0, b1, b2, b3; int pp; };
struct B { char p[2]; unsigned char c; char q; unsigned int w; char r[4]; unsigned int x; char z[0x88]; };

struct Self {
    char pad[0x8f];
    unsigned char f8f;
    unsigned char f90;
    char pad2[7];
    int f98;
    unsigned char f9c;
    char pad3[0xb];
    int fa8;
    int fac;
    int fb0;
    int fb4;
    char pad4[0x10];
    char fc8[0xc];
    void* fd4;
};

extern "C" int fn_801D48E4(Self* self, Object_vptr_0* o, unsigned int n) {
    A a;
    B b;
    OSLockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
    int sz = self->f9c + 0x40;
    if (o->slot1(self->fc8, &a, &b, self->fa8, self->fac, 0, n) == 0) {
        OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
        return 0;
    }
    if (self->fb0 == 0) {
        n = self->fb4;
    } else if (self->fb0 == 1) {
        n = (unsigned int)fn_803F1470((long long)self->fb4 * (long long)(unsigned long long)b.w, 1000);
    }
    if (n > b.x) {
        OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
        return 0;
    }
    int h = self->f98;
    void* r = fn_801BE5A8((int)b.c > 2 ? 2 : (int)b.c, h, sz, (void*)fn_801D4EE8, self);
    if (!r) {
        OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
        return 0;
    }
    fn_801BF2E0(r, a.b0);
    fn_801BF2F8(r, a.b1);
    fn_801BF398(r, a.b2);
    fn_801BF3A0(r, a.b3);
    ((unsigned char*)r)[0x35] = self->f90;
    fn_801BE254(r, &b, -1, n);
    self->fd4 = r;
    self->f8f = 1;
    OSUnlockMutex((OSMutex*)(fn_801CC2E4() + 0x354));
    return 1;
}