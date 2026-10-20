#pragma force_active on
typedef unsigned int u32;

struct FnObj {
    u32 unk0;
    u32 unk4;
    struct {
        u32 a : 10;
        u32 b : 5;
        u32 c : 17;
    } flags;
};

extern "C" void fn_27_199B4C(FnObj* obj, u32 v) {
    obj->flags.b = v;
}
