#pragma force_active on
typedef unsigned int u32;
typedef float f32;

struct SomeStruct {
    char pad[0x188];
    u32 field_188;
    f32 field_18c;
};

extern "C" void fn_77_C04(SomeStruct* obj, u32* out1, f32* out2) {
    *out1 = obj->field_188;
    *out2 = obj->field_18c;
}
