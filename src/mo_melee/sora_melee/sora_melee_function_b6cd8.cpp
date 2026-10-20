#pragma force_active on
typedef unsigned int u32;

struct Object {
    char pad[8];
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
    virtual u32 get(int);
};

struct Module {
    char pad[4];
    Object* object;
};

struct Input {
    char pad[0xD8];
    Module* module;
};

extern "C" char* lbl_27_bss_5668;
extern "C" void fn_27_228C04(char*, u32);

extern "C" void fn_27_B6CD8(void*, Input* input) {
    Module* module = input->module;
    char* target = *(char**)(lbl_27_bss_5668 + 0xC4);
    Object* object = module->object;
    fn_27_228C04(target, object->get(1));
}
