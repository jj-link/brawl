#pragma force_active on

struct Vec2 {
    float x, y;

    Vec2(float a, float b) : x(a), y(b) {}
    Vec2(unsigned long long bits) {
        *(unsigned long long*)this = bits;
    }
};

struct Module {
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
    virtual void slot12();
    virtual unsigned long long getValue(const short&);
};

struct Object {
    unsigned char pad[0x114];
    void* target;

    bool hasTarget() const { return target != 0; }
};

extern "C" Module* fn_27_8CE14(void*);
extern "C" const float lbl_27_rodata_10B0;

extern "C" Vec2 fn_27_13FED0(Object* self) {
    if (self->hasTarget()) {
        Module* module = fn_27_8CE14(self->target);
        short index = -1;
        return module->getValue(index);
    }
    return Vec2(lbl_27_rodata_10B0, lbl_27_rodata_10B0);
}
