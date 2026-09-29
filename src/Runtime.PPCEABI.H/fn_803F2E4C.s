# Runtime.PPCEABI.H/fn_803F2E4C.s (auto_03_803F2E4C_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_03_803F2E4C_text.s), following the fn_803F1B64.s precedent.
# References lbl_8041F478 (rodata) and lbl_8059E9B0 (.sdata) — external, link-resolved.

.include "macros.inc"

.text
.balign 4
.fn fn_803F2E4C, global
	stwu r1, -0x2c0(r1)
	mflr r0
	stw r0, 0x2c4(r1)
	stw r3, 0x8(r1)
	stw r4, 0xc(r1)
	stw r5, 0x10(r1)
	stmw r13, 0x24c(r1)
	stfd f14, 0xf8(r1)
	addi r3, r1, 0x100
	psq_stx f14, r0, r3, 0, qr0
	stfd f15, 0x108(r1)
	addi r3, r1, 0x110
	psq_stx f15, r0, r3, 0, qr0
	stfd f16, 0x118(r1)
	addi r3, r1, 0x120
	psq_stx f16, r0, r3, 0, qr0
	stfd f17, 0x128(r1)
	addi r3, r1, 0x130
	psq_stx f17, r0, r3, 0, qr0
	stfd f18, 0x138(r1)
	addi r3, r1, 0x140
	psq_stx f18, r0, r3, 0, qr0
	stfd f19, 0x148(r1)
	addi r3, r1, 0x150
	psq_stx f19, r0, r3, 0, qr0
	stfd f20, 0x158(r1)
	addi r3, r1, 0x160
	psq_stx f20, r0, r3, 0, qr0
	stfd f21, 0x168(r1)
	addi r3, r1, 0x170
	psq_stx f21, r0, r3, 0, qr0
	stfd f22, 0x178(r1)
	addi r3, r1, 0x180
	psq_stx f22, r0, r3, 0, qr0
	stfd f23, 0x188(r1)
	addi r3, r1, 0x190
	psq_stx f23, r0, r3, 0, qr0
	stfd f24, 0x198(r1)
	addi r3, r1, 0x1a0
	psq_stx f24, r0, r3, 0, qr0
	stfd f25, 0x1a8(r1)
	addi r3, r1, 0x1b0
	psq_stx f25, r0, r3, 0, qr0
	stfd f26, 0x1b8(r1)
	addi r3, r1, 0x1c0
	psq_stx f26, r0, r3, 0, qr0
	stfd f27, 0x1c8(r1)
	addi r3, r1, 0x1d0
	psq_stx f27, r0, r3, 0, qr0
	stfd f28, 0x1d8(r1)
	addi r3, r1, 0x1e0
	psq_stx f28, r0, r3, 0, qr0
	stfd f29, 0x1e8(r1)
	addi r3, r1, 0x1f0
	psq_stx f29, r0, r3, 0, qr0
	stfd f30, 0x1f8(r1)
	addi r3, r1, 0x200
	psq_stx f30, r0, r3, 0, qr0
	stfd f31, 0x208(r1)
	addi r3, r1, 0x210
	psq_stx f31, r0, r3, 0, qr0
	mfcr r3
	stw r3, 0x298(r1)
	lwz r3, 0x0(r1)
	lwz r4, 0x4(r3)
	stw r3, 0x29c(r1)
	stw r3, 0x2a4(r1)
	stw r4, 0x2a8(r1)
	lwz r3, 0x8(r1)
	stw r3, 0x2ac(r1)
	lwz r3, 0xc(r1)
	stw r3, 0x2b0(r1)
	lwz r3, 0x10(r1)
	stw r3, 0x2b4(r1)
	addi r3, r1, 0x18
	bl fn_803F2A4C
	nop
	lwz r0, 0x2c4(r1)
	mtlr r0
	addi r1, r1, 0x2c0
	blr
.endfn fn_803F2E4C
.fn fn_803F2F90, global
	stwu r1, -0x20(r1)
	mflr r0
	stw r0, 0x24(r1)
	stw r31, 0x1c(r1)
	stw r30, 0x18(r1)
	stw r29, 0x14(r1)
	mr r29, r3
	lwz r0, lbl_8059E9B0@sda21(r0)
	cmpwi r0, -0x1
	bne .L_803F3020
	lis r31, lbl_8041F478@ha
	addi r3, r31, lbl_8041F478@l
	crclr cr1eq
	bl OSReport
	addi r3, r31, lbl_8041F478@l
	addi r3, r3, 0x36
	crclr cr1eq
	bl OSReport
	bl fn_801D7154
	mr r30, r3
	bl fn_801D713C
	mr r31, r3
	mr r3, r30
	mr r4, r31
	li r5, 0x1
	bl fn_801D7050
	mr r30, r3
	bl fn_801D7184
	addi r0, r30, 0x1f
	clrrwi r30, r31, 5
	mr r4, r30
	clrrwi r3, r0, 5
	bl fn_801D70C0
	bl fn_801D7040
	mr r3, r30
	bl fn_801D7184
.L_803F3020:
	lwz r3, lbl_8059E9B0@sda21(r0)
	mr r4, r29
	bl fn_801D6FC8
	lwz r0, 0x24(r1)
	lwz r31, 0x1c(r1)
	lwz r30, 0x18(r1)
	lwz r29, 0x14(r1)
	mtlr r0
	addi r1, r1, 0x20
	blr
.endfn fn_803F2F90
