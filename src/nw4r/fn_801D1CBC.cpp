#pragma force_active on
struct Inner { char pad[0x38]; unsigned short type; };
struct Item { Inner* inner; };
struct Context {
    char pad[12]; Item* items[9][4]; int rows; int cols;
    void (*callback)(Context*, int, void*); void* user;
    char pad2; char flagAD; char pad3; char flagAF;
};
extern "C" void* fn_801BB188();
extern "C" void fn_801BB8E0(void*, void*);
extern "C" void fn_802022DC(void*, int);
extern "C" void fn_801D0DA4(void*);
extern "C" void fn_801D1CBC(Item* arg0, int arg1, void* arg2) {
    Context* ctx = (Context*)arg2;
    int mode;
    int retain;
    int i;
    int j;
    Item* item;
    retain = 0;
    switch (arg1) {
    case 0: mode = 1; break;
    case 1: mode = 3; retain = 1; break;
    }
    for (i = 0; i < ctx->rows; i++) {
        for (j = 0; j < ctx->cols; j++) {
            item = ctx->items[i][j];
            if (item) {
                if (item == arg0) {
                    if (!retain) fn_801BB8E0(fn_801BB188(), item);
                } else {
                    Inner* inner = item->inner;
                    int valid = 0;
                    if (inner && inner->type == 1) valid = 1;
                    if (valid) fn_802022DC(inner, 0);
                    fn_801BB8E0(fn_801BB188(), item);
                }
                ctx->items[i][j] = 0;
            }
        }
    }
    ctx->flagAF = 0;
    ctx->flagAD = 0;
    ctx->rows = 0;
    if (retain) fn_801D0DA4(ctx);
    if (ctx->callback) ctx->callback(ctx, mode, ctx->user);
}