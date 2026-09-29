# Runtime.PPCEABI.H/fn_803F1D14.s (auto_fn_803F1D14_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_fn_803F1D14_text.s), following the fn_803F1B64.s precedent.

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
	.4byte fn_803F1D14
	.4byte 0x000001B0
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F1D14, global
	stwu r1, -0x10(r1)
	mflr r0
	stw r0, 0x14(r1)
	stw r31, 0xc(r1)
	mr r31, r3
	stw r30, 0x8(r1)
.L_803F1D2C:
	lwz r4, 0x8(r31)
	cmpwi r4, 0x0
	beq .L_803F1D44
	lbz r5, 0x0(r4)
	rlwinm. r0, r5, 0, 24, 24
	beq .L_803F1DB4
.L_803F1D44:
	lwz r3, 0x0(r31)
	lwz r4, 0x18(r31)
	lhz r3, 0x0(r3)
	lwz r30, 0x0(r4)
	srawi. r0, r3, 11
	beq .L_803F1D6C
	rlwinm r0, r3, 29, 24, 28
	subf r3, r0, r30
	lwz r0, -0x4(r3)
	stw r0, 0x20(r31)
.L_803F1D6C:
	lwz r3, 0x4(r30)
	mr r4, r31
	bl fn_803F1B64
	lwz r0, 0x0(r31)
	cmpwi r0, 0x0
	bne .L_803F1D88
	bl fn_803F07D4
.L_803F1D88:
	stw r30, 0x18(r31)
	lwz r3, 0x0(r31)
	lhz r0, 0x0(r3)
	extrwi. r0, r0, 1, 27
	beq .L_803F1DA0
	lwz r30, 0x20(r31)
.L_803F1DA0:
	lwz r0, 0x8(r31)
	stw r30, 0x1c(r31)
	cmpwi r0, 0x0
	bne .L_803F1E80
	b .L_803F1D2C
.L_803F1DB4:
	cmplwi r5, 0x10
	bgt .L_803F1E7C
	lis r3, jumptable_80493D90@ha
	slwi r0, r5, 2
	addi r3, r3, jumptable_80493D90@l
	lwzx r3, r3, r0
	mtctr r3
	bctr
	addi r0, r4, 0x8
	stw r0, 0x8(r31)
	b .L_803F1E80
	addi r0, r4, 0xc
	stw r0, 0x8(r31)
	b .L_803F1E80
	addi r0, r4, 0x8
	stw r0, 0x8(r31)
	b .L_803F1E80
	addi r0, r4, 0xc
	stw r0, 0x8(r31)
	b .L_803F1E80
	addi r0, r4, 0xc
	stw r0, 0x8(r31)
	b .L_803F1E80
	addi r0, r4, 0x10
	stw r0, 0x8(r31)
	b .L_803F1E80
	addi r0, r4, 0x14
	stw r0, 0x8(r31)
	b .L_803F1E80
	addi r0, r4, 0x8
	stw r0, 0x8(r31)
	b .L_803F1E80
	addi r0, r4, 0xc
	stw r0, 0x8(r31)
	b .L_803F1E80
	addi r0, r4, 0xc
	stw r0, 0x8(r31)
	b .L_803F1E80
	addi r0, r4, 0x10
	stw r0, 0x8(r31)
	b .L_803F1E80
	addi r0, r4, 0x4
	stw r0, 0x8(r31)
	b .L_803F1E80
	lhz r0, 0x2(r4)
	slwi r0, r0, 2
	add r3, r0, r4
	addi r0, r3, 0xc
	stw r0, 0x8(r31)
	b .L_803F1E80
.L_803F1E7C:
	bl fn_803F07D4
.L_803F1E80:
	lwz r4, 0x8(r31)
	lbz r0, 0x0(r4)
	clrlwi r3, r0, 25
	cmplwi r3, 0x1
	bne .L_803F1EAC
	lwz r3, 0x0(r31)
	lhz r0, 0x2(r4)
	add r3, r3, r0
	stw r3, 0x8(r31)
	lbz r0, 0x0(r3)
	clrlwi r3, r0, 25
.L_803F1EAC:
	lwz r0, 0x14(r1)
	lwz r31, 0xc(r1)
	lwz r30, 0x8(r1)
	mtlr r0
	addi r1, r1, 0x10
	blr
