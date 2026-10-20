#pragma force_active on
extern float lbl_27_rodata_32E4;
extern float lbl_27_rodata_32D0;

struct A {
    char pad[0x1C];
    float value;
};

struct B {
    char pad[0x6C];
    float value;
};

extern "C" float fn_27_21F434(A* a, B* b)
{
    return a->value * (lbl_27_rodata_32D0 + lbl_27_rodata_32E4 * b->value);
}
