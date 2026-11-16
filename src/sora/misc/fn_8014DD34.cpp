#include <types.h>
#include <gf/gf_heap_manager.h>
#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0(int, int, int);
};

struct Self {
    u8 flag;
    u8 pad[3];
    Heaps::HeapType heap;
    Object_vptr_0* obj;
};

extern "C" {
int fn_8039A008(void*);
int fn_8039A52C();
extern OSMutex lbl_8049ECC8;
extern s32 lbl_805A0454;
extern void* lbl_805A0450;
}

struct Lock {
    OSMutex* mutex;
    bool locked : 8;
    Lock(OSMutex* m) : mutex(m), locked(true) { OSLockMutex(mutex); }
    void release() { if (locked) OSUnlockMutex(mutex); }
};

inline void initialize(void* buffer, int retry, int& result) {
    result = -1;
    if (buffer) {
        int n = 10;
        while (n > 0) {
            result = fn_8039A008(lbl_805A0450);
            if (retry) {
                switch (result) {
                case 0:
                    break;
                case -22:
                case -26:
                case -29:
                    OSSleepTicks(1000 * (s64)((*(u32*)0x800000F8 / 4) / 1000));
                    break;
                }
                break;
            } else {
                n = 0;
            }
        }
        if (result != 0 && lbl_805A0450 != 0) {
            gfHeapManager::free(lbl_805A0450);
            lbl_805A0450 = 0;
        }
    }
}

extern "C" int fn_8014DD34(Self* self, int arg1) {
        Object_vptr_0* o;
    Lock lock(&lbl_8049ECC8);
    if (self->flag != 0) {
        lock.release();
        return 1;
    }
    if (lbl_805A0454 != 0) {
        lock.release();
        return 1;
    }
    lock.release();

    void* buffer = lbl_805A0450;
    if (buffer == 0) {
        buffer = gfHeapManager::alloc(self->heap, 0x4000, 0x20);
        lbl_805A0450 = buffer;
        if (buffer == 0) {
            if (self->obj != 0) self->obj->slot0(3, -1, 0x1ADAF);
            return 0;
        }
    }
    int r31;
    initialize(buffer, arg1, r31);
    switch (r31) {
    case 0:
        OSLockMutex(&lbl_8049ECC8);
        self->flag = 1;
        lbl_805A0454 = lbl_805A0454 + 1;
        OSUnlockMutex(&lbl_8049ECC8);
        return 1;
    case -22:
    case -26:
    case -29: {
        int v = fn_8039A52C();
        o = self->obj;
        if (o != 0) {
            int a = v;
            if (v < 0) a = -v;
            o->slot0(4, r31, a);
        }
        break;
    }
    case -46: case -43: case -38: case -21: case -20:
    case -19: case -18: case -17: case -16: case -14: {
        int v = fn_8039A52C();
        Object_vptr_0* o = self->obj;
        if (o != 0) {
            int a = v;
            if (v < 0) a = -v;
            o->slot0(1, r31, a);
        }
        break;
    }
    case -49: {
        int v = fn_8039A52C();
        Object_vptr_0* o = self->obj;
        if (o != 0) {
            int a = v;
            if (v < 0) a = -v;
            o->slot0(2, r31, a);
        }
        break;
    }
    case -42: case -1: {
        int v = fn_8039A52C();
        Object_vptr_0* o = self->obj;
        if (o != 0) {
            int a = v;
            if (v < 0) a = -v;
            o->slot0(3, r31, a);
        }
        break;
    }
    default: {
        int v = fn_8039A52C();
        Object_vptr_0* o = self->obj;
        if (o != 0) {
            int a = v;
            if (v < 0) a = -v;
            o->slot0(3, r31, a);
        }
        break;
    }
    }
    return 0;
}
