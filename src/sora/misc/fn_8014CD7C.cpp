#include <types.h>
#pragma force_active on

extern "C" {
void OSLockMutex(void* mutex);
void OSUnlockMutex(void* mutex);
void fn_8039A1F4();
extern char lbl_8049ECC8[];
extern void* lbl_805A0450;
extern s32 lbl_805A0454;
}

class gfHeapManager {
public:
    static void free(void* p);
};

struct Lock {
    void* mutex;
    bool locked : 8;
    Lock(void* m, bool l = true) {
        mutex = m;
        locked = l;
        if (locked) OSLockMutex(mutex);
    }
    void release() {
        if (locked) OSUnlockMutex(mutex);
    }
};

struct Obj8014CD7C {
    u8 m_active;
    u8 pad[0xc - 1];
    void* m_buf;
    u32 m_size;
};

extern "C" Obj8014CD7C* fn_8014CD7C(Obj8014CD7C* self, s32 flag) {
    if (self) {
        if (self->m_buf) {
            gfHeapManager::free(self->m_buf);
            self->m_size = 0;
            self->m_buf = 0;
        }
        Lock lock(lbl_8049ECC8);
        if (self->m_active) {
            if (--lbl_805A0454 == 0) {
                fn_8039A1F4();
                if (lbl_805A0450) {
                    gfHeapManager::free(lbl_805A0450);
                    lbl_805A0450 = 0;
                }
            }
            self->m_active = 0;
        }
        Lock* lp = &lock;
        lp->release();
        if (flag > 0) {
            delete self;
        }
    }
    return self;
}
