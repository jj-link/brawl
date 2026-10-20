#pragma force_active on
struct Data {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int : 4;
    signed int value : 4;
};

extern "C" int fn_63_B1C8(const Data* p) {
    return p->value;
}
