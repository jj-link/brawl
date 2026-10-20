#pragma force_active on
struct sfn_27_199660 {
    int unk0;
    int unk4;
    unsigned : 9;
    unsigned f : 1;
};

extern "C" int fn_27_199660(const struct sfn_27_199660* p) {
    return p->f;
}
