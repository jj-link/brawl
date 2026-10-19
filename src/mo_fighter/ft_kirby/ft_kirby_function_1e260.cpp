#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int value;
};

extern "C" int fn_96_1E260(Data* p) {
    return (int)((p->value << 4) & 0xF8000000u) >> 28;
}
