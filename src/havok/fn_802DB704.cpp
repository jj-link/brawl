#pragma force_active on
#pragma fp_contract on

extern "C" float fn_802DB704(float* arg0) {
    float r = arg0[0]*arg0[0] + arg0[1]*arg0[1];
    r = arg0[2]*arg0[2] + r;
    return arg0[3]*arg0[3] + r;
}
