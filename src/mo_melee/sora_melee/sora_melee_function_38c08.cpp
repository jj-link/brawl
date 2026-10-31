#pragma force_active on
typedef unsigned int u32;
struct State {
    int kind;
    u32 unk4;
    float data[3];
    float scale;
    unsigned char pad18[0x1C];
    u32 flags34;
    u32 flags38;
    u32 unk3c;
    u32 flags40;
};
extern "C" float lbl_27_rodata_490;
extern "C" void fn_27_55E8C(void*, void*, bool, u32, u32, void*, float, float);
inline float choose(State* self, float value) {
    if (((self->flags38 >> 22) & 1) == 0) return value;
    return lbl_27_rodata_490;
}
extern "C" void fn_27_38C08(State* self, void* a, void* b, float value) {
    if (self->kind != 0) {
    value = choose(self, value);
    fn_27_55E8C(a, b, self->kind == 1, self->flags40 >> 31,
                  self->flags34 >> 23, self->data, self->scale, value);
    }
}