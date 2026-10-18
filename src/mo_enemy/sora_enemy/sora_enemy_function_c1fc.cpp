#pragma force_active on
extern "C" {
struct FnC1FCObj {
    char pad[0x14];
    float *values;
};

void fn_41_C1FC(FnC1FCObj *obj, int idx, float val) {
    float *p = obj->values;
    p[idx] += val;
}
}
