#pragma force_active on
struct Object {
    virtual void dummy();
    virtual char* get(int);
};

struct Context {
    char pad[0x38];
    int id;
    char pad3c[0xC];
    Object* object;
};

struct Result {
    int words[3];
};

struct Module {
    int pad[2];
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void dummy10();
    virtual void dummy11();
    virtual void dummy12();
    virtual void dummy13();
    virtual void dummy14();
    virtual void dummy15();
    virtual void dummy16();
    virtual void dummy17();
    virtual void dummy18();
    virtual void dummy19();
    virtual void dummy20();
    virtual void dummy21();
    virtual void dummy22();
    virtual void dummy23();
    virtual void dummy24();
    virtual void dummy25();
    virtual void dummy26();
    virtual void dummy27();
    virtual void dummy28();
    virtual void dummy29();
    virtual void dummy30();
    virtual void dummy31();
    virtual void dummy32();
    virtual void dummy33();
    virtual void dummy34();
    virtual void dummy35();
    virtual Result invoke(void*, int);
};

struct ModuleHolder {
    char pad[4];
    Module* module;
};

struct Data {
    char pad[0xD8];
    ModuleHolder* holder;
};

struct Accessor {
    char pad[0x44];
    Data* data;
};

extern "C" Accessor* fn_27_6F30C(void*);

extern "C" Result fn_27_6DD5C(Context* context, void* arg) {
    char* node = context->object->get(context->id);
    Module* module = fn_27_6F30C(node + 0x1C)->data->holder->module;
    return module->invoke(arg, 0);
}
