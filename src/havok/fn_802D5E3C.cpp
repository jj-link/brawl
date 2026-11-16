#pragma force_active on
extern float lbl_805A4160;
inline void fill(int count, float* p, float z) {
    while (count-- >= 0) {
        p[3] = z;
        p[2] = z;
        p[1] = z;
        p[0] = z;
        p += 4;
    }
}
extern "C" void fn_802D5E3C(int a, int b, int count, float* p) {
    float z = lbl_805A4160;
    fill(count - 1, p, z);
}