#pragma force_active on
typedef int s32;

typedef struct Ctx {
    char pad[0x22c];
    s32 unk22C;
} Ctx;

typedef struct Conn {
    s32 unk0;
    s32 sock;
    void *unk8;
    s32 pad[3];
    void *unk18;
} Conn;

typedef struct Req {
    s32 unk0;
    Conn *unk4;
} Req;

extern void closesocket(s32);
extern void fn_8035C2D8(s32, s32);
extern void fn_8035E00C(void *);

void fn_8036EE44(Ctx **arg0, Req *arg1) {
    Ctx *ctx = *arg0;
    Conn *c;

    if (arg1->unk0 == 3) {
        c = arg1->unk4;
        ctx->unk22C = ctx->unk22C - 1;
        fn_8035C2D8(c->sock, 2);
        closesocket(c->sock);
        fn_8035E00C(c->unk18);
        c->unk18 = 0;
        fn_8035E00C(c->unk8);
        c->unk8 = 0;
    }
    fn_8035E00C(arg1->unk4);
    arg1->unk4 = 0;
    fn_8035E00C(arg1);
}
