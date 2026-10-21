#pragma force_active on
extern "C" void fn_27_16CCCC(void*, void*);
extern "C" const float lbl_27_rodata_21D0;
extern "C" const float lbl_27_rodata_21D8;

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
    unsigned char padding[0x64];
    Work* work;
};

struct Object {
    unsigned char padding[0xD8];
    Modules* modules;
};

extern "C" void fn_27_16E0D4(void* self, Object* object) {
    fn_27_16CCCC(self, object);
    float value = object->modules->work->getFloat(0x21000008);
    if (value > lbl_27_rodata_21D0) {
        Work* work = object->modules->work;
        value -= lbl_27_rodata_21D8;
        work->setFloat(value, 0x21000008);
    }
}
