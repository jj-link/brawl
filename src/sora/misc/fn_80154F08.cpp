#pragma force_active on
#include <gf/gf_thread.h>
#include <gf/gf_task.h>
#include <revolution/OS/OSThread.h>
#include <types.h>

extern "C" {
extern char lbl_80462050[];
extern char lbl_80461718[];
void* fn_80037E64(void*, int);
void netReport__FPCce(const char*, ...);
void* __dt__8gfThreadFv(void*, short);
}

inline bool terminated(u8* thread) {
    return OSIsThreadTerminated((OSThread*)(thread + 8)) == 1;
}

extern "C" void* fn_80154F08(void* self, int flag) {
    u8* p = (u8*)self;
    if (p != 0) {
        *(char**)p = lbl_80462050;
        *(char**)(p + 0x340) = lbl_80462050 + 0xc;
        *(char**)(p + 0x344) = lbl_80462050 + 0x18;
        if (!terminated(p)) {
            p[0x398] = 1;
            OSResumeThread((OSThread*)(p + 8));
            while (!terminated(p)) {
                OSSleepTicks((*(u32*)0x800000F8 / 4) / 1000);
            }
        }
        if (*(int*)(p + 0x39c) != 0) {
            fn_80037E64(*(void**)(p + 0x39c), 1);
            *(int*)(p + 0x39c) = 0;
        }
        netReport__FPCce(lbl_80461718);
        gfTask* task = *(gfTask**)(p + 0x394);
        task->exit();
        __dt__8gfThreadFv(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return self;
}