#pragma force_active on
extern const float lbl_805A3758;
extern const float lbl_805A375C;
extern const float lbl_805A3768;

void fn_801ECCE8(float *arg0, float farg0, float farg1, float farg2, float farg3, float farg4, float farg5, float farg6, float farg7)
{
    float temp_f11;
    float temp_f12;
    float t;

    temp_f12 = lbl_805A3758 / (farg3 - farg2);
    arg0[1] = lbl_805A375C;
    arg0[2] = lbl_805A375C;
    arg0[4] = lbl_805A375C;
    arg0[6] = lbl_805A375C;
    arg0[8] = lbl_805A375C;
    temp_f11 = lbl_805A3758 / (farg0 - farg1);
    arg0[9] = lbl_805A375C;
    arg0[10] = lbl_805A375C;
    arg0[11] = lbl_805A3758;
    t = lbl_805A3768 * temp_f12;
    arg0[0] = t * farg4;
    arg0[3] = farg6 + (farg4 * (temp_f12 * -(farg3 + farg2)));
    arg0[5] = lbl_805A3768 * temp_f11;
    arg0[5] *= farg5;
    arg0[7] = farg7 + (farg5 * (temp_f11 * -(farg0 + farg1)));
}
