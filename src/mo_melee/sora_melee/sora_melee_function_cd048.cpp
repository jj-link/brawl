#pragma force_active on
extern "C" {
struct _fn27 {
    unsigned unk0;
    unsigned unk4;
    unsigned unk8;
};
int fn_27_CD048(const _fn27* p) {
    return (p->unk8 >> 22) & 1;
}
}
