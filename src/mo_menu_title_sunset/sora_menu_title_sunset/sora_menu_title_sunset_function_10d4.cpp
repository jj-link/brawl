#pragma force_active on
extern "C" char lbl_25_data_278[];

struct SunsetLayout {
    float x, y, z, w;
    char* ptr;
    unsigned char pad[0x20];
    float a, b, c, d;
};

extern "C" void fn_25_10D4(SunsetLayout* dst, SunsetLayout* src) {
    dst->ptr = lbl_25_data_278;
    dst->x = src->a;
    dst->y = src->b;
    dst->z = src->c;
    dst->w = src->d;
}
