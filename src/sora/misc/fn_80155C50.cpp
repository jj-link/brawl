#pragma force_active on
#include <gf/gf_thread.h>
#include <gf/gf_heap_manager.h>
#include <revolution/OS/OSThread.h>
#include <revolution/OS/OSTime.h>

extern "C" {
extern char lbl_80461718[];
int fn_80155F54(void* self, void** out1, int* out2);
void* fn_80037DD0();
void* fn_80037E64(void* self, int flag);
int fn_80037F04(void* self, void* a, int b, int c);
void netReport__FPCce(const char* fmt, ...);
void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
}

inline bool terminated(u8* thread) {
    return OSIsThreadTerminated((OSThread*)(thread + 8)) == 1;
}

extern "C" int fn_80155C50(void* arg0) {
    char* base = lbl_80461718;
    u8* self = (u8*)arg0;
    void* heap;
    int r;

    if (terminated(self)) {
        return 0;
    }
    if (*(int*)(self + 0x350) != 0x64) {
        return 0;
    }
    netReport__FPCce(base + 0x2F4);
    if (*(void**)(self + 0x39c) == 0) {
        void* spC = 0;
        int sp8 = 0;
        if (fn_80155F54(self, &spC, &sp8) != 0) {
            heap = __nw__FUlQ25Heaps8HeapType(0x388, *(int*)(self + 0x354));
            if (heap != 0) {
                heap = fn_80037DD0();
            }
            *(void**)(self + 0x39c) = heap;
            netReport__FPCce(base + 0x30C, heap);
            heap = *(void**)(self + 0x39c);
            if (heap != 0) {
                *(u8*)((u8*)heap + 0x380) = 1;
                r = fn_80037F04(*(void**)(self + 0x39c), spC, sp8, *(int*)(self + 0x354));
                if (r != 0) {
                    netReport__FPCce(base + 0x33C, spC, sp8, *(int*)(self + 0x354));
                    while (*(u8*)((u8*)*(void**)(self + 0x39c) + 0x370) == 0) {
                        OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
                    }
                }
                netReport__FPCce(base + 0x390);
                if (*(int*)((u8*)*(void**)(self + 0x39c) + 0x374) != 0) {
                    netReport__FPCce(base + 0x3B4);
                    fn_80037E64(*(void**)(self + 0x39c), 1);
                    *(void**)(self + 0x39c) = 0;
                }
                if (spC != 0) {
                    gfHeapManager::free(spC);
                }
            }
        }
    }
    *(int*)(self + 0x350) = 0;
    OSResumeThread((OSThread*)(self + 8));
    return 1;
}
