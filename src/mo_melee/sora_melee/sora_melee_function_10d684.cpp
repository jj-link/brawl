#pragma force_active on
struct State {
    unsigned char pad[0x78];
    int count;
    unsigned char enabled;
};
struct itManager {};
extern "C" itManager* lbl_27_bss_6A34;
extern "C" itManager* getInstance__9itManagerFv();
extern "C" unsigned int fn_27_2A5BB4(void*, int, int);
extern "C" int fn_27_2A3EC8(void*, int);
extern "C" bool fn_27_10D684(State* __restrict self, unsigned int kind) {
    if (!self->enabled) return 0;
    if (lbl_27_bss_6A34) {
        if (fn_27_2A5BB4(getInstance__9itManagerFv(), -1, 1) == 1) return 0;
        if (fn_27_2A3EC8(getInstance__9itManagerFv(), 0x37) == 0) return 0;
    }
    if (kind == 1 && self->count > 0) return 0;
    return 1;
}
