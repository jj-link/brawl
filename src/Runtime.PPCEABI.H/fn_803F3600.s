# Runtime.PPCEABI.H/fn_803F3600.s (auto_fn_803F3600_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_fn_803F3600_text.s), following the fn_803F1B64.s precedent.

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
	.4byte fn_803F3600
	.4byte 0x00000084
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F3600, global
	stwu r1, -0x10(r1)
	mflr r0
	stw r0, 0x14(r1)
	stw r31, 0xc(r1)
	li r31, 0x0
	stw r30, 0x8(r1)
	lis r30, __files@ha
	addi r30, r30, __files@l
	b .L_803F3660
.L_803F3624:
	lwz r3, 0x4(r30)
	extrwi. r0, r3, 3, 7
	beq .L_803F365C
	extrwi. r0, r3, 1, 6
	beq .L_803F365C
	lwz r0, 0x8(r30)
	srwi r0, r0, 29
	cmplwi r0, 0x1
	bne .L_803F365C
	mr r3, r30
	bl fn_803F5954
	cmpwi r3, 0x0
	beq .L_803F365C
	li r31, -0x1
.L_803F365C:
	lwz r30, 0x4c(r30)
.L_803F3660:
	cmpwi r30, 0x0
	bne .L_803F3624
	mr r3, r31
	lwz r31, 0xc(r1)
	lwz r30, 0x8(r1)
	lwz r0, 0x14(r1)
	mtlr r0
	addi r1, r1, 0x10
	blr
.endfn fn_803F3600
