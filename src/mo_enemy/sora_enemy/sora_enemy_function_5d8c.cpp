#pragma force_active on
struct Fn41Target {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void method38(unsigned int);
    virtual void method3C(unsigned int);
};

struct Fn41Module {
    unsigned char pad00[0x64];
    Fn41Target* field_64;
};

struct Fn41Object {
    unsigned char pad00[0xC0];
    float field_C0;
    unsigned int field_C4;
    unsigned char pad_C8[0xEC];
    Fn41Module* field_1B4;
};

extern "C" void fn_27_5CA4(Fn41Object*);
extern "C" void* fn_41_5E20();
extern "C" unsigned int fn_27_5BEA8(void*);
extern "C" const float lbl_41_rodata_18;

extern "C" void fn_41_5D8C(Fn41Object* obj) {
    fn_27_5CA4(obj);
    if (fn_27_5BEA8(fn_41_5E20()) == 1U) {
        obj->field_C0 = lbl_41_rodata_18;
        obj->field_C4 = 0;
        Fn41Target* target = obj->field_1B4->field_64;
        target->method38(0x11000001);
        target->method3C(0x1100000E);
    }
}
