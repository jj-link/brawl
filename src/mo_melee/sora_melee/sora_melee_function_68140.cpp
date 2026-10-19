#pragma force_active on
extern "C" {
    extern double fn_804005AC(double);
    extern const float lbl_27_rodata_920;
}

extern "C" int fn_27_68140(float a, float b, float c, float d, float e) {
    if (a > lbl_27_rodata_920) {
        float temp = c + a * b;
        temp *= d;
        if (temp > e)
            temp = e;
        return (int)(float)fn_804005AC((double)temp);
    }
    return 0;
}
