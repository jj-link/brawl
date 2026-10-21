#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

struct Object {
    unsigned int data;
    virtual void unused();
    virtual ~Object();
};

extern "C" Object* fn_40_DBE8(Object*, void*, unsigned int);

struct Owner {
    char pad[0x18];
    Object* object;
    char pad1[0x10];
};

extern "C" void fn_27_234660(Owner* self, unsigned int value) {
    Object* object = (Object*)__nw__FUlQ25Heaps8HeapType(0x14, 0xf);
    if (object)
        object = fn_40_DBE8(object, (char*)self + 0x2c, value);

    if (self->object)
        delete self->object;

    self->object = object;
}
