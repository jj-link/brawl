#pragma force_active on
struct Interface {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void call(int);
};
struct Module { unsigned char pad[0x64]; Interface *interface; };
struct Object { unsigned char pad[0xD8]; Module *module; };
extern "C" void fn_107_14560(void *, Object *object, int value)
{
    if (value < 0x138 && value >= 0x12D)
        return;
    object->module->interface->call(0x12000041);
}