#pragma force_active on

namespace hkMath {
float max2f(float a, float b) {
    if (a > b) {
        return a;
    }
    return b;
}
}