#pragma force_active on
typedef unsigned int u32;

struct FnObj27 {
    u32 pad0;
    u32 pad4;
    u32 a : 5;
    u32 field : 5;
    u32 rest : 22;
};

extern "C" {
void fn_27_1CF6EC(FnObj27* obj, u32 value) {
    obj->field = value;
}
}
