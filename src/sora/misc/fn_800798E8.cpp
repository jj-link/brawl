#include <revolution/OS/OSMutex.h>
#include <snd/snd_system.h>
#pragma force_active on

extern "C" void fn_801DEE84(OSCond*, OSMutex*);
extern "C" void fn_801DEF60(OSCond*);
extern "C" void fn_80073D24(sndSystem*, int, int);
extern "C" void fn_80073D94(sndSystem*, int, int);

struct Request {
    int kind;
    int arg;
    int value;
    int other;
};

struct Thread {
    char pad[0x340];
    OSMutex mutex;
    OSCond work;
    OSCond done;
    Request queue[149];
    Request pending[1];
    unsigned int count;
    unsigned int pendingCount;
    unsigned char running;
};

extern "C" void fn_800798E8(Thread* self) {
    sndSystem* snd = g_sndSystem;
    for (;;) {
        OSLockMutex(&self->mutex);
        while (self->count == 0 && self->pendingCount == 0 && self->running) {
            fn_801DEE84(&self->work, &self->mutex);
        }
        while (self->count != 0 && self->pendingCount < 1) {
            self->pending[self->pendingCount] = self->queue[0];
            ++self->pendingCount;
            for (unsigned int i = 1; i < self->count; ++i) {
                self->queue[i - 1] = self->queue[i];
            }
            --self->count;
        }
        OSUnlockMutex(&self->mutex);
        while (self->pendingCount != 0) {
            switch (self->pending[0].kind) {
            case 1:
                fn_80073D24(snd, self->pending[0].value, self->pending[0].arg);
                break;
            case 2:
                fn_80073D94(snd, self->pending[0].other, self->pending[0].arg);
                break;
            }
            for (unsigned int i = 1; i < self->pendingCount; ++i) {
                self->pending[i - 1] = self->pending[i];
            }
            --self->pendingCount;
        }
        if (!self->running) {
            OSExitThread(0);
            self->running = 1;
        }
        fn_801DEF60(&self->done);
    }
}
