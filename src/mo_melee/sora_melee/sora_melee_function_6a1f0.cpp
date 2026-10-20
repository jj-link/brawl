#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_934;

struct FnObj {
    char pad[0x28];
    float f28;
    float f2c;
};

float fn_27_6A1F0(FnObj* p)
{
    float r = lbl_27_rodata_934 * p->f28;
    return r + p->f2c;
}
}
