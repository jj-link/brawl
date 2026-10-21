#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int : 4;
    signed int value : 4;
};

extern "C" int fn_27_1997A8(const Data* p) {
    return p->value;
}
