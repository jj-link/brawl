#pragma force_active on
extern "C" void mtSinCosf__FfPfPf(float, float*, float*);
extern "C" float lbl_805A1728;

extern "C" void fn_8003ECA0(float* arg0, float farg0, float farg1, float farg2) {
    float sp1C;
    float sp18;
    float sp14;
    float sp10;
    float spC;
    float sp8;

    mtSinCosf__FfPfPf(farg0, &sp1C, &sp10);
    mtSinCosf__FfPfPf(farg1, &sp18, &spC);
    mtSinCosf__FfPfPf(farg2, &sp14, &sp8);
    float zero = lbl_805A1728;
    arg0[0] = spC * sp8;
    arg0[4] = spC * sp14;
    arg0[8] = -sp18;
    arg0[1] = (sp8 * (sp1C * sp18)) - (sp10 * sp14);
    arg0[5] = (sp14 * (sp1C * sp18)) + (sp10 * sp8);
    arg0[9] = sp1C * spC;
    arg0[2] = (sp8 * (sp10 * sp18)) + (sp1C * sp14);
    arg0[6] = (sp14 * (sp10 * sp18)) - (sp1C * sp8);
    arg0[10] = sp10 * spC;
    arg0[3] = zero;
    arg0[7] = zero;
    arg0[11] = zero;
}
