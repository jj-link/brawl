#pragma force_active on
extern "C" char* fn_76_3D70(char* p, int n) {
    int k = (*(int*)(p + 8) >> 27) + n;
    if (k >= 9) {
        k = k - 9;
    }
    return p + k * 0xA0 + 0xC;
}
