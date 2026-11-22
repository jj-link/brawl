#pragma force_active on

extern "C" const float lbl_27_rodata_7C14;
extern "C" const float lbl_27_rodata_7C0C;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(unsigned int, void*);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(unsigned int, unsigned int, float*, float*, float*, float*, unsigned int, unsigned int, float);
};

struct Inner {
    unsigned char pad1[0x70];
    Object_vptr_0* obj70;
    unsigned char pad2[0x14];
    Object_vptr_0* obj88;
};

struct Mid {
    unsigned char pad[0xD8];
    Inner* inner;
};

struct Outer {
    unsigned char pad[0x60];
    Mid* mid;
};

extern "C" void fn_27_380F64(Outer* self, unsigned int arg) {
    if (arg == 1) {
        float value = lbl_27_rodata_7C14;
        float values[12];
        values[0] = value;
        values[1] = value;
        values[2] = value;
        values[3] = value;
        values[4] = value;
        values[5] = value;
        values[6] = value;
        values[7] = value;
        values[8] = value;
        values[9] = value;
        values[10] = value;
        values[11] = value;
        self->mid->inner->obj88->slot8(0x01030039, 0x12E, &values[9], &values[6],
                                       &values[3], &values[0], 0, 0, lbl_27_rodata_7C0C);
    }
    Mid* mid = self->mid;
    mid->inner->obj70->slot3(0x10B, mid);
}
