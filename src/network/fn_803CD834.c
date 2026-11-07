#pragma force_active on
typedef struct Data {
    char pad[2];
    unsigned short size;
    int value;
} Data;
typedef struct Context {
    char pad[0x9c];
    unsigned short size;
    char pad9e[2];
    Data *data;
    void *buffer;
    unsigned char flag;
} Context;
extern Context *fn_803CD2E0(void);
extern int fn_803CD32C(void);
extern void *fn_803CD284(int);
extern void fn_803CD298(void *);
extern void fn_803CD410(int);
extern void fn_803CD710(void);
extern void fn_803CD830(void);
extern int fn_803CF870(int, void *, int, void *, int);
extern void fn_803CFBE4(int, void *);
void fn_803CD834(void) {
    Context *ctx = fn_803CD2E0();
    int error = 0;
    Data *data;
    int result;
    if (fn_803CD32C() == 0) {
        data = ctx->data;
        ctx->size = data->size;
        ctx->buffer = fn_803CD284(0x20);
        ctx->flag = 0;
        result = fn_803CF870(1, ctx->buffer, 0x20, (void *)fn_803CD710, data->value);
        if (result != 6 && (result >= 6 || result != 0)) {
            error = 1;
        }
    } else {
        error = 1;
        fn_803CD410(2);
    }
    if (error != 0) {
        fn_803CD298(ctx->data);
        ctx->data = 0;
        if (ctx->buffer != 0) {
            fn_803CD298(ctx->buffer);
            ctx->buffer = 0;
        }
        fn_803CFBE4(1, (void *)fn_803CD830);
    }
}