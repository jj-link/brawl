#pragma force_active on
#include <gf/gf_heap_manager.h>
#include <revolution/OS/OSThread.h>
extern "C" {
int fn_8038F430();
void fn_8038F4C0();
int fn_8038FD64(void*, void*, int, void*);
void fn_8038FD6C(void*);
int fn_8038FD70(void*, void*, void*, int);
int fn_8038FE28(void*, void*, void*, int);
}
struct NetObj {
    unsigned char pad[0x340];
    int f340;
    unsigned char pad344[0xC];
    int f350;
    unsigned char pad354[0xC];
    void* f360;
    int f364;
    Heaps::HeapType f368;
    int f36C;
    unsigned char f370;
    unsigned char pad371[3];
    int f374;
    void* f378;
    int f37C;
};
extern "C" void fn_80037FFC(NetObj* self) {
    int* valp = &self->f364;
    int val;
    char buf1[0x20];
    char buf2[0x120] __attribute__((aligned(32)));
    int mode = self->f36C;
    if (mode != 0) {
        val = *valp;
        self->f374 = -1;
        self->f37C = val;
        if (mode == 1)
            self->f37C = (val + 0xF) & ~0xF;
        void* ptr = gfHeapManager::alloc(self->f368, self->f37C, 0x20);
        self->f378 = ptr;
        if (ptr) {
            unsigned int base = 0x80000000;
            unsigned int c = 0x10624DD3;
            while (fn_8038F430() == 0) {
                unsigned int t = *(unsigned int*)(base + 0xF8) >> 2;
                unsigned int y = (unsigned int)((unsigned long long)c * t >> 32);
                OSSleepTicks((long long)(y >> 6));
            }
            if (fn_8038FD64(buf2, &self->f350, 0x10, &self->f340) != 0) {
                if (self->f36C == 1) {
                    int raw = self->f364;
                    unsigned int rem = raw & 0x1F;
                    int aligned = raw - rem;
                    if (aligned) {
                        if (fn_8038FD70(buf2, self->f378, self->f360, aligned) == 0)
                            goto cleanup;
                    }
                    if (rem) {
                        memset(buf1, 0, 0x20);
                        memcpy(buf1, (char*)self->f360 + aligned, rem);
                        unsigned int size;
                        if (rem <= 0x10)
                            size = 0x10;
                        else
                            size = 0x20;
                        if (fn_8038FD70(buf2, (char*)self->f378 + aligned, buf1, size) == 0)
                            goto cleanup;
                    }
                    self->f374 = 0;
                } else {
                    if (fn_8038FE28(buf2, self->f378, self->f360, self->f37C) != 0)
                        self->f374 = 0;
                }
                fn_8038FD6C(buf2);
            }
            fn_8038F4C0();
        } else {
            self->f374 = -2;
        }
    cleanup:
        if (self->f374 && self->f378) {
            gfHeapManager::free(self->f378);
            self->f378 = 0;
        }
        self->f370 = 1;
    }
}