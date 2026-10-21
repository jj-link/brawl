#pragma force_active on
extern "C" {
void fn_802F7DF0(int* arg0, int* arg1) {
    int temp_r5;
    temp_r5 = arg0[0];
    arg0[0] = arg1[0];
    arg1[0] = temp_r5;
    temp_r5 = arg0[1];
    arg0[1] = arg1[1];
    arg1[1] = temp_r5;
    temp_r5 = arg0[2];
    arg0[2] = arg1[2];
    arg1[2] = temp_r5;
}
}
