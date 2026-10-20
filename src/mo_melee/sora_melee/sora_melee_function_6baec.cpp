#pragma force_active on
typedef unsigned int u32;

struct Entry {
    char pad[0x30];
    u32 flags;
};

struct Node {
    Node* next;
    char pad[8];
    Entry* entry;
};

class utList {
public:
    Node* getNode(unsigned long);
};

struct Owner {
    char pad[0x14];
    utList list;
};

struct Header {
    u32 a, b;
};

class Module : public Header {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual u32 get();
};

struct Modules {
    char pad[0x38];
    Module* module;
};

struct Data {
    char pad[0xd8];
    Modules* modules;
};

struct Accessor {
    char pad[0x44];
    Data* data;
};

extern "C" Accessor* fn_27_6F30C(void*);

extern "C" u32 fn_27_6BAEC(Owner* owner, int id) {
    Node* node = owner->list.getNode(0);
    while (node) {
        if (id == (int)((node->entry->flags >> 1) & 0x7f)) {
            Module* module = fn_27_6F30C(node)->data->modules->module;
            return module->get();
        }
        node = node->next;
    }
    return 0;
}
