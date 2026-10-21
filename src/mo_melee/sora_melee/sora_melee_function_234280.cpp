#pragma force_active on

struct Pair {
    int a;
    int b;
};

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_40_DDF0(void*, unsigned int, unsigned char);
void fn_40_DEA4(void*, int, Pair);
}

struct Base {
    int data;
};

struct Object : Base {
    virtual void f0();
    virtual ~Object();
};

extern "C" void fn_27_234280(char* self, int arg1, Pair arg2) {
    void* ret = __nw__FUlQ25Heaps8HeapType(0x48, 15);
    if (ret) {
        ret = fn_40_DDF0(ret, (unsigned int)(self + 0x2c), 1);
    }

    fn_40_DEA4(ret, arg1, arg2);

    Object* old = *(Object**)(self + 0x18);
    if (old) {
        delete old;
    }

    *(void**)(self + 0x18) = ret;
}
