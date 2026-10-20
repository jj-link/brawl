#pragma force_active on
typedef unsigned int u32;

struct Module {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void set(int);
};

struct Modules {
    char pad[0x44];
    Module* module;
};

struct Data {
    char pad[0xD8];
    Modules* modules;
};

struct Accessor {
    char pad[0x44];
    Data* data;
};

struct Flags {
    char pad[0x30];
    u32 flags;
};

struct Node {
    Node* next;
    char pad[8];
    Flags* data;
};

extern "C" void* getNode__6utListFUl(void*, u32);
extern "C" Accessor* fn_27_6F30C(void*);

extern "C" void fn_27_6BEE4(char* self) {
    Node* node = (Node*)getNode__6utListFUl(self + 0x14, 0);
    while (node) {
        if ((node->data->flags >> 8) & 1) {
            fn_27_6F30C(node)->data->modules->module->set(0);
        }
        node = node->next;
    }
}
