#pragma force_active on
extern "C" int fn_800418D0(float* arg0, float* arg1) {
    int result = 0;
    if (!(arg0[2] < arg1[0]) && !(arg0[0] > arg1[0]) && !(arg0[3] < arg1[1]) && !(arg0[1] > arg1[1])) {
        result = 1;
    }
    return result;
}
