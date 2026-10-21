#pragma force_active on
struct Provider {
    virtual void unused();
    virtual char* get();
};
struct Object {
    char padding[0x48];
    Provider* provider;
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
    virtual void unused11();
    virtual void invoke();
};
struct Modules {
    char padding[0xC4];
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
extern "C" void fn_27_6CB68(Object* __restrict self) {
    char* object = self->provider->get();
    fn_27_6F30C(object + 0x1C)->data->modules->module->invoke();
}
