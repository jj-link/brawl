#pragma force_active on
typedef unsigned int u32;

struct BitStruct {
    u32 unk0;
    u32 unk4;
    u32 field5 : 5;
    u32 rest : 27;
};

extern "C" void fn_27_19DF7C(BitStruct* p, u32 v) {
    p->field5 = v;
}
