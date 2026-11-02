#pragma force_active on

typedef unsigned int u32;

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)
#define RG PASTE(r, egister)

typedef struct OSContext {
    u32 gprs[32];
    u32 cr;
    u32 lr;
    u32 ctr;
    u32 xer;
    unsigned long long fprs[32];
    u32 fpscr_pad;
    u32 fpscr;
    u32 srr0;
    u32 srr1;
    unsigned short mode;
    unsigned short state;
    u32 gqrs[8];
    u32 psf_pad;
    unsigned long long psfs[32];
} OSContext;

extern void TRKInterruptHandler(void);

BLOCK void TRKLoadContext(RG OSContext* ctx, RG u32 exception) {
    nofralloc

    lwz r0, ctx->gprs[0]
    lwz r1, ctx->gprs[1]
    lwz r2, ctx->gprs[2]
    lhz r5, ctx->state
    rlwinm. r6, r5, 0, 30, 30
    beq _load_saved_gprs

    rlwinm r5, r5, 0, 31, 29
    sth r5, ctx->state
    lmw r5, ctx->gprs[5]
    b _load_special_regs

_load_saved_gprs:
    lmw r13, ctx->gprs[13]

_load_special_regs:
    mr r31, r3
    mr r3, r4
    lwz r4, 128(r31)
    mtcr r4
    lwz r4, 132(r31)
    mtlr r4
    lwz r4, 136(r31)
    mtctr r4
    lwz r4, 140(r31)
    mtxer r4

    mfmsr r4
    rlwinm r4, r4, 0, 17, 15
    rlwinm r4, r4, 0, 31, 29
    mtmsr r4

    mtsprg 1, r2
    lwz r4, 12(r31)
    mtsprg 2, r4
    lwz r4, 16(r31)
    mtsprg 3, r4

    lwz r2, 408(r31)
    lwz r4, 412(r31)
    lwz r31, 124(r31)
    b TRKInterruptHandler
}
