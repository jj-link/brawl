#include <types.h>
#include <revolution/OS/OSMutex.h>

extern "C" {
int fn_801C914C(void*, void*, int*, int);
int fn_801C6BB4(void*);
int fn_801C6C04(void*, int*);
void fn_801C07F8(void*, int, int, int);
void fn_801C219C(int, int, int);
}

inline int reserve_end(int current, int size) {
    return ((unsigned int)(size + current) + 3) & ~3;
}

inline int setup_pool(char* pool, int* p, int end, int count, int unit) {
    int aligned;
    int current = *p;
    int size = count * unit;
    aligned = (size + current + 3) & ~3;

    if (aligned - end > 0)
        return 0;

    OSMutex* mutex = (OSMutex*)(pool + 0x10);
    OSLockMutex(mutex);
    fn_801C07F8(pool, current, size, unit);
    OSUnlockMutex(mutex);

    *p = aligned;
    return 1;
}

inline int setup_pool_tail(char* pool, int* p, int end, int count, int unit) {
    int current = *p;
    OSMutex* mutex;
    int size = count * unit;
    int aligned = (size + current + 3) & ~3;

    if (aligned - end > 0)
        return 0;

    mutex = (OSMutex*)(pool + 0x10);
    OSLockMutex(mutex);
    fn_801C07F8(pool, current, size, unit);
    OSUnlockMutex(mutex);

    *p = aligned;
    return 1;
}

#pragma force_active on
extern "C" int fn_801C8EB4(void* arg0, void* arg1, int* arg2, int arg3) {
    int sp[7];
    int end = (int)arg2 + arg3;
    sp[0] = (int)arg2;

    if (fn_801C914C(arg0, arg1, &sp[0], end) == 0)
        return 0;

    int count = fn_801C6BB4(arg1);
    union SizeValue {
        unsigned int unsignedValue;
        int signedValue;
    } tableSize;
    tableSize.unsignedValue = count * 8 + 4;
    int current = sp[0];
    int aligned = reserve_end(current, tableSize.signedValue);
    int result;

    if (aligned - end > 0) {
        result = 0;
    } else {
        *(int*)((char*)arg0 + 0x14) = current;
        sp[0] = aligned;

        int n = fn_801C6BB4(arg1);
        int* base = *(int**)((char*)arg0 + 0x14);
        *base = n;

        unsigned int i = 0;
        unsigned int offset = 0;
        while (i < (unsigned int)**(int**)((char*)arg0 + 0x14)) {
            *(int*)((char*)*(int**)((char*)arg0 + 0x14) + offset + 4) = 0;
            i++;
            *(int*)((char*)*(int**)((char*)arg0 + 0x14) + offset + 8) = 0;
            offset += 8;
        }

        result = 1;
    }

    if (result == 0)
        return 0;

    if (fn_801C6C04(arg1, &sp[1]) != 0) {
        if (!setup_pool((char*)arg0 + 0x38, &sp[0], end, sp[1], 0x44c))
            return 0;
        if (!setup_pool_tail((char*)arg0 + 0x60, &sp[0], end, sp[3], 0xb3c))
            return 0;
        if (!setup_pool_tail((char*)arg0 + 0x88, &sp[0], end, sp[6], 0x1bc))
            return 0;

        current = sp[0];
        int size = sp[2] * 0xd8;
        aligned = (size + current + 3) & ~3;

        if (aligned - end > 0) {
            result = 0;
        } else {
            fn_801C219C((int)((char*)arg0 + 0xb0), current, size);
            result = 1;
        }

        if (!result)
            return 0;
    }

    *(void**)((char*)arg0 + 0x10) = arg1;
    *(int*)((char*)arg0 + 0xd8) = (int)arg2;
    *(int*)((char*)arg0 + 0xdc) = arg3;
    return 1;
}
