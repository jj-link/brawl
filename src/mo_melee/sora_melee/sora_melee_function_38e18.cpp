#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 a : 8;
    u32 b : 4;
    u32 c : 20;
} fn_27_38E18_obj;

extern "C" void fn_27_38E18(fn_27_38E18_obj* p, u32 v) {
    p->b = v;
}
