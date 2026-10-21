#pragma force_active on

typedef unsigned char u8;

extern "C" {
int OSIsThreadTerminated(void*);
int OSResumeThread(void*);
void* __dt__8gfThreadFv(void*, short);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(
    void*, void*, unsigned long, unsigned long, int);
extern int __vt__8gfThread[];
void* memcpy(void*, const void*, unsigned long);
}

struct Request {
    int type;
    int count;
    int value;
    u8 rest[0x8c];
};

inline void initializeThread(u8* thread, void* runnable,
                             unsigned long priority,
                             unsigned long stackSize, int heap) {
    *(int**)thread = __vt__8gfThread;
    createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(
        thread, runnable, priority, stackSize, heap);
}

extern "C" int fn_80039A04(u8* self, int value) {
    Request request;
    request.type = 4;
    request.count = 1;
    request.value = value;

    u8* thread = *(u8**)(self + 0x58);
    if (thread != 0) {
        bool terminated = OSIsThreadTerminated(thread + 8) == 1;
        if (!terminated)
            return 0;

        __dt__8gfThreadFv(*(void**)(self + 0x58), 1);
        *(void**)(self + 0x58) = 0;
    }

    u8* next = (u8*)__nw__FUlQ25Heaps8HeapType(
        0x340, *(int*)(self + 0x50));
    if (next != 0) {
        initializeThread(next, self, 0xf, 0x1800, *(int*)(self + 0x50));
    }

    *(u8**)(self + 0x58) = next;
    if (next == 0)
        return 0;

    self[0x5c] = 0;
    *(int*)(self + 0xe4) = 0;
    *(int*)(self + 0xe8) = 0;
    memcpy(self + 0xf0, &request, 0x98);
    OSResumeThread(*(u8**)(self + 0x58) + 8);
    return 1;
}
