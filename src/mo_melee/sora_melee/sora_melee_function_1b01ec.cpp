#pragma force_active on
typedef int s32;

struct Obj {
    char pad[8];
    s32 field;
};

extern "C" void* fn_27_1B01EC(Obj* self, s32 idx) {
    s32 t = self->field >> 28;
    s32 sum = t + idx;
    idx = (sum >= 6) ? sum - 6 : sum;
    return (char*)self + (idx << 4) + 0xc;
}
