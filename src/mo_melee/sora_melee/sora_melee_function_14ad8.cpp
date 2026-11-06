#pragma force_active on

struct Flags165 {
    unsigned char top : 2;
    unsigned char mode : 2;
    unsigned char low : 4;
};

class Class_20E8 {
public:
    virtual void fn_27_1F1B8();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
    virtual void fn_27_14A68(float value);
    virtual void fn_27_14AD8();
    virtual float fn_27_14A60();
    virtual void fn_27_14D08();

    unsigned char pad4[0x54];
    void* field58;
    unsigned char pad5C[0x165 - 0x5C];
    Flags165 field165;
};

extern "C" void fn_27_1B354(void* self, void* target, int flag, short* param, int zero, float value);

extern "C" void fn_27_14AD8(Class_20E8* self, float value) {
    int spC;
    short sp8;
    void* r31;

    self->fn_27_14A68(value);
    r31 = self->field58;
    sp8 = 2;
    fn_27_1B354(self, r31, 1, &sp8, 0, value);
    *(short*)&spC = 0x40;
    fn_27_1B354(self, r31, 0, (short*)&spC, 0, value);
    self->field165.mode = 1;
}
