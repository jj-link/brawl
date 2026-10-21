#pragma force_active on
struct Result {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void invoke();
};
struct Module {
    char pad[8];
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual Result* get();
};
struct Modules {
    char pad[0xd8];
    Module** module;
};
struct Accessor {
    char pad[0x44];
    Modules* modules;
};
struct Provider {
    virtual void slot08();
    virtual void* get();
};
struct Object {
    char pad[0x48];
    Provider* provider;
};
extern "C" Accessor* fn_27_6F30C(void*);
extern "C" void fn_27_6CC64(Object* __restrict self) {
    void* node = self->provider->get();
    Accessor* accessor = fn_27_6F30C((char*)node + 0x1c);
    Module* module = *accessor->modules->module;
    module->get()->invoke();
}
