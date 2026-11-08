#include <types.h>
#pragma force_active on

class soNullable {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual int slot17(u32);
    virtual void slot18();
    virtual void slot19(u32);
};

class Object_vptr_0 {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49(void*, int);
};

struct Modules {
    unsigned char padding[0x64];
    soNullable* work;
    unsigned char padding2[0x14];
    void* obj7c;
};

struct Accessor {
    unsigned char padding[0xD8];
    Modules* modules;
};

struct Context {
    unsigned char padding[0x60];
    Accessor* accessor;
};

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" const char lbl_27_data_71BE0[];
extern "C" const char lbl_27_data_CDC0[];

extern "C" int fn_27_29DE30(void*, Context* context) {
    soNullable* work = context->accessor->modules->work;
    if (work->slot17(0x12000000) != 0) {
        work->slot19(0x12000000);
        work->slot19(0x22000005);
        Object_vptr_0* p = (Object_vptr_0*)__dynamic_cast(
            context->accessor->modules->obj7c, 0,
            lbl_27_data_71BE0, lbl_27_data_CDC0, 1);
        p->slot49(context->accessor, 1);
    }
    return 0;
}