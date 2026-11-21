#pragma force_active on
#include <types.h>
#include <revolution/OS/OSMutex.h>
#include <gf/gf_heap_manager.h>
extern "C" {
int fn_801BFF1C(int*);
void fn_801CA8F8(void*);
void fn_801CAA28(void*, unsigned char);
}
struct Entry {
    char pad[4];
    OSMutex mutex;
    int list;
    char tail[12];
};
struct Container {
    char pad[0x258];
    Entry entries[1];
};
extern "C" void fn_8007AA48(char* self, unsigned int arg1, int arg2) {
    char* p;
    Entry* r29;
    OSMutex* r28;
    int hi = (arg1 >> 8) & 0xFF;
    unsigned char lo = arg1 & 0xFF;
    if (arg2 == 0x1B && arg1 == 0) {
        fn_801CAA28(self + 0x284, 0);
        unsigned int i = 3;
        p = self + 0x2DC;
        do {
            fn_801CAA28(p, 0);
            i++;
            p += 0x2C;
        } while (i <= 6);
        return;
    }
    if (hi == 0x1B) {
        hi = 3;
    }
    r29 = &((Container*)self)->entries[hi];
    r28 = &r29->mutex;
    OSLockMutex(r28);
    int r31 = fn_801BFF1C(&r29->list);
    OSUnlockMutex(r28);
    if (r31 >= (int)lo) {
        fn_801CAA28(r29, lo);
    }
    if (hi == 0xB) {
        fn_801CA8F8(self + 0x43C);
        gfHeapManager::free(*(void**)(self + 0x4A0));
        *(void**)(self + 0x4A0) = 0;
        *(int*)(self + 0x4D0) = 0;
    }
}