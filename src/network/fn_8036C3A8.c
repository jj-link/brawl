#pragma force_active on
typedef int s32;

typedef struct Node {
    char pad[0x40];
    struct Node *next;
} Node;

typedef struct Ctx {
    char pad0[0x198];
    s32 unk198;
    s32 unk19C;
    s32 unk1A0;
    char pad1[0x4C];
    s32 unk1F0;
    s32 unk1F4;
    void *unk1F8;
    char pad2[0xC];
    void *unk208;
    char pad3[0x4];
    void *unk210;
    char pad4[0xC];
    s32 unk220;
    char pad5[0x21C];
    void *unk440;
    char pad6[0xC];
    Node *unk450;
    char pad7[0x8];
    void *unk45C;
    char pad8[0xC];
    void *unk46C;
} Ctx;

extern void closesocket(s32);
extern void fn_8035C2D8(s32, s32);
extern void fn_8035E00C(void *);
extern void fn_8036A328(void **, void *, void *);
extern void fn_8036A384(void **, void *, s32);
extern s32 fn_8036A81C(void **, s32, void *, s32 *, s32, void *);
extern void fn_8036EEE4(void **, void *);
extern void fn_8036F974(void **, void *);
extern s32 fn_80370A78(void **, void (*)(void), s32);
extern void fn_8036C2B8(void);
extern char lbl_8048F1AC[];
extern char lbl_8059F6F8[8];
extern char lbl_8059F740[3];

void fn_8036C3A8(void **arg0, s32 arg1) {
    Ctx *ctx;
    s32 sp8;
    Node *node;
    void *node440;

    ctx = *arg0;
    if (ctx->unk1F4 != 4) {
        if (ctx->unk1F4 != 0) {
            if (arg1 != 0 && ctx->unk1F4 == 3) {
                fn_8036A328(arg0, &ctx->unk210, lbl_8048F1AC);
                fn_8036A384(arg0, &ctx->unk210, ctx->unk198);
                fn_8036A328(arg0, &ctx->unk210, lbl_8059F6F8);
            }
            fn_8036A81C(arg0, ctx->unk1F0, &ctx->unk210, &sp8, 1, lbl_8059F740);
            if (ctx->unk1F0 != -1) {
                fn_8035C2D8(ctx->unk1F0, 2);
                closesocket(ctx->unk1F0);
                ctx->unk1F0 = -1;
            }
            if (ctx->unk220 != -1) {
                fn_8035C2D8(ctx->unk220, 2);
                closesocket(ctx->unk220);
                ctx->unk220 = -1;
            }
            ctx->unk1F4 = 4;
            ctx->unk19C = 0;
            ctx->unk1A0 = 0;
        }
        fn_8035E00C(ctx->unk1F8);
        ctx->unk1F8 = 0;
        fn_8035E00C(ctx->unk208);
        ctx->unk208 = 0;
        fn_8035E00C(ctx->unk210);
        ctx->unk210 = 0;
        fn_8035E00C(ctx->unk45C);
        ctx->unk45C = 0;
        fn_8035E00C(ctx->unk46C);
        ctx->unk46C = 0;
        while ((node440 = ctx->unk440) != 0) {
            fn_8036EEE4(arg0, node440);
        }
        ctx->unk440 = 0;
        node = ctx->unk450;
        while (node != 0) {
            Node *cur = node;
            node = node->next;
            fn_8036F974(arg0, cur);
        }
        ctx->unk450 = 0;
        do {
        } while (fn_80370A78(arg0, fn_8036C2B8, 0) == 0);
    }
}
