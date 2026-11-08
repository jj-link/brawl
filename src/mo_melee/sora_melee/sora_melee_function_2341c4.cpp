#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_236E64(void*, void*, float*, unsigned int);

struct Object_vptr_4_base { char pad[0x4]; };
class Object_vptr_4 : public Object_vptr_4_base {
public:
    virtual void slot0();
    virtual void slot1(int del);
};

struct Self {
    char pad[0x18];
    Object_vptr_4* obj;
};

struct Source {
    char pad0;
    unsigned char c1;
    char pad[2];
    float f4;
    float f8;
    float fc;
    float f10;
};

extern "C" void fn_27_2341C4(Self* self, const Source* src) {
    float d;
    float c;
    float b;
    float a;
    a = src->f4;
    b = src->fc;
    c = src->f10;
    d = src->f8;
    float arr[4];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
    Object_vptr_4* obj = (Object_vptr_4*)__nw__FUlQ25Heaps8HeapType(0x28, 0xf);
    if (obj) {
        obj = (Object_vptr_4*)fn_27_236E64(obj, (char*)self + 0x2c, arr, src->c1 != 0);
    }
    if (self->obj && self->obj) {
        self->obj->slot1(1);
    }
    self->obj = obj;
}
