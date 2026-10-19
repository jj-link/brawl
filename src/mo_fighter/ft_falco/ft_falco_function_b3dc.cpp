#pragma force_active on
typedef unsigned int u32;

struct FalcoBuf24 {
    u32 a;
    u32 b;
    u32 c;
};

struct FalcoSelf {
    u32 header;
    FalcoBuf24 buf;
};

extern "C" void fn_108_B430(FalcoBuf24* ret, void* a, void* b);

extern "C" FalcoBuf24* fn_108_B3DC(FalcoSelf* self, void* other) {
    FalcoBuf24 tmp;
    fn_108_B430(&tmp, self, other);
    self->buf.a = tmp.a;
    self->buf.b = tmp.b;
    self->buf.c = tmp.c;
    return &self->buf;
}
