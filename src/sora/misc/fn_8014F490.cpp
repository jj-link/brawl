#pragma force_active on

struct gfRunnable {
    void* vtable;
};

struct gfThread {
    void* vtable;
    char pad4[4];
    char thread[0x318];
    char tail[0x20];
};

struct Prefix {
    char pad0[4];
    int heap;
    char pad8[0xC];
};

struct Owner : Prefix, gfRunnable {
    char pad18[4];
    gfThread* thread;
    char pad20[4];
    int arg1;
    int arg2;
    char pad2C[0x60];
    bool flag;
};

extern "C" {
    int OSIsThreadTerminated(void*);
    int OSResumeThread(void*);
    void* __dt__8gfThreadFv(gfThread*, short);
    void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
    void createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(
        gfThread*, gfRunnable*, unsigned long, unsigned long, int);
    extern char __vt__8gfThread[];
}

inline bool terminated(gfThread* thread) {
    return OSIsThreadTerminated(thread->thread) == 1;
}

inline void initialize(gfThread* thread, gfRunnable* runnable, int heap) {
    thread->vtable = __vt__8gfThread;
    createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(
        thread, runnable, 0x10, 0x2000, heap);
}

extern "C" int fn_8014F490(Owner* self, int arg1, int arg2) {
    if (self->thread != 0) {
        if (!terminated(self->thread))
            return 0;
        __dt__8gfThreadFv(self->thread, 1);
        self->thread = 0;
    }

    int heap = self->heap;
    gfThread* thread = (gfThread*)__nw__FUlQ25Heaps8HeapType(0x340, heap);
    if (thread != 0) {
        initialize(thread, static_cast<gfRunnable*>(self), heap);
    }

    self->thread = thread;
    if (thread == 0)
        return 0;

    self->arg1 = arg1;
    self->arg2 = arg2;
    self->flag = false;
    OSResumeThread(thread->thread);
    return 1;
}
