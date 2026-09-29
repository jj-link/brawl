# Runtime.PPCEABI.H/fn_803F3240.s (auto_fn_803F3240_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_fn_803F3240_text.s), following the fn_803F1B64.s precedent.
# References lbl_8041F4E8 (rodata) — external, link-resolved.

.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x10080000
	.4byte 0x00000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803F3240
	.4byte 0x000001EC
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F3240, global
	stwu r1, -0x10(r1)
	mflr r0
	lis r6, lbl_8041F4E8@ha
	li r7, 0x0
	stw r0, 0x14(r1)
	addi r6, r6, lbl_8041F4E8@l
	stw r31, 0xc(r1)
	mr r31, r3
	stw r30, 0x8(r1)
	b .L_803F3270
.L_803F3268:
	addi r6, r6, 0x4
	addi r7, r7, 0x1
.L_803F3270:
	lwz r0, 0x0(r6)
	cmplw r5, r0
	bgt .L_803F3268
	subi r6, r4, 0x4
	lwz r4, -0x4(r4)
	slwi r0, r7, 3
	add r3, r3, r0
	lwz r0, 0xc(r4)
	cmpwi r0, 0x0
	bne .L_803F3300
	lwz r5, 0x8(r3)
	cmplw r5, r4
	beq .L_803F3300
	lwz r0, 0x4(r3)
	cmplw r0, r4
	bne .L_803F32C8
	lwz r0, 0x0(r5)
	stw r0, 0x8(r3)
	lwz r5, 0x4(r3)
	lwz r0, 0x0(r5)
	stw r0, 0x4(r3)
	b .L_803F3300
.L_803F32C8:
	lwz r0, 0x4(r4)
	lwz r5, 0x0(r4)
	stw r0, 0x4(r5)
	lwz r0, 0x0(r4)
	lwz r5, 0x4(r4)
	stw r0, 0x0(r5)
	lwz r5, 0x8(r3)
	stw r5, 0x4(r4)
	lwz r5, 0x0(r5)
	stw r5, 0x0(r4)
	stw r4, 0x4(r5)
	lwz r5, 0x4(r4)
	stw r4, 0x0(r5)
	stw r4, 0x8(r3)
.L_803F3300:
	lwz r0, 0xc(r4)
	stw r0, 0x4(r6)
	stw r6, 0xc(r4)
	lwz r0, 0x10(r4)
	subic. r0, r0, 0x1
	stw r0, 0x10(r4)
	bne .L_803F3414
	lwz r0, 0x8(r3)
	cmplw r0, r4
	bne .L_803F3330
	lwz r0, 0x4(r4)
	stw r0, 0x8(r3)
.L_803F3330:
	lwz r0, 0x4(r3)
	cmplw r0, r4
	bne .L_803F3344
	lwz r0, 0x0(r4)
	stw r0, 0x4(r3)
.L_803F3344:
	lwz r0, 0x4(r4)
	lwz r5, 0x0(r4)
	stw r0, 0x4(r5)
	lwz r0, 0x0(r4)
	lwz r5, 0x4(r4)
	stw r0, 0x0(r5)
	lwz r0, 0x8(r3)
	cmplw r0, r4
	bne .L_803F3370
	li r0, 0x0
	stw r0, 0x8(r3)
.L_803F3370:
	lwz r0, 0x4(r3)
	cmplw r0, r4
	bne .L_803F3384
	li r0, 0x0
	stw r0, 0x4(r3)
.L_803F3384:
	subi r4, r4, 0x8
	lwz r0, 0x4(r4)
	clrrwi r30, r0, 1
	mr r3, r30
	bl fn_803F3048
	lwz r3, 0x10(r30)
	li r5, 0x0
	rlwinm. r0, r3, 0, 30, 30
	bne .L_803F33C4
	lwz r0, 0xc(r30)
	clrrwi r4, r3, 3
	clrrwi r3, r0, 3
	subi r0, r3, 0x18
	cmplw r4, r0
	bne .L_803F33C4
	li r5, 0x1
.L_803F33C4:
	cmpwi r5, 0x0
	beq .L_803F3414
	lwz r4, 0x4(r30)
	cmplw r4, r30
	bne .L_803F33DC
	li r4, 0x0
.L_803F33DC:
	lwz r0, 0x0(r31)
	cmplw r0, r30
	bne .L_803F33EC
	stw r4, 0x0(r31)
.L_803F33EC:
	cmpwi r4, 0x0
	beq .L_803F3400
	lwz r3, 0x0(r30)
	stw r3, 0x0(r4)
	stw r4, 0x4(r3)
.L_803F3400:
	li r0, 0x0
	mr r3, r30
	stw r0, 0x4(r30)
	stw r0, 0x0(r30)
	bl fn_803F2F90
.L_803F3414:
	lwz r0, 0x14(r1)
	lwz r31, 0xc(r1)
	lwz r30, 0x8(r1)
	mtlr r0
	addi r1, r1, 0x10
	blr
.endfn fn_803F3240
