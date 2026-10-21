#pragma force_active on
struct Provider {
    virtual void unused();
    virtual char* get();
};
struct Target {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void invoke();
};
struct Modules {
    char padding[0xC8];
    Target* target;
};
struct Data {
    char padding[0xD8];
    Modules* modules;
};
struct Accessor {
    char padding[0x44];
    Data* data;
};
struct Object {
    char padding[0x48];
    Provider* provider;
};
extern "C" Accessor* fn_27_6F30C(void*);
extern "C" void fn_27_6CEB0(Object* __restrict object) {
    char* base = object->provider->get();
    fn_27_6F30C(base + 0x1C)->data->modules->target->invoke();
}
