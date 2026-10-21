#pragma force_active on
struct Object {
    virtual void unused();
    virtual void* get();
};
struct Context {
    char padding[0x48];
    Object* object;
};
struct Module {
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
    virtual void call();
};
struct Modules {
    char padding[0xC8];
    Module* module;
};
struct Data {
    char padding[0xD8];
    Modules* modules;
};
struct Accessor {
    char padding[0x44];
    Data* data;
};
extern "C" Accessor* fn_27_6F30C(void*);
extern "C" void fn_27_6D000(Context self) {
    void* result = self.object->get();
    Accessor* accessor = fn_27_6F30C(static_cast<char*>(result) + 0x1C);
    accessor->data->modules->module->call();
}
