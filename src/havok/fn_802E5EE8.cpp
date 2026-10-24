#pragma force_active on
#pragma fp_contract on

extern "C" void fn_802E5EE8(float* arg0, const float* arg1) {
    arg0[60] = arg0[52] * arg1[0] + arg0[60];
    arg0[61] = arg0[53] * arg1[1] + arg0[61];
    arg0[62] = arg0[54] * arg1[2] + arg0[62];
    arg0[63] = arg0[55] * arg1[3] + arg0[63];
}
