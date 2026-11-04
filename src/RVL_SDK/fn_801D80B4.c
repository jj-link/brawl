#include <types.h>
#include <revolution/OS/OSContext.h>
#include <revolution/OS/OSInterrupt.h>

#pragma force_active on

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)
#define RG PASTE(r, egister)

BLOCK void fn_801D80B4(RG OSContext* ctx) {
    // clang-format off
    nofralloc

    // If the context was in OSDisableInterrupts,
    // jump back to the beginning of the function
    lis r4, OSDisableInterrupts@ha
    lwz r6, ctx->srr0
    addi r5, r4, OSDisableInterrupts@l
    cmplw r6, r5
    ble _srr0_not_in_disableintr
    lis r4, OSDisableInterrupts+0xC@ha
    addi r0, r4, OSDisableInterrupts+0xC@l
    cmplw r6, r0
    bge _srr0_not_in_disableintr
    stw r5, ctx->srr0

_srr0_not_in_disableintr:
    lwz r0, ctx->gprs[0]
    lwz r1, ctx->gprs[1]
    lwz r2, ctx->gprs[2]
    lhz r4, ctx->state
    rlwinm. r5, r4, 0, 30, 30
    beq _load_saved_gprs

    rlwinm r4, r4, 0, 31, 29
    sth r4, ctx->state
    lmw r5, ctx->gprs[5]
    b _load_special_regs

_load_saved_gprs:
    lmw r13, ctx->gprs[13]

_load_special_regs:
    lwz r4, ctx->gqrs[1]
    mtgqr1 r4
    lwz r4, ctx->gqrs[2]
    mtgqr2 r4
    lwz r4, ctx->gqrs[3]
    mtgqr3 r4
    lwz r4, ctx->gqrs[4]
    mtgqr4 r4
    lwz r4, ctx->gqrs[5]
    mtgqr5 r4
    lwz r4, ctx->gqrs[6]
    mtgqr6 r4
    lwz r4, ctx->gqrs[7]
    mtgqr7 r4

    lwz r4, ctx->cr
    mtcr r4
    lwz r4, ctx->lr
    mtlr r4
    lwz r4, ctx->ctr
    mtctr r4
    lwz r4, ctx->xer
    mtxer r4

    mfmsr r4
    rlwinm r4, r4, 0, 17, 15
    rlwinm r4, r4, 0, 31, 29
    mtmsr r4

    lwz r4, ctx->srr0
    mtsrr0 r4

    lwz r4, ctx->srr1
    mtsrr1 r4

    lwz r4, ctx->gprs[4]
    lwz r3, ctx->gprs[3]

    rfi
    // clang-format on
}
