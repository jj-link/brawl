#pragma force_active on
typedef unsigned int u32;

struct fn_27_19E8BC_Obj {
    u32 unk0;
    u32 unk4;
    struct {
        u32 hi : 5;
        u32 mid : 5;
        u32 lo : 22;
    } flags;
};

extern "C" {
void fn_27_19E8BC(fn_27_19E8BC_Obj* obj, u32 value) {
    obj->flags.mid = value;
}
}
