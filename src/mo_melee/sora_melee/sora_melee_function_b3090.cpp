#pragma force_active on
typedef unsigned int u32;

struct Triple {
    u32 data[3];
};

struct Work {
    unsigned char pad[0x10];
    Triple value;
};

struct Interface {
    virtual void unused();
    virtual void* get(int);
};

struct Owner {
    unsigned char pad[0x18];
    Interface* array;
};

extern "C" Work* fn_27_B16C8(void*);

extern "C" void fn_27_B3090(Triple* result, Owner* self, int index) {
    Work* work = fn_27_B16C8(self->array->get(index));
    *result = work->value;
}
