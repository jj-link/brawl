#pragma force_active on
struct A { char pad[0x20]; float value; };
struct B { char pad[0x6c]; float value; };

extern float lbl_27_rodata_32E4;
extern float lbl_27_rodata_32D0;

extern "C" float fn_27_21F45C(A* a, B* b) {
    return a->value * (lbl_27_rodata_32D0 + lbl_27_rodata_32E4 * b->value);
}
