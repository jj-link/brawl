#pragma force_active on
extern "C" {
void fn_802DB804(float* a, const float* b) {
    a[0] = a[0] - b[0];
    a[1] = a[1] - b[1];
    a[2] = a[2] - b[2];
    a[3] = a[3] - b[3];
}
}
