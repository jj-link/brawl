#pragma force_active on
typedef unsigned int u32;

struct FnStruct {
    u32 unk0;
    u32 unk4;
    u32 flag : 7;
    u32 rest : 25;
};

extern "C" {
void fn_27_14F310(FnStruct* p, u32 v) {
    p->flag = v;
}
}
