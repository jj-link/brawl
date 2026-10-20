#pragma force_active on
typedef unsigned int u32;

struct fn_27_19FA20_Obj {
    u32 unk0;
    u32 unk4;
    struct {
        u32 a : 5;
        u32 b : 5;
        u32 c : 22;
    } unk8;
};

extern "C" {
void fn_27_19FA20(fn_27_19FA20_Obj* p, u32 v) {
    p->unk8.b = v;
}
}
