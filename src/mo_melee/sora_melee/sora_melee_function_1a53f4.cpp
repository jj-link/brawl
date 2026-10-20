#pragma force_active on
typedef unsigned int u32;

struct fn_27_1A53F4_obj {
    u32 unk0;
    u32 unk4;
    u32 mode : 3;
    u32 rest : 29;
};

extern "C" void fn_27_1A53F4(fn_27_1A53F4_obj* p, u32 v) {
    p->mode = v;
}
