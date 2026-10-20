#pragma force_active on
struct FnObj27 {
    int pad0;
    int pad1;
    int field8;
    int fieldC;
    unsigned char field10;
};

extern "C" bool fn_27_25E08C(FnObj27* p) {
    if (p->field10 != 0) {
        p->field8 = 7;
        p->fieldC = 4;
        return true;
    }
    return false;
}
