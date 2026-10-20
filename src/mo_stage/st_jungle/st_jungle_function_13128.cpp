#pragma force_active on
typedef unsigned int u32;

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_51_2838(void*, const char*);
extern "C" char lbl_51_data_8688[];

struct Node {
    u32 pad;
    u32 flags;
};

struct Callback {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void init(int, int);

    Node* node;
    u32 mode;

    void setup() {
        if (this == 0) return;
        mode = 1;
        init(0, 15);
        node->flags |= 8;
    }
};

struct Header {
    char pad[0x3C];
};

struct ObjectView : Header {
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
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void model(int);
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void name(const char*);

    char pad1[0xD0 - 0x40];
    Callback callback;
    char pad2[0x158 - 0xDC];
    u32 field158;
    u32 field15C;
};

struct Object {
    char pad0[0x3C];
    void* vtable;
    char pad1[0x158 - 0x40];
    u32 field158;
    u32 field15C;
    unsigned char field160;

    Object(const char* task) {
        fn_51_2838(this, task);
        vtable = lbl_51_data_8688;
        field158 = 0;
        field15C = 0;
        field160 = 1;

        Callback* cb = (Callback*)((char*)this + 0xD0);
        if (cb == 0) return;
        cb->mode = 1;
        cb->init(0, 15);
        cb->node->flags |= 8;
    }
};

namespace Heaps {
    enum HeapType {
        StageInstance = 15
    };
}

void* operator new(unsigned long, Heaps::HeapType);

extern "C" Object* fn_51_13128(int model, const char* name, const char* task) {
    Object* obj = new (Heaps::StageInstance) Object(task);
    if (obj) {
        ((ObjectView*)obj)->model(model);
        ((ObjectView*)obj)->name(name);
    }
    return obj;
}
