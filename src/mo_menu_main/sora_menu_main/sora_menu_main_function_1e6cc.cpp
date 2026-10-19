#pragma force_active on
struct FnItem {
    int unk0;
    unsigned int unk4;
};

extern "C" int fn_2_1E6CC(FnItem* a, FnItem* b) {
    int ret = 1;
    if (a->unk4 > b->unk4) {
        ret = -1;
    }
    return ret;
}
