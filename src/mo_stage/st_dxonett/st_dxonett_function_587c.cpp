#pragma force_active on
extern "C" char* fn_78_587C(int* p, int index) {
    int v = (p[2] >> 28) + index;
    if (v >= 7) {
        v -= 7;
    }
    return (char*)p + v * 8 + 12;
}
