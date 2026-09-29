# Runtime.PPCEABI.H/fn_803F3B40.s (auto_fn_803F3B40_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_fn_803F3B40_text.s), following the fn_803F1B64.s precedent.
# References jumptable_80493FA0 (.data) and lbl_8041F500 (rodata) — external, link-resolved.

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
	.4byte fn_803F3B40
	.4byte 0x0000036C
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F3B40, global
	stwu r1, -0x70(r1)
	mflr r0
	stw r0, 0x74(r1)
	addi r0, r4, 0x40
	cmplwi r0, 0x48
	stw r31, 0x6c(r1)
	mr r31, r3
	stw r30, 0x68(r1)
	mr r30, r4
	bgt .L_803F3D74
	lis r5, jumptable_80493FA0@ha
	slwi r0, r0, 2
	addi r5, r5, jumptable_80493FA0@l
	lwzx r5, r5, r0
	mtctr r5
	bctr
	lis r4, lbl_8041F500@ha
	li r5, -0x14
	addi r4, r4, lbl_8041F500@l
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, -0x10
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0x2e
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, -0xa
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0x55
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, -0x5
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0x6d
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, -0x3
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0x7a
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, -0x3
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0x81
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, -0x2
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0x87
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, -0x2
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0x8d
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, -0x2
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0x92
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, -0x1
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0x96
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, -0x1
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0x9a
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, -0x1
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0x9d
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, 0x0
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0x9f
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, 0x0
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0xa1
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, 0x0
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0xa3
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, 0x0
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0xa5
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, 0x1
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0xa7
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, 0x1
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0xaa
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, 0x1
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0xad
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, 0x2
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0xb0
	bl fn_803F3A54
	b .L_803F3E94
	lis r4, lbl_8041F500@ha
	li r5, 0x2
	addi r4, r4, lbl_8041F500@l
	addi r4, r4, 0xb4
	bl fn_803F3A54
	b .L_803F3E94
.L_803F3D74:
	srwi r0, r4, 31
	addi r3, r1, 0x34
	add r0, r0, r4
	srawi r4, r0, 1
	bl fn_803F3B40
	addi r4, r1, 0x34
	mr r3, r31
	mr r5, r4
	bl fn_803F37CC
	clrlwi. r0, r30, 31
	beq .L_803F3E94
	lhz r3, 0x0(r31)
	cmpwi r30, 0x0
	lhz r0, 0x2(r31)
	sth r3, 0x8(r1)
	sth r0, 0xa(r1)
	lhz r3, 0x4(r31)
	lhz r0, 0x6(r31)
	sth r3, 0xc(r1)
	sth r0, 0xe(r1)
	lhz r3, 0x8(r31)
	lhz r0, 0xa(r31)
	sth r3, 0x10(r1)
	sth r0, 0x12(r1)
	lhz r3, 0xc(r31)
	lhz r0, 0xe(r31)
	sth r3, 0x14(r1)
	sth r0, 0x16(r1)
	lhz r3, 0x10(r31)
	lhz r0, 0x12(r31)
	sth r3, 0x18(r1)
	sth r0, 0x1a(r1)
	lhz r3, 0x14(r31)
	lhz r0, 0x16(r31)
	sth r3, 0x1c(r1)
	sth r0, 0x1e(r1)
	lhz r3, 0x18(r31)
	lhz r0, 0x1a(r31)
	sth r3, 0x20(r1)
	sth r0, 0x22(r1)
	lhz r3, 0x1c(r31)
	lhz r0, 0x1e(r31)
	sth r3, 0x24(r1)
	sth r0, 0x26(r1)
	lhz r3, 0x20(r31)
	lhz r0, 0x22(r31)
	sth r3, 0x28(r1)
	sth r0, 0x2a(r1)
	lhz r3, 0x24(r31)
	lhz r0, 0x26(r31)
	sth r3, 0x2c(r1)
	sth r0, 0x2e(r1)
	lhz r0, 0x28(r31)
	sth r0, 0x30(r1)
	ble .L_803F3E6C
	lis r4, lbl_8041F500@ha
	addi r3, r1, 0x34
	addi r4, r4, lbl_8041F500@l
	li r5, 0x0
	addi r4, r4, 0xa1
	bl fn_803F3A54
	b .L_803F3E84
.L_803F3E6C:
	lis r4, lbl_8041F500@ha
	addi r3, r1, 0x34
	addi r4, r4, lbl_8041F500@l
	li r5, -0x1
	addi r4, r4, 0x9d
	bl fn_803F3A54
.L_803F3E84:
	mr r3, r31
	addi r4, r1, 0x8
	addi r5, r1, 0x34
	bl fn_803F37CC
.L_803F3E94:
	lwz r0, 0x74(r1)
	lwz r31, 0x6c(r1)
	lwz r30, 0x68(r1)
	mtlr r0
	addi r1, r1, 0x70
	blr
.endfn fn_803F3B40
