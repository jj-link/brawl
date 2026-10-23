#pragma force_active on

extern "C" float fn_8031EA40(int*);

extern "C" void fn_8031EA8C(int arg0, float* arg1, float farg0, float farg1) {
    int sp8 = arg0;
    arg1[0] = (farg1 - farg0) * (farg0 + fn_8031EA40(&sp8));
    arg1[1] = (farg1 - farg0) * (farg0 + fn_8031EA40(&sp8));
    arg1[2] = (farg1 - farg0) * (farg0 + fn_8031EA40(&sp8));
}
