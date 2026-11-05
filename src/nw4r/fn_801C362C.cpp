#include <types.h>
#pragma force_active on

extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
char* fn_801CC2E4();
void fn_801CC818(void*, void*);
void* fn_801BE7BC();
void fn_801BE8D0(void*, void*);
void fn_801C4DEC(void*);
}

struct Vt {
    virtual void a();
    virtual void b();
    virtual void f(void*);
};

struct O {
    char _0[0x74];
    char m74[0xC];
    char m80[0xC];
    unsigned char f8c;
    unsigned char f8d;
    char _8e[0x26];
    Vt* b4;
    void* b8[16];
};

extern "C" void fn_801C362C(O* self) {
    s32 i;
    OSLockMutex(fn_801CC2E4() + 0x354);
    OSLockMutex(fn_801CC2E4() + 0x354);

    if (self->f8d) {
        i = (s32)self;
        if (self) i = (s32)self + 0x80;
        fn_801CC818(fn_801CC2E4(), (void*)i);
        self->f8d = 0;
    }

    if (self->f8c) {
        i = (s32)self;
        if (self) i = (s32)self + 0x74;
        fn_801BE8D0(fn_801BE7BC(), (void*)i);
        self->f8c = 0;
    }

    i = 0;
    char* p = (char*)self;
    do {
        OSLockMutex(fn_801CC2E4() + 0x354);
        void* v;
        if (i > 15) {
            v = 0;
        } else {
            v = *(void**)(p + 0xb8);
        }
        if (v == 0) {
            OSUnlockMutex(fn_801CC2E4() + 0x354);
        } else {
            fn_801C4DEC(v);
            self->b4->f(*(void**)(p + 0xb8));
            *(void**)(p + 0xb8) = 0;
            OSUnlockMutex(fn_801CC2E4() + 0x354);
        }
        i += 1;
        p += 4;
    } while (i < 16);

    OSUnlockMutex(fn_801CC2E4() + 0x354);
    OSUnlockMutex(fn_801CC2E4() + 0x354);
}
