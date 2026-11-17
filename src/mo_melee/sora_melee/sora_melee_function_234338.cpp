#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_40_DF98(void* self, void* arg1, unsigned char arg2);

struct Pair {
    float a;
    float b;
};

struct Args {
    int a;
    int b;
    int c;
    int d[7];
};

extern "C" void fn_27_234FE8(void* obj, int arg, Args* out);
extern "C" void fn_40_E04C(void* obj, Args* a, const Pair* b);
extern float lbl_27_rodata_38E8;

inline Pair makePair(float f) {
    Pair p = {f, f};
    return p;
}

struct Obj {
    int data;
    virtual void slot0();
    virtual void slot1(int del);
};

struct Owner {
    char pad[0x18];
    Obj* obj;
};

extern "C" void fn_27_234338(Owner* self, int arg) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x48, 0xf);
    if (obj) {
        obj = fn_40_DF98(obj, (char*)self + 0x2c, 1);
    }
    Args sp18;
    fn_27_234FE8(obj, arg, &sp18);
    sp18.b = 0x19;
    sp18.c = 0x200000;
    Pair v = makePair(lbl_27_rodata_38E8);
    fn_40_E04C(obj, &sp18, &v);
    if (self->obj && self->obj) {
        self->obj->slot1(1);
    }
    self->obj = (Obj*)obj;
}
