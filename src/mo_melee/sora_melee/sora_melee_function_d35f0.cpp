#pragma force_active on
typedef unsigned int u32;

struct BitStruct {
    u32 unk0;
    u32 unk4;
    u32 field : 5;
    u32 rest : 27;
};

extern "C" void fn_27_D35F0(BitStruct* p, u32 v) {
    p->field = v;
}
