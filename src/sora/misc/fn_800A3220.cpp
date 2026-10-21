#pragma force_active on
extern "C" void fn_800A3220(float* p, float x, float y) {
    p[13] = x;
    p[12] = p[12] + y * (x - p[12]);
}
