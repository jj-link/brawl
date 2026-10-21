#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

class Object {
public:
    int data;
    virtual void unused();
    virtual ~Object();
};

struct Owner {
    char pad[0x18];
    Object* object;
    char pad1[0x10];
    char context[1];
};

extern "C" Object* fn_27_2358EC(void*, void*, void*);

extern "C" Object* fn_27_233898(Owner* self, void* arg) {
    Object* result = (Object*)__nw__FUlQ25Heaps8HeapType(0x40, 15);
    if (result)
        result = fn_27_2358EC(result, self->context, arg);
    if (self->object)
        delete self->object;
    self->object = result;
    return result;
}
