#pragma force_active on
struct Object {
    virtual void virtual0();
    virtual void virtual1();
    virtual void virtual2();
    virtual void virtual3();
    virtual void reset();

    unsigned char padding[0x24];
    float value;
    bool flag2C;
    bool flag2D;
    bool flag2E;
    bool flag2F;
    bool flag30;
    bool flag31;
};

extern "C" const float lbl_27_rodata_910[];

extern "C" void fn_27_66154(Object* object) {
    object->reset();
    object->flag2C = true;
    object->flag2D = true;
    object->flag2E = false;
    object->flag31 = false;
    object->flag30 = false;
    object->value = lbl_27_rodata_910[0];
}
