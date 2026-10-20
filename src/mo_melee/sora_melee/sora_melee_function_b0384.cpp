#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 a : 9;
    u32 b : 9;
    u32 c : 14;
};

extern "C" {
void fn_27_B0384(Obj *obj, u32 val) {
    obj->b = val;
}
}
