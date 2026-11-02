#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    u32 a;
    u32 b;
} Entry;

typedef struct {
    u32 unk0;
    u32 flags;
    char pad8[0x68 - 0x8];
    Entry entries[2];
    u32 sizes[20];
    char padC8[1];
    u8 count;
} Ctx;

typedef struct {
    char data[0x9c];
} Work;

extern s32 fn_8039A260(void);
extern s32 fn_8039A274(void);
extern s32 fn_8039B9B0(int mode, u32 a, Work* w);
extern s32 fn_8039BA88(Work* w);
extern s32 fn_803A001C(Work* w, Entry* e, s32 a, s32 b, u32* out);

static s32 getMode(const Ctx* c, int* mode) {
    if (c->flags & 0x10) {
        *mode = 0;
    } else if (c->flags & 0x20) {
        *mode = 1;
    } else {
        return -3;
    }
    return 0;
}

static s32 readData(Work* w, const Ctx* c, u32 idx, s32 a, s32 b) {
    u32 size = 0;
    s32 ret = fn_803A001C(w, (Entry*)&c->entries[idx], a, b, &size);
    if (ret == 0 && size != c->sizes[idx]) {
        ret = -24;
    }
    return ret;
}

s32 fn_8039FEB0(Ctx* ctx, u32 idx, s32 arg2, s32 arg3) {
    Work w;
    int mode;
    s32 ret;
    s32 r;

    if (fn_8039A260() == 0 && fn_8039A274() == 0) {
        return -9;
    }
    if (!(ctx->flags & 0x200)) {
        return -7;
    }
    if (idx >= ctx->count) {
        return -13;
    }
    ret = getMode(ctx, &mode);
    if (ret != 0) {
        return ret;
    }
    if (ctx->entries[idx].b == 0 || ctx->sizes[idx] == 0) {
        return -5;
    }
    ret = fn_8039B9B0(mode, ctx->unk0, &w);
    if (ret != 0) {
        return ret;
    }
    ret = readData(&w, ctx, idx, arg2, arg3);
    r = fn_8039BA88(&w);
    if (ret == 0) {
        ret = r;
    }
    return ret;
}
