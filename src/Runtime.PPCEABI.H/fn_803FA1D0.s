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
	.4byte fn_803FA1D0
	.4byte 0x000000B0
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803FA1D0, global
	stwu r1, -0x10(r1)
	mflr r0
	cmpwi r3, 0x1
	stw r0, 0x14(r1)
	stw r31, 0xc(r1)
	stw r30, 0x8(r1)
	mr r30, r3
	blt .L_803FA1F8
	cmpwi r3, 0x7
	ble .L_803FA200
.L_803FA1F8:
	li r3, -0x1
	b .L_803FA268
.L_803FA200:
	subi r0, r3, 0x1
	lis r4, lbl_80599F28@ha
	slwi r5, r0, 2
	addi r4, r4, lbl_80599F28@l
	lwzx r31, r4, r5
	cmplwi r31, 0x1
	beq .L_803FA224
	li r0, 0x0
	stwx r0, r4, r5
.L_803FA224:
	cmplwi r31, 0x1
	beq .L_803FA23C
	cmpwi r31, 0x0
	bne .L_803FA244
	cmpwi r3, 0x1
	bne .L_803FA244
.L_803FA23C:
	li r3, 0x0
	b .L_803FA268
.L_803FA244:
	cmpwi r31, 0x0
	bne .L_803FA254
	li r3, 0x0
	bl exit
.L_803FA254:
	mr r12, r31
	mr r3, r30
	mtctr r12
	bctrl
	li r3, 0x0
.L_803FA268:
	lwz r0, 0x14(r1)
	lwz r31, 0xc(r1)
	lwz r30, 0x8(r1)
	mtlr r0
	addi r1, r1, 0x10
	blr
.endfn fn_803FA1D0
