#pragma force_active on
typedef unsigned char u8;

extern float lbl_27_rodata_EA8;

struct fn_27_C1140_Obj {
    char pad[0x24];
    float f0;
    float f1;
    float f2;
    float f3;
    u8 b0;
    u8 b1;
};

extern "C" void fn_27_C1140(fn_27_C1140_Obj* obj) {
    float v = lbl_27_rodata_EA8;
    obj->b0 = 0;
    obj->b1 = 0;
    obj->f0 = v;
    obj->f1 = v;
    obj->f2 = v;
    obj->f3 = v;
}
