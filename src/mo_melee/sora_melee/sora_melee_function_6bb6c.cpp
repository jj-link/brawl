#pragma force_active on
typedef unsigned int u32;

struct Entry {
    char pad[0x30];
    u32 flags;
};

struct Node {
    Node* next;
    char pad[8];
    Entry* data;
};

class utList {
public:
    Node* getNode(unsigned long);
};

class Module {
public:
    char pad[8];

    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual u32 fetch();
};

struct Modules {
    char pad[0x38];
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

struct Owner {
    char pad[0x14];
    utList list;
};

extern "C" Accessor* fn_27_6F30C(void*);

extern "C" u32 fn_27_6BB6C(Owner* self, int value) {
    Node* node = self->list.getNode(0);
    while (node) {
        if (value == (int)((node->data->flags >> 1) & 0x7F)) {
            Module* module = fn_27_6F30C(node)->data->modules->module;
            return module->fetch();
        }
        node = node->next;
    }
    return 0;
}
