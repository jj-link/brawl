#pragma force_active on
struct Data {
    unsigned char pad[8];
    unsigned int word;
};

extern "C" int fn_27_543C4(const Data* p) {
    return (int)((p->word << 9) & 0xFFC00000u) >> 23;
}
