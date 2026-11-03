#pragma force_active on
extern "C" int fn_8006CF54(void* p, int* out, void* ctx, int flag);
extern "C" int fn_803F6150(const void* lhs, const void* rhs, unsigned long n);
extern "C" char lbl_8059DB10;
extern "C" char lbl_8059DB14;

struct Ctx {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    unsigned char pad14[4];
    unsigned char f18[4];
    unsigned char f1C;
    unsigned char f1D;
    unsigned char pad1E[0x4C - 0x1E];
    int f4C;
    unsigned char* f50;
};

extern "C" unsigned char* fn_8006A76C(unsigned char* self, unsigned char* script) {
    Ctx* ctx;
    int var;
    unsigned char* pc;
    int sp8;
    unsigned char c;

    var = 0;
    pc = script;
    ctx = *(Ctx**)(self + 0x1d0);

    *(ctx->f50 + ctx->f4C) = 1;

    for (;;) {
        c = *pc;
        if (c >= 0x20) {
            break;
        }
        switch (c) {
        case 0:
            var = ctx->f4;
            pc++;
            break;
        case 1:
            ctx->f1D = 1;
            return pc;
        case 23:
            pc += 9;
            continue;
        case 24:
            pc += 3;
            continue;
        case 26:
            pc += 2;
            continue;
        case 25:
            pc += 6;
            continue;
        case 5:
            pc += 2;
            continue;
        }
        break;
    }

    pc += fn_8006CF54(pc, &sp8, ctx->f18, 0);

    switch (sp8) {
    case 0:
        var = 0;
        break;
    case 1:
        ctx->f1C = 1;
        if (fn_803F6150(ctx->f18, &lbl_8059DB10, 3) == 0) {
            var = ctx->f8;
        } else if (fn_803F6150(ctx->f18, &lbl_8059DB14, 4) == 0) {
            var = ctx->fC;
        } else {
            var = ctx->f0;
        }
        break;
    case 2:
        var = ctx->f4;
        break;
    case 5:
        var = 0;
        break;
    }

    ctx->f10 += var * 0x3c;
    return pc;
}
