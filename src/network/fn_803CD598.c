#pragma force_active on
typedef struct Entry {
    unsigned short a;
    unsigned short b;
    unsigned int offset;
} Entry;
typedef struct Context {
    Entry entries[18];
    char pad90[4];
    unsigned int *data;
    char pad98[4];
    unsigned short size;
} Context;
extern Context *fn_803CD2E0(void);
static inline void setEntry(Context *ctx, Entry *e, unsigned int idx) {
    unsigned int *data = ctx->data;
    unsigned short *hdr = (unsigned short *)((char *)data + data[idx]);
    e->a = hdr[0];
    e->b = hdr[1];
    e->offset = data[idx] + 4;
}
static inline void init(Context *ctx) {
    int i;
    Entry *e = ctx->entries;
    ctx->size = ((unsigned short *)ctx->data)[1];
    for (i = 0; i < 18; i++) {
        setEntry(ctx, e, i + 1);
        e++;
    }
}
void fn_803CD598(void) {
    init(fn_803CD2E0());
}
