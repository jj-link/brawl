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
	.4byte fn_803F86E4
	.4byte 0x000000C4
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F86E4, global
	stwu r1, -0x80(r1)
	mflr r0
	stw r0, 0x84(r1)
	stw r31, 0x7c(r1)
	mr r31, r4
	stw r30, 0x78(r1)
	mr r30, r3
	bne cr1, .L_803F8724
	stfd f1, 0x28(r1)
	stfd f2, 0x30(r1)
	stfd f3, 0x38(r1)
	stfd f4, 0x40(r1)
	stfd f5, 0x48(r1)
	stfd f6, 0x50(r1)
	stfd f7, 0x58(r1)
	stfd f8, 0x60(r1)
.L_803F8724:
	stw r3, 0x8(r1)
	mr r3, r30
	stw r4, 0xc(r1)
	li r4, -0x1
	stw r5, 0x10(r1)
	stw r6, 0x14(r1)
	stw r7, 0x18(r1)
	stw r8, 0x1c(r1)
	stw r9, 0x20(r1)
	stw r10, 0x24(r1)
	bl fwide
	cmpwi r3, 0x0
	blt .L_803F8760
	li r3, -0x1
	b .L_803F8790
.L_803F8760:
	addi r7, r1, 0x88
	addi r0, r1, 0x8
	lis r4, 0x200
	lis r3, __FileWrite@ha
	stw r4, 0x68(r1)
	addi r6, r1, 0x68
	mr r4, r30
	mr r5, r31
	stw r7, 0x6c(r1)
	addi r3, r3, __FileWrite@l
	stw r0, 0x70(r1)
	bl __pformatter_803F7CFC
.L_803F8790:
	lwz r0, 0x84(r1)
	lwz r31, 0x7c(r1)
	lwz r30, 0x78(r1)
	mtlr r0
	addi r1, r1, 0x80
	blr
.endfn fn_803F86E4
