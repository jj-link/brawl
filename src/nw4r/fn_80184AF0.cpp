#pragma force_active on
struct Col { unsigned char r, g, b, a; };
struct Col16 { short r, g, b, a; };
static inline short cl(short x) {
    return x < 0 ? 0 : (x > 255 ? 255 : x);
}
extern "C" void fn_80184AF0(Col* out, const Col16& in) {
    Col c = { cl(in.r), cl(in.g), cl(in.b), cl(in.a) };
    *(int*)out = *(int*)&c;
}
