#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int value;
};

extern "C" int fn_27_1A6340(const Data* p) {
    return (int)((p->value << 10) & 0xFFE00000u) >> 22;
}
