# Runtime.PPCEABI.H/fn_803F342C.s (auto_fn_803F342C_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_fn_803F342C_text.s), following the fn_803F1B64.s precedent.
# References lbl_80599BF0 (rodata) and lbl_805A12D8 (.sdata2) — external, link-resolved.

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
	.4byte fn_803F342C
	.4byte 0x00000130
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F342C, global
	stwu r1, -0x10(r1)
	mflr r0
	stw r0, 0x14(r1)
	lbz r0, lbl_805A12D8@sda21(r0)
	stw r31, 0xc(r1)
	mr r31, r3
	cmpwi r0, 0x0
	stw r30, 0x8(r1)
	bne .L_803F346C
	lis r3, lbl_80599BF0@ha
	li r4, 0x0
	addi r3, r3, lbl_80599BF0@l
	li r5, 0x34
	bl memset
	li r0, 0x1
	stb r0, lbl_805A12D8@sda21(r0)
.L_803F346C:
	cmpwi r31, 0x0
	lis r30, lbl_80599BF0@ha
	addi r30, r30, lbl_80599BF0@l
	beq .L_803F3544
	lwz r3, -0x4(r31)
	clrlwi. r0, r3, 31
	bne .L_803F3490
	lwz r5, 0x8(r3)
	b .L_803F349C
.L_803F3490:
	lwz r0, -0x8(r31)
	clrrwi r3, r0, 3
	subi r5, r3, 0x8
.L_803F349C:
	cmplwi r5, 0x44
	bgt .L_803F34B4
	mr r3, r30
	mr r4, r31
	bl fn_803F3240
	b .L_803F3544
.L_803F34B4:
	lwz r0, -0x4(r31)
	subi r4, r31, 0x8
	clrrwi r31, r0, 1
	mr r3, r31
	bl fn_803F3048
	lwz r3, 0x10(r31)
	li r5, 0x0
	rlwinm. r0, r3, 0, 30, 30
	bne .L_803F34F4
	lwz r0, 0xc(r31)
	clrrwi r4, r3, 3
	clrrwi r3, r0, 3
	subi r0, r3, 0x18
	cmplw r4, r0
	bne .L_803F34F4
	li r5, 0x1
.L_803F34F4:
	cmpwi r5, 0x0
	beq .L_803F3544
	lwz r4, 0x4(r31)
	cmplw r4, r31
	bne .L_803F350C
	li r4, 0x0
.L_803F350C:
	lwz r0, 0x0(r30)
	cmplw r0, r31
	bne .L_803F351C
	stw r4, 0x0(r30)
.L_803F351C:
	cmpwi r4, 0x0
	beq .L_803F3530
	lwz r3, 0x0(r31)
	stw r3, 0x0(r4)
	stw r4, 0x4(r3)
.L_803F3530:
	li r0, 0x0
	mr r3, r31
	stw r0, 0x4(r31)
	stw r0, 0x0(r31)
	bl fn_803F2F90
.L_803F3544:
	lwz r0, 0x14(r1)
	lwz r31, 0xc(r1)
	lwz r30, 0x8(r1)
	mtlr r0
	addi r1, r1, 0x10
	blr
.endfn fn_803F342C
