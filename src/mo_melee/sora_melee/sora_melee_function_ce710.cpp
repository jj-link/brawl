#pragma force_active on
typedef unsigned int u32;

struct FlagHolder {
    u32 unk0;
    u32 unk4;
    u32 pad : 18;
    u32 field : 9;
    u32 rest : 5;
};

extern "C" {
void fn_27_CE710(FlagHolder* p, u32 v) {
    p->field = v;
}
}
