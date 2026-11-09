#pragma force_active on

typedef struct {
    int f00;
    int f04;
    int f08;
    int f0C;
    int f10;
    int f14;
    int f18;
    int f1C;
} NetBuffer;

extern int lbl_805A1170;
extern int fn_80398818(void *, int, int);
extern int fn_80398A08(int, int, void *);
extern int fn_80398BD8(int, int, void *);
extern void *memset(void *, int, int);

void fn_8039CCC8(NetBuffer *arg0, void *arg1, int arg2) {
    int base;
    NetBuffer *ctx;

    base = lbl_805A1170 + 0x1800;
    ctx = (NetBuffer *)base;

    switch (fn_80398818(arg1, arg2, 0)) {
    case 0:
        switch (fn_80398A08(base, 0x80, arg1)) {
        case 0:
            arg0->f08--;
            arg0->f10 -= ctx->f08;
            memset(ctx, 0, 0x80);
            ctx->f0C = arg0->f1C;
            arg0->f1C = arg2;

            switch (fn_80398818(arg1, arg2, 0)) {
            case 0:
                fn_80398BD8(base, 0x80, arg1);
                break;
            default:
                return;
            }
            break;
        default:
            return;
        }
        break;
    default:
        return;
    }
}