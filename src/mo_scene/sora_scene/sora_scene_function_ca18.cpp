#pragma force_active on

extern "C" {
extern void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern void* fn_8009A104(void*);
extern void* fn_20_6E0C(void*);
extern void* fn_20_916C(void*);
extern void* lbl_1_bss_60;
extern void* lbl_20_bss_8;
extern void* lbl_8049DEC8;
}

struct Scene {
    unsigned char pad[12];
    void* task;
};

struct Base {
    unsigned char data[0x3C];
};

struct Thing : Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
};

extern "C" void fn_1_CA18(Scene* self) {
    if (!lbl_8049DEC8) {
        void* obj = __nw__FUlQ25Heaps8HeapType(0xAC, 0xD);
        if (obj) {
            obj = fn_8009A104(obj);
        }
        lbl_8049DEC8 = obj;
        static_cast<Thing*>(obj)->f21();
    }
    
    void* task = __nw__FUlQ25Heaps8HeapType(0x500, 0xD);
    if (task) {
        task = fn_20_6E0C(task);
    }
    lbl_20_bss_8 = task;
    self->task = task;
    
    void* res = __nw__FUlQ25Heaps8HeapType(0x28, 0x2A);
    if (res) {
        res = fn_20_916C(res);
    }
    lbl_1_bss_60 = res;
}
