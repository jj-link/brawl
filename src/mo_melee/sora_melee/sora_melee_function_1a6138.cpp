#pragma force_active on
struct Data {
    unsigned int pad[2];
    signed int : 10;
    signed int value : 10;
};

extern "C" int fn_27_1A6138(const Data* p) {
    return p->value;
}
