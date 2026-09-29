# Runtime.PPCEABI.H/__close_all.s (auto_close_all_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_close_all_text.s), following the fn_803F1B64.s precedent.
# References __files (MW stdio FILE array) — external, link-resolved.

.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x18080000
	.4byte 0x00000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte __close_all
	.4byte 0x000000A4
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn __close_all, global
	stwu r1, -0x20(r1)
	mflr r0
	stw r0, 0x24(r1)
	stw r31, 0x1c(r1)
	li r31, 0x0
	stw r30, 0x18(r1)
	li r30, 0x3
	stw r29, 0x14(r1)
	lis r29, __files@ha
	addi r29, r29, __files@l
	b .L_803F35DC
.L_803F3588:
	lwz r0, 0x4(r29)
	extrwi. r0, r0, 3, 7
	beq .L_803F359C
	mr r3, r29
	bl fn_803F5898
.L_803F359C:
	mr r3, r29
	lwz r29, 0x4c(r29)
	lbz r0, 0xc(r3)
	cmpwi r0, 0x0
	beq .L_803F35B8
	bl fn_803F342C
	b .L_803F35DC
.L_803F35B8:
	lwz r0, 0x4(r3)
	rlwimi r0, r30, 22, 7, 9
	cmpwi r29, 0x0
	stw r0, 0x4(r3)
	beq .L_803F35DC
	lbz r0, 0xc(r29)
	cmpwi r0, 0x0
	beq .L_803F35DC
	stw r31, 0x4c(r3)
.L_803F35DC:
	cmpwi r29, 0x0
	bne .L_803F3588
	lwz r0, 0x24(r1)
	lwz r31, 0x1c(r1)
	lwz r30, 0x18(r1)
	lwz r29, 0x14(r1)
	mtlr r0
	addi r1, r1, 0x20
	blr
.endfn __close_all
