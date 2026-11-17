#pragma force_active on
extern "C" {
extern const float lbl_805A33BC;
extern const float lbl_805A33C0;
void fn_80162384(float*, float*, float);
void fn_801A97F0(float* m, const float* arg) {
    float spC;
    float sp8;
    float angle = arg[2];
    fn_80162384(&spC, &sp8, lbl_805A33C0 * angle);
    {
        float a;
        float b;
        a = (sp8 * m[0]) - (spC * m[4]);
        b = (spC * m[0]) + (sp8 * m[4]);
        m[0] = a;
        m[4] = b;
    }
    {
        float a = (sp8 * m[1]) - (spC * m[5]);
        float b = (spC * m[1]) + (sp8 * m[5]);
        m[1] = a;
        m[5] = b;
    }
    {
        float a = (sp8 * m[2]) - (spC * m[6]);
        float b = (spC * m[2]) + (sp8 * m[6]);
        m[2] = a;
        m[6] = b;
    }
    {
        float a = spC + ((sp8 * m[3]) - (spC * m[7]));
        float b = lbl_805A33BC + (((spC * m[3]) + (sp8 * m[7])) - sp8);
        m[3] = a;
        m[7] = b;
    }
}
}