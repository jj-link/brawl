#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_2352FC(void* obj, void* p, int arg);

struct Sub {
    int hdr;
    virtual void vf0();
    virtual void vf1(int del);
};

struct Owner {
    char pad[0x18];
    Sub* sub;
};

extern "C" {
void* fn_27_2336E8(Owner* self, int arg) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x40, 0xf);
    if (obj) {
        obj = fn_27_2352FC(obj, (char*)self + 0x2c, arg);
    }
    if (self->sub && self->sub) {
        self->sub->vf1(1);
    }
    self->sub = (Sub*)obj;
    return obj;
}
}
