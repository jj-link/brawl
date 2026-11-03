#include <revolution/OS/OSThread.h>
#pragma force_active on
extern "C" void* fn_801CFA14();
extern "C" void fn_801D0130(void*);
extern "C" void* fn_801D0344(void*);
struct Thread {
    OSThread thread;
    void* stack;
    unsigned char stop;
    unsigned char active;
};
extern "C" int fn_801D0218(Thread* self, int priority, char* stack, unsigned int size) {
    if (self->active) {
        if (self->active) {
            self->stop = 1;
            fn_801D0130(fn_801CFA14());
            OSJoinThread(&self->thread, 0);
            self->active = 0;
        }
    }
    if (!OSCreateThread(&self->thread, fn_801D0344, self, stack + size, size, priority, 0))
        return 0;
    self->stack = stack;
    self->stop = 0;
    self->active = 1;
    OSResumeThread(&self->thread);
    return 1;
}