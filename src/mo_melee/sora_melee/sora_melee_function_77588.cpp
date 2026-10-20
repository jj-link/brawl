#pragma force_active on
typedef struct {
    unsigned char a;
    short b;
    short c;
} Rec;

extern "C" void fn_27_77588(Rec* dst, const Rec* src) {
    if (dst == src) {
        return;
    }
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
}
