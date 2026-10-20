#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 pad;
    u32 flags;
};

struct Part {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void clear(int, int);

    Flags* data;
    u32 state;
};

struct Obj;

struct VTable {
    char pad0[0xb0];
    void (*setMdlIndex)(Obj*, int);
    char padb4[0x8c];
    void (*setTgtNode)(Obj*, const char*);
};

struct Obj {
    Obj(const char* name);

    char pad0[0x3c];
    VTable* vtable;
    char pad40[0x90];
    char part[0xc];
    char paddc[0x7c];
    u32 a158;
    u32 a15c;
};

namespace Heaps {
    enum HeapType { StageInstance = 15 };
}

extern void* operator new(unsigned long, Heaps::HeapType);
extern "C" Obj* fn_61_2320(Obj*, const char*);
extern VTable lbl_61_data_1790;

inline Obj::Obj(const char* name) {
    Obj* self = this;
    fn_61_2320(self, name);
    self->vtable = &lbl_61_data_1790;
    self->a158 = 0;
    self->a15c = 0;

    Part* p = (Part*)self->part;
    if (!p)
        return;

    p->state = 1;
    p->clear(0, 15);
    p->data->flags |= 8;
    return;
}

struct Base {
    char pad[0x3c];
};

struct CallObj : Base {
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
    virtual void setMdlIndex(int);
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
    virtual void setTgtNode(const char*);
};

extern "C" Obj* fn_61_5D50(int mdlIndex, const char* node, const char* name) {
    Obj* obj = new (Heaps::StageInstance) Obj(name);
    if (obj) {
        ((CallObj*)obj)->setMdlIndex(mdlIndex);
        ((CallObj*)obj)->setTgtNode(node);
    }
    return obj;
}
