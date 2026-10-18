#pragma force_active on
struct Unk {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" bool fn_41_1AE7C(Unk* p) {
    return p->unk8 == -1;
}
