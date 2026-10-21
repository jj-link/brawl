#pragma force_active on
struct Source {
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
    virtual void invoke();
};
struct Modules {
    char reserved[0xC8];
    Target* target;
};
struct Data {
    char reserved[0xD8];
    Modules* modules;
};
struct Accessor {
    char reserved[0x44];
    Data* data;
};
struct Object {
    char reserved[0x48];
    Source* source;
};
extern "C" Accessor* fn_27_6F30C(void*);

extern "C" void fn_27_6CDA4(Object* __restrict object) {
    char* node = object->source->get();
    fn_27_6F30C(node + 0x1C)->data->modules->target->invoke();
}
