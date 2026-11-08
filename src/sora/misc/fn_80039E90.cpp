#pragma force_active on
#include <gf/gf_thread.h>
#include <string.h>

extern "C" {
extern int __vt__8gfThread[];
}

struct Request {
    int kind;
    int count;
    int value;
    char text[0x80];
    char rest[0x0c];
};

inline void initializeThread(gfThread* thread, gfRunnable* runnable,
                             u32 priority, u32 stackSize, Heaps::HeapType heap) {
    *(int**)thread = __vt__8gfThread;
    thread->createThread(runnable, priority, stackSize, heap);
}

extern "C" int fn_80039E90(u8* self, int value, const char* text) {
    Request request;
    request.kind = 6;
    request.count = 1;
    request.value = value;
    strncpy(request.text, text, 0x80);
    request.text[0x7f] = 0;

    gfThread* thread = *(gfThread**)(self + 0x58);
    if (thread != 0) {
        bool terminated = OSIsThreadTerminated((OSThread*)((u8*)thread + 8)) == 1;
        if (!terminated)
            return 0;
        delete *(gfThread**)(self + 0x58);
        *(gfThread**)(self + 0x58) = 0;
    }

    gfThread* next = (gfThread*)operator new(0x340, *(Heaps::HeapType*)(self + 0x50));
    if (next != 0) {
        initializeThread(next, (gfRunnable*)self, 0xf, 0x1800, *(Heaps::HeapType*)(self + 0x50));
    }

    *(gfThread**)(self + 0x58) = next;
    if (next == 0)
        return 0;

    self[0x5c] = 0;
    *(int*)(self + 0xe4) = 0;
    *(int*)(self + 0xe8) = 0;
    memcpy(self + 0xf0, &request, 0x98);
    OSResumeThread((OSThread*)((u8*)*(gfThread**)(self + 0x58) + 8));
    return 1;
}
