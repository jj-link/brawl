#pragma force_active on
extern "C" {
void fn_801F5500(int, int, int, int);
void fn_801F5484(float, float, float, float, float, float);
void fn_801F55B0(void*, void*);
void fn_801ECF4C(void*, float, float, float, float, float, float);
void fn_801F50EC(void*, int);
void fn_801EC158(void*);
void fn_801F51DC(void*, int);
void fn_801F52E4(int);

extern float lbl_805A19EC;
extern float lbl_805A1A10;
extern float lbl_805A1A1C;
extern float lbl_805A1A20;
}

extern "C" void fn_8006B360() {
    char sp48[0x40];
    char sp8[0x40];

    fn_801F5500(0, 0, 0x280, 0x1E0);
    fn_801F5484(lbl_805A1A10, lbl_805A1A10, lbl_805A1A20,
                lbl_805A1A1C, lbl_805A1A10, lbl_805A19EC);
    fn_801F55B0(0, 0);

    float z = lbl_805A1A10;
    float farZ = lbl_805A19EC;
    fn_801ECF4C(sp48, z, lbl_805A1A1C, z, lbl_805A1A20, z, farZ);

    fn_801F50EC(sp48, 1);
    fn_801EC158(sp8);
    fn_801F51DC(sp8, 0);
    fn_801F52E4(0);
}
