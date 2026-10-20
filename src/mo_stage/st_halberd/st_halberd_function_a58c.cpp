#pragma force_active on
struct S { char pad[0x5ac]; float* p; };
extern "C" float fn_57_A58C(S* s, int i) {
    return s->p[i];
}
