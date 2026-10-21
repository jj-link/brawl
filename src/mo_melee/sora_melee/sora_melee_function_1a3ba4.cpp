#pragma force_active on
struct Data {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int : 10;
    signed int value : 10;
    unsigned int : 12;
};

extern "C" int fn_27_1A3BA4(const Data* p) {
    return p->value;
}
