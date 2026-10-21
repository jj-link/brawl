#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;

class Query {
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
    virtual u32 get(u32);
};

struct Data {
    u8 pad[5];
    u8 flag : 1;
    u8 remaining : 7;
};

class Accessor {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Data* get(u32);
};

struct Modules {
    u8 pad[0x64];
    Query* query;
    u8 pad68[0x14];
    Accessor* accessor;
};

struct Object {
    u8 pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_160268(Object* self) {
    if (self->modules->query->get(0x2200000D) == 1U) {
        Data* a = self->modules->accessor->get(5);
        a->flag = 0;
        Data* b = self->modules->accessor->get(7);
        b->flag = 0;
    } else {
        Data* a = self->modules->accessor->get(5);
        a->flag = 1;
        Data* b = self->modules->accessor->get(7);
        b->flag = 1;
    }
}
