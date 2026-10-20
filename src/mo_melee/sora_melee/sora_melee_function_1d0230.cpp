#pragma force_active on
struct Word {
    unsigned int pad0;
    unsigned int pad4;
    union {
        unsigned int raw;
        struct {
            unsigned int hi : 8;
            unsigned int mid : 4;
            unsigned int rest : 20;
        } bits;
    } word8;
};

extern "C" void fn_27_1D0230(Word* arg0, unsigned int arg1) {
    arg0->word8.bits.mid = arg1;
}
