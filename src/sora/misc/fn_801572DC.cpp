#pragma force_active on
#include <gf/gf_thread.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_task.h>
#include <revolution/OS/OSThread.h>
#include <types.h>

extern "C" {
extern char lbl_804620C4[];
void* fn_80151180(void*, int);
void* __dt__8gfThreadFv(void*, short);
}

inline bool terminated(u8* thread) {
    return OSIsThreadTerminated((OSThread*)(thread + 8)) == 1;
}

extern "C" void* fn_801572DC(void* self, int flag) {
    u8* p = (u8*)self;
    if (p != 0) {
        *(char**)p = lbl_804620C4;
        *(char**)(p + 0x340) = lbl_804620C4 + 0xC;
        *(char**)(p + 0x344) = lbl_804620C4 + 0x18;
        if (!terminated(p)) {
            p[0x37C] = 1;
            OSResumeThread((OSThread*)(p + 8));
            while (!terminated(p)) {
                OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
            }
        }
        if (*(int*)(p + 0x378) != 0) {
            fn_80151180(*(void**)(p + 0x378), 1);
            *(int*)(p + 0x378) = 0;
        }
        if (*(void**)(p + 0x358) != 0) {
            gfHeapManager::free(*(void**)(p + 0x358));
            *(void**)(p + 0x358) = 0;
        }
        if (*(int*)(p + 0x370) != 0) {
            ((gfTask*)(*(u8**)(p + 0x370) + 4))->exit();
            *(int*)(p + 0x370) = 0;
        }
        __dt__8gfThreadFv(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return self;
}
