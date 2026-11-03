#include <mt/mt_prng.h>
#pragma force_active on

extern "C" float lbl_27_rodata_CD4;

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_A1E80();
    virtual void fn_27_A1F44();
    virtual void fn_27_A1FBC();
    virtual void fn_27_A1FCC();
    virtual void fn_27_A1FEC();
    virtual void fn_27_A200C();
    virtual void fn_27_A2088();
    virtual void fn_27_A20A8();
    virtual void fn_27_A2160();
    virtual void fn_27_A2180();
    virtual void fn_27_A20C8();
    virtual void fn_27_A21A0();
    virtual void fn_27_A21C0(int, float);
};

extern "C" void fn_27_A21E0(soNullable* self, int arg1, float min, float max) {
    if (max < min) {
        return;
    }
    float value = max;
    if (max == min) {
        value = max;
    } else {
        value = min + ((lbl_27_rodata_CD4 + (max - min)) * randf());
    }
    self->fn_27_A21C0(arg1, value);
}
