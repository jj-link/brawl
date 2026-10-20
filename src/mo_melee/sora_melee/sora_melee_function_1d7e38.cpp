#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Fn27Data {
    u32 unk0;
    u32 unk4;
    u32 pad : 5;
    s32 field : 5;
    u32 rest : 22;
};

extern "C" s32 fn_27_1D7E38(Fn27Data* p) {
    return p->field;
}
