#pragma force_active on
struct Unk1A67B4_1 {
    int _0;
    int _4;
    unsigned _8 : 20;
    signed _20 : 10;
    unsigned _30 : 2;
};

extern "C" int fn_27_1A67B4(Unk1A67B4_1* p) {
    return p->_20;
}
