#pragma force_active on
typedef unsigned int u32;
typedef unsigned long size_t;
typedef void (*Ctor)();

extern "C" void* __nwa__FUlQ25Heaps8HeapType(size_t, int);
extern "C" void* __construct_new_array(void*, Ctor, void*, size_t, int);
extern "C" void* __nw__FUlQ25Heaps8HeapType(size_t, int);
extern "C" void* __ct__14snd3DGeneratorFv(void*);
extern "C" void* memset(void*, int, size_t);
extern "C" char lbl_40_data_2E44;
extern "C" void fn_40_14070(void);

struct Obj {
    u32 unk00;
    void* data;
    u32 count;
    u32 enabled;
    void* items;
    u32 arg4;
    u32 arg5;
    u32 unk1C;
    u32 unk20;
    unsigned char flag;
    unsigned char pad25[3];
    void* generator;
};

extern "C" Obj* fn_40_13FB0(Obj* self, u32 a, u32 b) {
    self->arg4 = a;
    self->unk00 = 0;
    self->count = 11;
    self->data = &lbl_40_data_2E44;
    self->enabled = 1;
    self->items = 0;
    self->arg5 = b;
    self->unk1C = 0;
    self->unk20 = 0;
    self->flag = 1;
    self->generator = 0;

    void* p = __nwa__FUlQ25Heaps8HeapType(0x30, 15);
    p = __construct_new_array(p, fn_40_14070, 0, 0x20, 1);
    self->items = p;
    memset(p, 0, self->enabled << 5);

    void* gen = __nw__FUlQ25Heaps8HeapType(8, 15);
    if (gen)
        gen = __ct__14snd3DGeneratorFv(gen);
    self->generator = gen;
    return self;
}
