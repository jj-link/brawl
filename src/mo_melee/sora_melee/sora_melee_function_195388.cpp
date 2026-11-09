#pragma force_active on

extern const float lbl_27_rodata_26B0;
extern const float lbl_27_rodata_26C0;

extern "C" float fn_27_195388(float a, float b, float c) {
    float temp_f1;
    float temp_f1_2;

    if (lbl_27_rodata_26B0 == c) {
        return a;
    }

    if (c < lbl_27_rodata_26B0) {
        float factor;
        temp_f1 = -c;

        if (lbl_27_rodata_26B0 == temp_f1) {
            factor = lbl_27_rodata_26C0;
        } else if (temp_f1 < lbl_27_rodata_26B0) {
            temp_f1_2 = -temp_f1;

            if (lbl_27_rodata_26B0 == temp_f1_2) {
                factor = lbl_27_rodata_26C0;
            } else if (temp_f1_2 < lbl_27_rodata_26B0) {
                float value =
                    fn_27_195388(lbl_27_rodata_26C0, b, -temp_f1_2);
                factor = lbl_27_rodata_26C0 / value;
            } else {
                if (b >= lbl_27_rodata_26C0 ||
                    temp_f1_2 <= lbl_27_rodata_26C0) {
                    float difference = b - lbl_27_rodata_26C0;
                    float scaled = difference * lbl_27_rodata_26C0;
                    float negated = -c;
                    float restored = -negated;
                    factor = lbl_27_rodata_26C0 + restored * scaled;
                } else {
                    factor = (lbl_27_rodata_26C0 * b) / temp_f1_2;
                }
            }

            factor = lbl_27_rodata_26C0 / factor;
        } else if (b >= lbl_27_rodata_26C0 ||
                   temp_f1 <= lbl_27_rodata_26C0) {
            c = -c;
            float difference = b - lbl_27_rodata_26C0;
            float scaled = difference * lbl_27_rodata_26C0;
            factor = lbl_27_rodata_26C0 + c * scaled;
        } else {
            factor = (lbl_27_rodata_26C0 * b) / temp_f1;
        }

        return a / factor;
    }

    if (b >= lbl_27_rodata_26C0 || c <= lbl_27_rodata_26C0) {
        float difference = b - lbl_27_rodata_26C0;
        float scaled = difference * a;
        return a + c * scaled;
    }

    return (a * b) / c;
}
