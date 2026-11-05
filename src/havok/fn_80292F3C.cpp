#pragma force_active on

struct Block {
    float v[8];
};

struct Context {
    int unk0;
    int count;
    char pad8[0x18];
    char* matrices;
    char pad24[8];
    Block* values;
};

extern const float lbl_805A3E00;
extern "C" void fn_802843A8(Block*, const void*, const Block*);

extern "C" void fn_80292F3C(Context* ctx, Block* out)
{
    Block tmp __attribute__((aligned(16)));
    int m, v;
    Block* base = out + 1;
    int i;

    base[-1].v[0] = base[-1].v[1] = base[-1].v[2] = base[-1].v[3] = lbl_805A3E00;
    base[-1].v[4] = base[-1].v[5] = base[-1].v[6] = base[-1].v[7] = lbl_805A3E00;

    for (i = 0, m = 0, v = 0; i < ctx->count;
         m += 0x3c0, v += 0x20, ++i) {
        const Block* p = (const Block*)((const char*)ctx->values + v);
        fn_802843A8(&tmp, ctx->matrices + m, base + (i - 1));

        const void* matrix = ctx->matrices + m + 0xc0;
        tmp.v[0] = p->v[0] - tmp.v[0];
        tmp.v[1] = p->v[1] - tmp.v[1];
        tmp.v[2] = p->v[2] - tmp.v[2];
        tmp.v[3] = p->v[3] - tmp.v[3];
        tmp.v[4] = p->v[4] - tmp.v[4];
        tmp.v[5] = p->v[5] - tmp.v[5];
        tmp.v[6] = p->v[6] - tmp.v[6];
        tmp.v[7] = p->v[7] - tmp.v[7];

        fn_802843A8((Block*)((char*)base + v), matrix, &tmp);
    }
}
