#pragma force_active on
namespace Heaps {
    enum HeapType { StageInstance = 15 };
}

void* operator new(unsigned long, Heaps::HeapType);

extern "C" void fn_50_1F78(void*, const char*);
extern "C" unsigned char lbl_50_data_12F8[];
extern "C" const float lbl_50_rodata_88;

inline void* operator new(unsigned long, void* p) { return p; }

struct Flags {
    unsigned int unused;
    unsigned int bits;
};

struct Callback {
    unsigned int unused;
    Flags* flags;
    void enable() { if (this) flags->bits |= 1; }
};

struct Prefix {
    unsigned char pad[0x3c];
};

struct VirtualObject : Prefix {
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
    virtual void node(const char*);
    virtual void f79();
    virtual void f80();
};

struct Object {
    unsigned char pad0[0x3c];
    void (**vtable)(Object*, const void*);
    unsigned char pad40[0x24];
    float value;
    unsigned char pad68[0x68];
    Callback callback;
    unsigned char padd8[0x8c];
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned char d;
    unsigned char tail[3];

    Object(const char* name) {
        fn_50_1F78(this, name);
        vtable = (void (**)(Object*, const void*))lbl_50_data_12F8;
        a = 0;
        b = 0;
        c = 999999;
        d = 8;
        value = lbl_50_rodata_88;

        char* p = (char*)this + 0xd0;
        if (!p)
            return;
        *(unsigned int*)(*(char**)(p + 4) + 4) |= 1;
    }
};

extern "C" Object* fn_50_38CC(int model, const char* node, const char* name) {
    Object* obj = new (Heaps::StageInstance) Object(name);
    if (obj) {
        ((VirtualObject*)obj)->model(model);
        ((VirtualObject*)obj)->node(node);
    }
    return obj;
}
