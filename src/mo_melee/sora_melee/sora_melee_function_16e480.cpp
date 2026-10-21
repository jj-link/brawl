#pragma force_active on
extern "C" void fn_27_16B950();
extern "C" const float lbl_27_rodata_21E8;
extern "C" const float lbl_27_rodata_21EC;

struct Work {
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
    virtual float getFloat(unsigned int);
    virtual void setFloat(float, unsigned int);
};

struct Modules {
    char unused[0x64];
    Work* work;
};

struct Object {
    char unused[0xD8];
    Modules* modules;
};

extern "C" void fn_27_16E480(void*, Object* object) {
    fn_27_16B950();
    Work* work = object->modules->work;
    float value = work->getFloat(0x21000009);
    if (value > lbl_27_rodata_21E8) {
        value -= lbl_27_rodata_21EC;
        object->modules->work->setFloat(value, 0x21000009);
    }
}
