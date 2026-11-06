#pragma force_active on
#pragma force_active off

class soNullable {
public:
    virtual void isNull();
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
    virtual int slot25(int);

    char pad[0x10];
    float a;
    float b;
    float c;
};

extern "C" float fn_27_C2FA8(soNullable* self, int arg1, int arg2, float value) {
    int delta = arg2 - self->slot25(arg1);
    if (delta == 0) {
        return value;
    }

    float result = ((float)0, value * (((float)delta / 100.0f) * self->a + 1.0f));
    if (result <= 0.0f && value > 0.0f) {
        result = self->b;
    }
    if (result > self->c && value < self->c) {
        result = self->c;
    }
    return result;
}
