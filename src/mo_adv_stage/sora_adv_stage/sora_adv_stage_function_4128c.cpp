#pragma force_active on
struct Data {
    unsigned int w[6];
    float a, b, c, d, e, f;
    unsigned char bytes[9];
    unsigned int end;
};
extern "C" void fn_40_4128C(Data* dst, const Data* src) {
    *dst = *src;
}