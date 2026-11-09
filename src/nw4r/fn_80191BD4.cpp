#pragma force_active on
extern "C" int fn_80191BD4(int* arg0, int arg1, char* arg2, int* arg3, int* arg4, int* arg5, int* arg6, int* arg7) {
    int* p = (int*)(*arg0 + (arg1 & 1) * 0x14);
    int val;
    if ((arg1 & 2) == 0)
        val = p[3];
    else
        val = p[4];
    if (arg2) *arg2 = (val >> 1) & 1;
    if (arg3) *arg3 = (val >> 6) & 1;
    if (arg4) *arg4 = val & 1;
    int lo5 = (val >> 2) & 0xF;
    int hi5 = (val >> 11) & 0xF;
    if (arg5) *arg5 = lo5 | (hi5 << 4);
    int out0, out4;
    if (((val >> 10) & 1) == 0) {
        out4 = 0;
        out0 = 0;
    } else if (((val >> 9) & 1) == 0) {
        out0 = (val >> 7) & 3;
        out4 = 2;
    } else {
        out4 = 1;
        out0 = (val >> 7) & 3;
    }
    if (arg6) *arg6 = out0;
    if (arg7) *arg7 = out4;
    return 1;
}
