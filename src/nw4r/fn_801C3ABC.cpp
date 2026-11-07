#include <types.h>
#pragma force_active on

extern "C" {
void OSLockMutex(void*);
void OSUnlockMutex(void*);
char* fn_801CC2E4();
void fn_801C4DEC(void*);
void fn_801C4EBC(void*);
int fn_801C4FA4(void*, int);
}

struct Vt {
    virtual void a();
    virtual void b();
    virtual void f(void*);
};

struct O {
    char _pad[0xb4];
    Vt* b4;
    void* b8[16];
};

extern "C" int fn_801C3ABC(O* self, int arg1) {
    void* v;
    char* p;
    int result;
    int i;
    void* null_val;
    
    OSLockMutex(fn_801CC2E4() + 0x354);
    
    p = (char*)self;
    result = 0;
    i = 0;
    null_val = 0;
    
    do {
        if (i > 15) {
            v = 0;
        } else {
            v = *(void**)(p + 0xb8);
        }
        if (v != 0) {
            fn_801C4EBC(v);
            if (fn_801C4FA4(v, arg1) < 0) {
                OSLockMutex(fn_801CC2E4() + 0x354);
                void* v2;
                if (i > 15) {
                    v2 = 0;
                } else {
                    v2 = *(void**)(p + 0xb8);
                }
                if (v2 == 0) {
                    OSUnlockMutex(fn_801CC2E4() + 0x354);
                } else {
                    fn_801C4DEC(v2);
                    self->b4->f(*(void**)(p + 0xb8));
                    *(void**)(p + 0xb8) = null_val;
                    OSUnlockMutex(fn_801CC2E4() + 0x354);
                }
            }
            if (((unsigned char*)v)[5]) {
                result = 1;
            }
        }
        i += 1;
        p += 4;
    } while (i < 16);
    
    if (result == 0) {
        OSUnlockMutex(fn_801CC2E4() + 0x354);
        return 1;
    }
    OSUnlockMutex(fn_801CC2E4() + 0x354);
    return 0;
}