#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" const char lbl_27_data_71BE0[];
extern "C" const char lbl_27_data_CDC0[];

struct Interface {
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void call(int);
};

struct Modules {
    char pad0[0x34];
    Interface* interface;
    char pad1[0x44];
    void* target;
};

struct Object {
    char pad[0xD8];
    Modules* modules;
};

struct Context {
    char pad0[0x60];
    Object* object;
    char pad1[0x85C];
    int state;
};

extern "C" void fn_27_29ED64(void*, Context* context) {
    Interface* interface = context->object->modules->interface;
    interface->call(6);

    if (context->state == 15) {
        char* p = (char*)__dynamic_cast(
            context->object->modules->target, 0,
            lbl_27_data_71BE0, lbl_27_data_CDC0, 1);
        p[0x304] = 0;
        p[0x305] = 5;
    }
}
