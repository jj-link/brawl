#pragma force_active on
struct Pair {
    unsigned int words[2];
};

struct Object {
    unsigned char base[8];
    Pair p0, p1, p2, p3, p4;
    unsigned char b0, b1, b2;
};

extern "C" void fn_113_1E208(void* dst, void* src);

extern "C" Object* fn_113_1E164(Object* dst, Object* src) {
    fn_113_1E208(dst, src);
    dst->p0 = src->p0;
    dst->p1 = src->p1;
    dst->p2 = src->p2;
    dst->p3 = src->p3;
    dst->p4 = src->p4;
    dst->b0 = src->b0;
    dst->b1 = src->b1;
    dst->b2 = src->b2;
    return dst;
}
