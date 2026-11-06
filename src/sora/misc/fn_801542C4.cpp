#pragma force_active on

extern "C" {
extern char __vt__8gfThread[];
extern char lbl_804616D8[];

void createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(
    void*, void*, unsigned long, unsigned long, int);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__6nteDWCFv(void*);
void* fn_80151B38(void*, int);
}

struct Dwc {
    char pad0[0x60];
    void* cb60;
    void* cb64;
};

struct Worker {
    char pad0[0x4C];
    void* cb4C;
    void* cb50;
    char pad54[0x24];
};

struct Thread {
    void* vtable;
    char pad4[0x33C];
    void* cb340;
    void* cb344;
    void* cb348;
    char f34C;
    char pad34D[3];
    int f350;
    int f354;
    int f358;
    int f35C;
    int heap;
    Dwc* dwc;
    Worker* worker;
    char f36C;
    char pad36D[3];
    int f370;
    char f374;
    char pad375[3];
    int f378;
    char f37C;
    char pad37D[3];
    int f380;
    char f384;
    char pad385[3];
    int f388;
};

extern "C" Thread* fn_801542C4(Thread* self, int heap)
{
    self->vtable = __vt__8gfThread;
    createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(
        self, self, 0x10, 0x2000, 0x3A);

    self->vtable = lbl_804616D8;
    self->cb340 = lbl_804616D8 + 0xC;
    self->cb344 = lbl_804616D8 + 0x18;
    self->cb348 = lbl_804616D8 + 0x24;
    self->f34C = 0;
    self->f350 = 0;
    self->f354 = 100;
    self->f358 = 0;
    self->f35C = 0;

    void* obj = __nw__FUlQ25Heaps8HeapType(0x3C8, heap);
    if (obj)
        obj = __ct__6nteDWCFv(obj);
    self->dwc = (Dwc*)obj;

    void* a = self;
    if (self)
        a = &self->cb344;
    self->dwc->cb60 = a;

    void* b = self;
    if (self)
        b = &self->cb340;
    self->dwc->cb64 = b;

    obj = __nw__FUlQ25Heaps8HeapType(0x78, heap);
    if (obj)
        obj = fn_80151B38(obj, 0);
    self->worker = (Worker*)obj;

    void* c = self;
    if (self)
        c = &self->cb340;
    self->worker->cb50 = c;

    void* d = self;
    if (self)
        d = &self->cb348;
    self->worker->cb4C = d;

    self->heap = heap;
    self->f36C = 0;
    self->f370 = 0;
    self->f374 = 0;
    self->f378 = 0;
    self->f37C = 0;
    self->f380 = 0;
    self->f384 = 0;
    self->f388 = 0;
    return self;
}
