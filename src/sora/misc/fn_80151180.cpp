#include <types.h>
#include <revolution/OS/OSThread.h>
#pragma force_active on
struct ThreadObject {
    void* vtable;
    char pad[4];
    OSThread thread;
    char pad2[0x34e - 8 - sizeof(OSThread)];
    s8 flag;
    bool terminated() { return OSIsThreadTerminated(&thread) == 1; }
    void resume() { OSResumeThread(&thread); }
};
extern int lbl_80461368[];
extern char lbl_80461108[];
extern "C" void netReport__FPCce(const char*, ...);
extern "C" void* __dt__8gfThreadFv(void*, int);
extern "C" void __dl__FPv(void*);
extern "C" ThreadObject* fn_80151180(ThreadObject* self, int flag) {
    if (self) {
        self->flag = 0;
        self->vtable = lbl_80461368;
        while (!self->terminated()) {
            self->resume();
            OSSleepTicks(15 * (s64)((*(u32*)0x800000F8 / 4) / 1000));
        }
        netReport__FPCce(lbl_80461108);
        __dt__8gfThreadFv(self, 0);
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}