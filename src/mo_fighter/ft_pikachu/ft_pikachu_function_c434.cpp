#pragma force_active on
extern "C" {
extern const float lbl_98_rodata_8;
void fn_98_C46C(float*, const float*);

void fn_98_C434(float* self) {
    float value = lbl_98_rodata_8;
    float vec[2] = {value, value};
    fn_98_C46C(self + 2, vec);
}
}
