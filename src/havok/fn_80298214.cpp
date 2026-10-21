#pragma force_active on
extern "C" char* fn_80298214(void* arg0, char* arg1) {
    int n = ((int*)arg0)[2];
    int t = n * 4 - n;
    return arg1 + t * 0x30 + (t << 5) + n * 0x3C0 + ((n + 1) << 5);
}
