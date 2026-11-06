#pragma force_active on
extern "C" const float lbl_27_rodata_B90;
extern "C" float fn_27_896EC(float a, float b, float c, float d) {
    if (c >= lbl_27_rodata_B90 && d > lbl_27_rodata_B90) {
        if (a + b > c) {
            if (lbl_27_rodata_B90 == c)
                b = -d;
            else {
                float n = -d;
                if (b > n)
                    b = n;
            }
            if (a + b < c)
                b = c - a;
        } else if (a + b < -c) {
            if (lbl_27_rodata_B90 == c)
                b = d;
            else if (b < d)
                b = d;
            if (a + b > -c)
                b = -c - a;
        }
        return b;
    }
    return b;
}