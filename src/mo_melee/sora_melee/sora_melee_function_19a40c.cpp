#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 pad : 4;
    u32 field : 2;
    u32 rest : 26;
} BitS;

extern "C" void fn_27_19A40C(BitS* p, u32 v) {
    p->field = v;
}
