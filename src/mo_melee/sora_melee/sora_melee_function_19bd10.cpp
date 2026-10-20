#pragma force_active on
struct BitStruct {
    unsigned int hi : 2;
    unsigned int rest : 30;
};

struct Holder {
    unsigned int unk0;
    unsigned int unk4;
    BitStruct bits;
};

extern "C" {
void fn_27_19BD10(Holder *p, unsigned int v) {
    p->bits.hi = v;
}
}
