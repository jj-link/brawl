#pragma force_active on

struct ThreadObj {
    void* vtable;
    char pad4[4];
    char thread[0x338];
    void* owner;
};

struct Owner {
    char pad0[0x50];
    int heap;
    char pad54[4];
    ThreadObj* unk58;
    char pad5C[0x12C];
    ThreadObj* thread;
    int state;
    int flag;
};

extern "C" {
    int OSIsThreadTerminated(void*);
    int OSResumeThread(void*);
    void* __dt__8gfThreadFv(void*, short);
    void* __dl__FPv(void*);
    void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
    void createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(void*, void*, unsigned long, unsigned long, int);
    extern char __vt__8gfThread[];
    extern char lbl_804236FC[];
}

inline bool terminated(ThreadObj* t) {
    return OSIsThreadTerminated(t->thread) == 1;
}

inline void initThread(ThreadObj* thread, int heap) {
    thread->vtable = __vt__8gfThread;
    createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(thread, thread, 0xF, 0x1000, heap);
}

extern "C" void fn_80038F6C(Owner* self) {
    switch (self->state) {
    case 0:
        if (self->flag != 0) {
            self->flag = 0;
            self->state = 1;
        }
        break;
    case 1: {
        ThreadObj* thread = (ThreadObj*)__nw__FUlQ25Heaps8HeapType(0x348, self->heap);
        if (thread != 0) {
            initThread(thread, self->heap);
            thread->vtable = lbl_804236FC;
            thread->owner = self;
            OSResumeThread(thread->thread);
        }
        self->thread = thread;
        self->state = self->state + 1;
        break;
    }
    case 2: {
        if (terminated(self->thread)) {
            ThreadObj* t = self->thread;
            if (t != 0) {
                __dt__8gfThreadFv(t, 0);
                __dl__FPv(t);
            }
            self->thread = 0;
            self->state = 0;
        }
        break;
    }
    }
    if (self->unk58 != 0) {
        if (terminated(self->unk58)) {
            __dt__8gfThreadFv(self->unk58, 1);
            self->unk58 = 0;
        }
    }
}
