#pragma force_active on
struct S { char pad[0x51c]; float* arr; };
extern "C" float fn_78_4B98(S* s, unsigned i) {
    return s->arr[i];
}
