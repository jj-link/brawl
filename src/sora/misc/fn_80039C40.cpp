#pragma force_active on

typedef unsigned char u8;

extern "C" {
int OSIsThreadTerminated(void*);
int OSResumeThread(void*);
void* __dt__8gfThreadFv(void*, short);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(
    void*, void*, unsigned long, unsigned long, int);
void* memcpy(void*, const void*, unsigned long);
extern unsigned char __vt__8gfThread[];
}

struct Request {
    int kind;
    int flag;
    int value;
    u8 rest[0x8C];
};

struct Object {
    u8 pad0[0x50];
    int heap;
    int pad54;
    u8* thread;
    u8 flag;
    u8 pad5D[0x87];
    int fieldE4;
    int fieldE8;
    int fieldEC;
    Request request;
};

inline bool terminated(u8* thread) {
    return OSIsThreadTerminated(thread + 8) == 1;
}

inline void construct(u8* thread, Object* self, int heap) {
    *(void**)thread = __vt__8gfThread;
    createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(
        thread, self, 15, 0x1800, heap);
}

extern "C" int fn_80039C40(Object* self, int value) {
    Request request;
    request.kind = 5;
    request.flag = 1;
    request.value = value;

    if (self->thread != 0) {
        if (!terminated(self->thread))
            return 0;

        __dt__8gfThreadFv(self->thread, 1);
        self->thread = 0;
    }

    u8* thread = (u8*)__nw__FUlQ25Heaps8HeapType(0x340, self->heap);
    if (thread) {
        construct(thread, self, self->heap);
    }

    self->thread = thread;
    if (!thread)
        return 0;

    self->flag = 0;
    self->fieldE4 = 0;
    self->fieldE8 = 0;
    memcpy(&self->request, &request, 0x98);
    OSResumeThread(self->thread + 8);
    return 1;
}
