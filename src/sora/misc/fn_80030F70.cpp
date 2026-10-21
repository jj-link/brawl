#pragma force_active on
extern "C" int fn_8003304C(int a, int b, int c, int d);

extern "C" int fn_80030F70(int a, int b, int c) {
    if (c != 0 && (unsigned int)c > 0x33) {
        return 0;
    }
    return fn_8003304C(a, b, 1, c);
}
