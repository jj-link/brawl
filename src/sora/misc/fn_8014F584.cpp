#pragma force_active on

typedef unsigned char u8;

extern "C" {
int OSIsThreadTerminated(void*);
int OSResumeThread(void*);
void* __dt__8gfThreadFv(void*, short);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(
    void*, void*, unsigned long, unsigned long, int);
extern unsigned char __vt__8gfThread[];
void* fn_80038984(void*, int);
}

struct Base0 {
    int pad0;
    int heap;
    u8 pad8[0x0C];
};

struct RunBase {
    int a;
    int b;
};

struct Object : Base0, RunBase {
    u8* thread;
    void* obj20;
    int field24;
    int field28;
    u8 pad2C[0x60];
    u8 flag;
};

inline bool terminated(u8* thread) {
    return OSIsThreadTerminated(thread + 8) == 1;
}

extern "C" int fn_8014F584(Object* self, int value) {
    if (self->thread != 0) {
        if (!terminated(self->thread))
            return 0;
        __dt__8gfThreadFv(self->thread, 1);
        self->thread = 0;
    }

    int heap = self->heap;
    if (self->obj20 == 0) {
        void* o = __nw__FUlQ25Heaps8HeapType(0x194, heap);
        if (o) {
            o = fn_80038984(o, heap);
        }
        self->obj20 = o;
        if (!o)
            return 0;
    }

    u8* thread = (u8*)__nw__FUlQ25Heaps8HeapType(0x340, heap);
    if (thread) {
        RunBase* r = self;
        *(void**)thread = __vt__8gfThread;
        createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(
            thread, r, 0x10, 0x2000, heap);
    }
    self->thread = thread;
    if (!thread)
        return 0;

    self->field24 = 3;
    self->field28 = value;
    self->flag = 0;
    OSResumeThread(thread + 8);
    return 1;
}
