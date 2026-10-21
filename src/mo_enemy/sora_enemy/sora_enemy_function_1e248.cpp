#pragma force_active on
struct Data {
    unsigned char pad0[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char pad6[0x32];
    int field38;
    unsigned char pad3c[0x28];
    unsigned char field64;
    bool isFlag() const { return flag; }
    void clearFlag() { flag = 0; }
};

extern "C" bool fn_41_1AE7C(void*);

extern "C" void fn_41_1E248(Data* p) {
    if (fn_41_1AE7C(p) == 1) return;
    if (!p->isFlag()) return;
    if (p->field64 != 1) return;
    switch (p->field38) {
    case 0:
        break;
    default:
        return;
    }
    p->clearFlag();
}
