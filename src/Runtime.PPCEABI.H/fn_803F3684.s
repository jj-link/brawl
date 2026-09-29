# Runtime.PPCEABI.H/fn_803F3684.s (auto_fn_803F3684_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_fn_803F3684_text.s), following the fn_803F1B64.s precedent.
# References __files (MW stdio FILE array) — external, link-resolved.

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
	.4byte fn_803F3684
	.4byte 0x0000006C
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F3684, global
	stwu r1, -0x10(r1)
	mflr r0
	stw r0, 0x14(r1)
	stw r31, 0xc(r1)
	li r31, 0x0
	stw r30, 0x8(r1)
	lis r30, __files@ha
	addi r30, r30, __files@l
	b .L_803F36CC
.L_803F36A8:
	lwz r0, 0x4(r30)
	extrwi. r0, r0, 3, 7
	beq .L_803F36C8
	mr r3, r30
	bl fn_803F5954
	cmpwi r3, 0x0
	beq .L_803F36C8
	li r31, -0x1
.L_803F36C8:
	lwz r30, 0x4c(r30)
.L_803F36CC:
	cmpwi r30, 0x0
	bne .L_803F36A8
	mr r3, r31
	lwz r31, 0xc(r1)
	lwz r30, 0x8(r1)
	lwz r0, 0x14(r1)
	mtlr r0
	addi r1, r1, 0x10
	blr
.endfn fn_803F3684
