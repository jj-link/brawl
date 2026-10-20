#pragma force_active on
typedef unsigned int u32;

struct fn_27_19F8EC_obj {
    u32 unk0;
    u32 unk4;
    u32 a : 8;
    u32 b : 4;
    u32 c : 20;
};

extern "C" {
void fn_27_19F8EC(fn_27_19F8EC_obj* p, u32 v) {
    p->b = v;
}
}
