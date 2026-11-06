#pragma force_active on
extern "C" int fn_800E1D78(int, void*);
extern "C" int fn_800E1E28(int, void*);

extern "C" int fn_800DCCBC(char* self, int idx1, int idx2) {
    int sp8;
    if (fn_800E1E28(*(int*)(self + (idx1 << 2) + 0x4c), &sp8) == 0) {
        return 0;
    }
    fn_800E1D78(*(int*)(self + (idx2 << 2) + 0x4c), &sp8);
    return 1;
}
