#pragma force_active on
extern "C" float fn_100_132D4(void* self) {
    float* p = static_cast<float*>(self);
    return p[2] * p[3];
}
