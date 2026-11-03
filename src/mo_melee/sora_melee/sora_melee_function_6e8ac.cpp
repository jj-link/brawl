#pragma force_active on
class Provider {
public:
    virtual void v0();
    virtual char* get();
};

struct Owner {
    char pad[0x48];
    Provider* provider;
};

class Module {
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
    virtual unsigned char v31(int);
    virtual void v32();
    virtual unsigned char v33(int);
    virtual void v34();
    virtual unsigned char v35(int);
};

struct Modules {
    char pad[0x60];
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

extern "C" void fn_27_6E8AC(const Owner* self, int, unsigned char* a2, unsigned char* a3, unsigned char* a4) {
    char* p = self->provider->get();
    *a2 = fn_27_6F30C(p + 0x1c)->data->modules->module->v35(0);
    *a3 = fn_27_6F30C(p + 0x1c)->data->modules->module->v31(0);
    *a4 = fn_27_6F30C(p + 0x1c)->data->modules->module->v33(0);
}
