#pragma force_active on
extern "C" float rsqrtf__Ff(float);

extern "C" void fn_8003DBA8(float* v) {
    float inv = rsqrtf__Ff(v[0] * v[0] + v[1] * v[1]);
    v[0] = v[0] * inv;
    v[1] = v[1] * inv;
}
