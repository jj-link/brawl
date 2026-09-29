# Runtime.PPCEABI.H/fn_803F861C.s (auto_fn_803F861C_text)

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
	.4byte fn_803F861C
	.4byte 0x000000C8
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F861C, global
	stwu r1, -0x80(r1)
	mflr r0
	stw r0, 0x84(r1)
	stw r31, 0x7c(r1)
	stw r30, 0x78(r1)
	mr r30, r3
	bne cr1, .L_803F8658
	stfd f1, 0x28(r1)
	stfd f2, 0x30(r1)
	stfd f3, 0x38(r1)
	stfd f4, 0x40(r1)
	stfd f5, 0x48(r1)
	stfd f6, 0x50(r1)
	stfd f7, 0x58(r1)
	stfd f8, 0x60(r1)
.L_803F8658:
	lis r31, __files@ha
	stw r4, 0xc(r1)
	addi r31, r31, __files@l
	li r4, -0x1
	stw r3, 0x8(r1)
	addi r3, r31, 0x50
	stw r5, 0x10(r1)
	stw r6, 0x14(r1)
	stw r7, 0x18(r1)
	stw r8, 0x1c(r1)
	stw r9, 0x20(r1)
	stw r10, 0x24(r1)
	bl fwide
	cmpwi r3, 0x0
	blt .L_803F869C
	li r3, -0x1
	b .L_803F86CC
.L_803F869C:
	addi r4, r1, 0x88
	addi r0, r1, 0x8
	lis r5, 0x100
	lis r3, __FileWrite@ha
	stw r5, 0x68(r1)
	addi r6, r1, 0x68
	mr r5, r30
	addi r3, r3, __FileWrite@l
	stw r4, 0x6c(r1)
	addi r4, r31, 0x50
	stw r0, 0x70(r1)
	bl __pformatter_803F7CFC
.L_803F86CC:
	lwz r0, 0x84(r1)
	lwz r31, 0x7c(r1)
	lwz r30, 0x78(r1)
	mtlr r0
	addi r1, r1, 0x80
	blr
.endfn fn_803F861C
