#pragma force_active on
typedef unsigned int u32;
struct Data {
    int kind;
    float vector[3];
    float value;
    u32 field14 : 9;
    u32 pad14 : 23;
    u32 pad18a : 8;
    u32 special : 1;
    u32 pad18b : 17;
    u32 flag : 1;
    u32 pad18c : 5;
};
extern "C" float lbl_27_rodata_520;
extern "C" void fn_27_55E8C(void*, void*, bool, u32, u32, float*, float, float);
extern "C" void fn_27_4DBA8(Data* self, void* a, void* b, float value) {
    if (self->kind != 0) {
        value = self->special == 0 ? value : lbl_27_rodata_520;
        fn_27_55E8C(a, b, self->kind == 1, self->flag, self->field14, self->vector, self->value, value);
    }
}
