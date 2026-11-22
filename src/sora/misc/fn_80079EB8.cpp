#pragma force_active on
#include <types.h>
#include <gf/gf_heap_manager.h>
#include <revolution/OS/OSMutex.h>

extern "C" {
void __construct_array(void *, void (*)(void *), void (*)(void *), u32, s32);
s32 fn_801BFF28(void *);
void fn_801CA8F0(void *, void *, u32);
void fn_801CA838(void *);
void fn_801CA880(void *);
}

inline s32 getFreeAt(u8 *self, u32 offset) {
    OSMutex *mutex = (OSMutex *)(self + (offset + 0x2E0));
    OSLockMutex(mutex);
    s32 size = fn_801BFF28(self + (offset + 0x2F8));
    OSUnlockMutex(mutex);
    return size;
}

inline s32 getFreeAt2(u8 *self, u32 offset) {
    OSMutex *mutex = (OSMutex *)(self + (offset + 0x25C));
    OSLockMutex(mutex);
    s32 size = fn_801BFF28(self + (offset + 0x274));
    OSUnlockMutex(mutex);
    return size;
}

inline s32 getFreeSize(u8 *heap) {
    OSMutex *mutex = (OSMutex *)(heap + 4);
    OSLockMutex(mutex);
    s32 size = fn_801BFF28(heap + 0x1C);
    OSUnlockMutex(mutex);
    return size;
}

extern "C" void *fn_80079EB8(void *arg0) {
    u8 *self = (u8 *)arg0;
    u32 i;
    u32 cnt;
    u32 o2c;
    u32 o4;
    u32 off;
    void *p;
    u32 *w;

    __construct_array(self + 0x258, fn_801CA838, fn_801CA880, 0x2C, 0xC);

    for (i = 0; i < 5; i++) {
        u8 *q = self + i * 0x78;
        s32 v = i * 6;
        q[0x11] = v;
        q[0x10] = 0;
        *(u32 *)(q + 0xC) = 0;
        q[0x25] = v + 1;
        q[0x24] = 0;
        *(u32 *)(q + 0x20) = 0;
        q[0x39] = v + 2;
        q[0x38] = 0;
        *(u32 *)(q + 0x34) = 0;
        q[0x4D] = v + 3;
        q[0x4C] = 0;
        *(u32 *)(q + 0x48) = 0;
        q[0x61] = v + 4;
        q[0x60] = 0;
        *(u32 *)(q + 0x5C) = 0;
        q[0x75] = v + 5;
        q[0x74] = 0;
        *(u32 *)(q + 0x70) = 0;
    }

    *(u32 *)(self + 0x468) = 0x1C;
    *(u32 *)(self + 0x46C) = 0x1C;
    *(u32 *)(self + 0x470) = 0x1C;

    p = gfHeapManager::alloc((Heaps::HeapType)5, 0x2C699A);
    *(void **)(self + 0x474) = p;
    fn_801CA8F0(self + 0x258, p, 0x2C699A);
    *(s32 *)(self + 0x4A4) = getFreeSize(self + 0x258);

    p = gfHeapManager::alloc((Heaps::HeapType)5, 0x133333);
    *(void **)(self + 0x478) = p;
    fn_801CA8F0(self + 0x284, p, 0x133333);
    *(s32 *)(self + 0x4A8) = getFreeSize(self + 0x284);

    p = gfHeapManager::alloc((Heaps::HeapType)5, 0x151CCD);
    *(void **)(self + 0x47C) = p;
    fn_801CA8F0(self + 0x2B0, p, 0x151CCD);
    *(s32 *)(self + 0x4AC) = getFreeSize(self + 0x2B0);

    {
        u32 heapOffset;
        u32 dataOffset;
        OSMutex *mutex;
        u32 count;
        count = 0;
        dataOffset = 0;
        heapOffset = 0;
        do {
            *(void **)(self + dataOffset + 0x480) =
                gfHeapManager::alloc((Heaps::HeapType)5, 0xF4800);
            fn_801CA8F0((heapOffset + 0x2DC) + self,
                        *(void **)(self + dataOffset + 0x480), 0xF4800);
            mutex = (OSMutex *)(self + (heapOffset + 0x2E0));
            OSLockMutex(mutex);
            s32 result = fn_801BFF28(self + (heapOffset + 0x2F8));
            OSUnlockMutex(mutex);
            count++;
            *(s32 *)((self + 0x4B0) + dataOffset) = result;
            dataOffset += 4;
            heapOffset += 0x2C;
        } while (count < 4);
    }

    p = gfHeapManager::alloc((Heaps::HeapType)5, 0x66666);
    *(void **)(self + 0x490) = p;
    fn_801CA8F0(self + 0x38C, p, 0x66666);
    *(s32 *)(self + 0x4C0) = getFreeSize(self + 0x38C);

    {
        u32 index;
        OSMutex *mutex;
        u32 heapOffset;
        u32 dataOffset;
        index = 8;
        dataOffset = 0x20;
        heapOffset = 0x160;
        do {
            {
                void **slot = (void **)(self + dataOffset + 0x474);
                *slot = gfHeapManager::alloc((Heaps::HeapType)5, 0xF555);
                fn_801CA8F0(self + heapOffset + 0x258, *slot, 0xF555);
            }
            mutex = (OSMutex *)((self + 0x25C) + heapOffset);
            OSLockMutex(mutex);
            s32 result = fn_801BFF28((self + 0x274) + heapOffset);
            OSUnlockMutex(mutex);
            index++;
            *(s32 *)((self + 0x4A4) + dataOffset) = result;
            dataOffset += 4;
            heapOffset += 0x2C;
        } while (index <= 10);
    }

    w = (u32 *)(self + 0x4A0);
    *w = 0;
    for (i = 0; i < 13; i++) {
        *(u32 *)(self + 0x4D0 + i * 4) = 0;
    }
    return arg0;
}
