#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int : 4;
    signed int field : 2;
};

extern "C" int fn_27_19BF1C(const Data* p) {
    return p->field;
}
