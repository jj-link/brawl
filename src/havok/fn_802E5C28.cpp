#pragma force_active on
extern "C" {
extern float lbl_805A43D8;
extern float lbl_805A43DC;
}

extern "C" void fn_802E5C28(float* arg0, float* arg1) {
    float f0;
    float f1;
    float f2;

    f0 = arg1[5];
    f2 = arg1[0];
    f1 = arg1[10];
    f2 = (f2 > f0) ? f2 : f0;
    f2 = (f2 > f1) ? f2 : f1;
    f0 = lbl_805A43DC;
    if (f2 > f0) {
        f0 = lbl_805A43D8 / f2;
    }
    arg0[52] = f0;
    arg0[53] = f0;
    arg0[54] = f0;
}
