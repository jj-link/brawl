#pragma force_active on
struct Header {
    unsigned int a, b;
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
    virtual void set(int);
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

class Provider {
public:
    virtual void v0();
    virtual char* get();
};

struct Owner {
    char pad[0x48];
    Provider* provider;
};

extern "C" Accessor* fn_27_6F30C(void*);

extern "C" void fn_27_6C908(Owner* owner) {
    fn_27_6F30C(owner->provider->get() + 0x1c)->data->modules->module->set(0);
}
