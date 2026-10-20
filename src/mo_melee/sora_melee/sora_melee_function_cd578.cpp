#pragma force_active on
struct Unk {
    int unk0;
    int unk4;
    int flags;
};

extern "C" int fn_27_CD578(Unk* p) {
    return (p->flags >> 25) & 1;
}
