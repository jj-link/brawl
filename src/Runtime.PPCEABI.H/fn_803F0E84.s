# Runtime.PPCEABI.H/fn_803F0E84.s (auto_fn_803F0E84_text)

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
	.4byte fn_803F0E84
	.4byte 0x00000080
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F0E84, global
	stwu r1, -0x20(r1)
	mflr r0
	cmpwi r3, 0x0
	stw r0, 0x24(r1)
	stw r31, 0x1c(r1)
	mr r31, r4
	stw r30, 0x18(r1)
	mr r30, r3
	bne .L_803F0ED0
	lis r4, lbl_80493D38@ha
	lis r3, lbl_8041F418@ha
	addi r4, r4, lbl_80493D38@l
	lis r5, fn_803F0F04@ha
	addi r3, r3, lbl_8041F418@l
	stw r4, 0x8(r1)
	addi r3, r3, 0x4
	addi r4, r1, 0x8
	addi r5, r5, fn_803F0F04@l
	bl fn_803F2E4C
.L_803F0ED0:
	lwzx r3, r30, r31
	lwz r30, 0x0(r3)
	cmpwi r30, 0x0
	bne .L_803F0EE8
	li r3, lbl_8059FF30@sda21
	b .L_803F0EEC
.L_803F0EE8:
	mr r3, r30
.L_803F0EEC:
	lwz r0, 0x24(r1)
	lwz r31, 0x1c(r1)
	lwz r30, 0x18(r1)
	mtlr r0
	addi r1, r1, 0x20
	blr
.endfn fn_803F0E84
