#pragma force_active on
struct S { char pad[20]; float* floats; };

extern "C" float fn_116_A8C4(const S* s, int index) {
    const float* p = s->floats;
    return p[index];
}
