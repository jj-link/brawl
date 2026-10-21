#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int word;
};

extern "C" int fn_27_1A7290(const Data* p) {
    return (int)((p->word << 4) & 0xF8000000u) >> 28;
}
