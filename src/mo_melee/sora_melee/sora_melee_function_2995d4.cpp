#include <types.h>
#include <math.h>

#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_2A00EC();
    virtual void fn_27_281B1C();
    virtual void fn_27_2839BC();
    virtual void fn_27_284EA0();
    virtual void fn_27_289454();
    virtual void fn_27_2995D4();
    virtual void fn_27_28A178();
    virtual void fn_27_28A1C4();
    virtual void fn_27_28A4F4();
    virtual void fn_27_289518();
    virtual void fn_27_289560();
    virtual float fn_27_28903C(unsigned long id);
    virtual void fn_27_287730(unsigned long id, float v);
    virtual void fn_27_28B33C();
    virtual void fn_27_28BBA0();
    virtual void fn_27_28BDA8();
    virtual void fn_27_28C004();
    virtual void fn_27_2905E8();
    virtual void fn_27_28C0E0();
    virtual void fn_27_28871C();
    virtual void fn_27_2886CC();
    virtual void fn_27_288700();
    virtual void fn_27_288610();
    virtual void fn_27_28F610(unsigned long z, float* p);
    virtual float fn_27_28F638();
};

class Pad8 {
public:
    int pad_a;
    int pad_b;
};

class soNullableAt8 : public Pad8 {
public:
    virtual void isNull();
    virtual void fn_27_2A00EC();
    virtual void fn_27_281B1C();
    virtual void fn_27_2839BC();
    virtual void fn_27_284EA0();
    virtual void fn_27_289454();
    virtual void fn_27_2995D4();
    virtual void fn_27_28A178();
    virtual void fn_27_28A1C4();
    virtual void fn_27_28A4F4();
    virtual void fn_27_289518();
    virtual void fn_27_289560();
    virtual float fn_27_28903C(unsigned long id);
    virtual void fn_27_287730(unsigned long id, float v);
    virtual void fn_27_28B33C();
    virtual void fn_27_28BBA0();
    virtual void fn_27_28BDA8();
    virtual void fn_27_28C004();
    virtual void fn_27_2905E8();
    virtual void fn_27_28C0E0();
    virtual void fn_27_28871C();
    virtual void fn_27_2886CC();
    virtual void fn_27_288700();
    virtual void fn_27_288610();
    virtual void fn_27_28F610(unsigned long z, float* p);
    virtual float fn_27_28F638();
};

extern "C" {
float getParamFloat__8BaseItemFUl(void*, unsigned long);
extern float lbl_27_rodata_4704;
extern float lbl_27_rodata_4708;
}

extern "C" s32 fn_27_2995D4(void* self, char* item) {
    soNullable* n = *(soNullable**)(*(char**)(*(char**)(item + 0x60) + 0xd8) + 0x64);
    float val = n->fn_27_28903C(0x11000000);
    val += lbl_27_rodata_4704 * (float)fabs(getParamFloat__8BaseItemFUl(item, 0x3ef));
    float maxv = getParamFloat__8BaseItemFUl(item, 0x186a);
    if (val > maxv) {
        val = maxv;
    } else if (val < lbl_27_rodata_4708) {
        val = lbl_27_rodata_4708;
    }
    float arr[3];
    soNullable* c = *(soNullable**)(*(char**)(*(char**)(item + 0x60) + 0xd8) + 0xc);
    float t = c->fn_27_28F638();
    arr[0] = val;
    arr[1] = t;
    arr[2] = val;
    soNullableAt8* d = *(soNullableAt8**)(*(char**)(*(char**)(item + 0x60) + 0xd8) + 0x4);
    d->fn_27_28F610(0, arr);
    n->fn_27_287730(0x11000000, val);
    return 1;
}
