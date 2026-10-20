#pragma force_active on
typedef unsigned int u32;

struct FooBits {
    u32 unk0;
    u32 unk4;
    u32 top : 5;
    u32 rest : 27;
};

extern "C" {
void fn_27_19D8A4(FooBits* p, u32 v) {
    p->top = v;
}
}
