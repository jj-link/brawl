#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    struct {
        unsigned int hi : 16;
        unsigned int b : 8;
        unsigned int lo : 8;
    } unk8;
};

extern "C" void fn_27_CE0AC(Obj* p, u32 v) {
    p->unk8.b = v;
}
