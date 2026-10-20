#pragma force_active on
typedef unsigned int u32;

struct Obj385CD4 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
void fn_27_385CD4(Obj385CD4* p) {
    p->unk8 &= 0xFFBFFFFF;
}
}
