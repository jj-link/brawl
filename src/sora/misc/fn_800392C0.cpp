#pragma force_active on

struct gfThread;

struct Parameters {
    int a;
    int b;
    int value;
    bool flag;
    char rest[0x8B];
};

struct gfRunnable {
    char pad0[0x50];
    int heap;
    char pad54[4];
    gfThread* thread;
    bool flag;
    char pad5D[0x87];
    int a;
    int b;
    char padEC[4];
    Parameters parameters;
};

struct gfThread {
    void* vtable;
    char pad4[4];
    char thread[0x318];
    char tail[0x20];
};

extern "C" {
    int OSIsThreadTerminated(void*);
    int OSResumeThread(void*);
    void* __dt__8gfThreadFv(gfThread*, short);
    void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
    void createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(
        gfThread*, gfRunnable*, unsigned long, unsigned long, int);
    extern char __vt__8gfThread[];
    void* memcpy(void*, const void*, unsigned long);
}

inline bool terminated(gfThread* thread) {
    return OSIsThreadTerminated(thread->thread) == 1;
}

inline void initialize(gfThread* thread, gfRunnable* self,
                       unsigned long priority, unsigned long stackSize,
                       int heap) {
    thread->vtable = __vt__8gfThread;
    createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(
        thread, self, priority, stackSize, heap);
}

extern "C" int fn_800392C0(gfRunnable* self, int value) {
    Parameters params;
    params.a = 1;
    params.b = 1;
    params.value = value;
    params.flag = false;

    if (self->thread != 0) {
        if (!terminated(self->thread))
            return 0;
        __dt__8gfThreadFv(self->thread, 1);
        self->thread = 0;
    }

    gfThread* thread =
        (gfThread*)__nw__FUlQ25Heaps8HeapType(0x340, self->heap);
    if (thread != 0) {
        initialize(thread, self, 15, 0x1800, self->heap);
    }

    self->thread = thread;
    if (thread == 0)
        return 0;

    self->flag = false;
    self->a = 0;
    self->b = 0;
    memcpy(&self->parameters, &params, 0x98);
    OSResumeThread(self->thread->thread);
    return 1;
}
