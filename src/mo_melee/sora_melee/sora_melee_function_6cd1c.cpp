#pragma force_active on
#include <types.h>

extern "C" void* getNode__6utListFUl(void*, u32);

class Module {
public:
    u8 pad[8];
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
    virtual void f42();
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
    virtual void target(s32);
};

struct Entry {
    u8 pad[0x30];
    u32 flags;
};

struct Node {
    Node* next;
    u8 pad[8];
    Entry* entry;
};

struct Modules {
    u32 x;
    Module* module;
};

struct Data {
    u8 pad[0xd8];
    Modules* modules;
};

struct Accessor {
    u8 pad[0x44];
    Data* data;
};

extern "C" Accessor* fn_27_6F30C(void*);

extern "C" void fn_27_6CD1C(void* self, s32 arg) {
    Node* node = (Node*)getNode__6utListFUl((u8*)self + 0x14, 0);
    while (node != 0) {
        if ((node->entry->flags >> 8) & 0x800) {
            Module* mod = fn_27_6F30C(node)->data->modules->module;
            mod->target(arg);
        }
        node = node->next;
    }
}
