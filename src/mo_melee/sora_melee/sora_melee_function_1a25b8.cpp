#pragma force_active on
typedef unsigned int u32;

struct fn_27_1A25B8_obj {
    u32 unk0;
    u32 unk4;
    u32 a : 5;
    u32 f : 5;
    u32 b : 22;
};

extern "C" void fn_27_1A25B8(fn_27_1A25B8_obj* obj, u32 value) {
    obj->f = value;
}
