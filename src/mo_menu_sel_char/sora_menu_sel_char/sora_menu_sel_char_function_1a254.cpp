#pragma force_active on

struct RO {
    float high;
    float low;
    unsigned char pad[0x40];
    float step;
};

extern "C" const RO lbl_10_rodata_7D0;

struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void setValue(int, float);
    virtual float getValue(int);
};

struct Object {
    unsigned char pad[0x7c];
    VObj* values;
    int selected;
};

extern "C" void fn_10_1A254(Object* self) {
    const RO* r = &lbl_10_rodata_7D0;
    int i = 0;
    do {
        float value = self->values->getValue(i);
        if (i == self->selected) {
            if (value < r->high) {
                value += r->step;
                if (value > r->high) {
                    value = r->high;
                }
            }
        } else if (value > r->low) {
            value -= r->step;
            if (value < r->low) {
                value = r->low;
            }
        }
        self->values->setValue(i, value);
        ++i;
    } while (i < 11);
}
