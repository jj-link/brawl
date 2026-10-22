#pragma force_active on

extern "C" {
extern char __vt__8gfThread[];
extern char lbl_80462050[];

void createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(
    void*, void*, unsigned long, unsigned long, int);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_80151B38(void*, int);
}

struct Worker {
    char pad0[0x4C];
    void* callback4C;
    void* callback50;
    char pad54[0x24];
};

struct Thread {
    void* vtable;
    char pad4[0x33C];
    void* callback340;
    void* callback344;
    char field348;
    char pad349[3];
    int field34C;
    int field350;
    int field354;
    int field358;
    char pad35C[0x30];
    int field38C;
    char field390;
    char pad391[3];
    Worker* worker;
    char field398;
    char pad399[3];
    int field39C;
};

extern "C" Thread* fn_80154E14(Thread* self, int heap)
{
    self->vtable = __vt__8gfThread;
    createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(
        self, self, 15, 0x2000, 0x3A);

    self->vtable = lbl_80462050;
    self->callback340 = lbl_80462050 + 12;
    self->callback344 = lbl_80462050 + 24;
    self->field348 = 0;
    self->field34C = 0;
    self->field358 = 0;
    self->field350 = 100;

    void* obj = __nw__FUlQ25Heaps8HeapType(0x78, heap);
    if (obj)
        obj = fn_80151B38(obj, 1);
    self->worker = (Worker*)obj;

    void* cb = self;
    if (self)
        cb = &self->callback340;
    self->worker->callback50 = cb;

    cb = self;
    if (self)
        cb = &self->callback344;
    self->worker->callback4C = cb;

    self->field354 = heap;
    self->field398 = 0;
    self->field38C = 0;
    self->field390 = 0;
    self->field39C = 0;
    return self;
}
