#pragma force_active on
#include <gf/gf_thread.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_task.h>

extern "C" {
extern char lbl_80461048[];
void* fn_8014CD7C(void*, int);
}

inline bool terminated(gfThread* thread) {
    return OSIsThreadTerminated((OSThread*)((u8*)thread + 8)) == 1;
}

extern "C" void* fn_8014E520(void* self, int flag) {
    if (self != 0) {
        u8* p = (u8*)self;
        gfThread* thread = *(gfThread**)(p + 0x1C);
        *(char**)(p + 0x94) = lbl_80461048;
        *(char**)(p + 0x14) = lbl_80461048 + 8;
        *(char**)(p + 0x18) = lbl_80461048 + 0x14;
        if (thread != 0) {
            while (!terminated(*(gfThread**)(p + 0x1C))) {
                OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
            }
            delete *(gfThread**)(p + 0x1C);
            *(gfThread**)(p + 0x1C) = 0;
        }
        void* buffer = *(void**)(p + 0x88);
        if (buffer != 0) {
            gfHeapManager::free(buffer);
            *(void**)(p + 0x88) = 0;
        }
        u8* task = *(u8**)(p + 0x20);
        if (task != 0) {
            ((gfTask*)(task + 4))->exit();
            *(u8**)(p + 0x20) = 0;
        }
        fn_8014CD7C(self, 0);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
