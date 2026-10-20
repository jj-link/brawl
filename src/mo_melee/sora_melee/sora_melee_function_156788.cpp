#pragma force_active on
struct Object {
    char pad[0x3C];

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
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual int get();
};

struct Context {
    char pad[8];
    Object* object;
};

extern const int lbl_27_rodata_1C60[];

extern "C" void fn_80077E94(int, void*);

extern "C" void fn_27_156788(void*, void* arg, Context* context) {
    int index = context->object->get();
    fn_80077E94(lbl_27_rodata_1C60[index], arg);
}
