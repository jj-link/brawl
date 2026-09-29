.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x20080000
	.4byte 0x00000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803FC8AC
	.4byte 0x000000D0
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803FC8AC, global
	stwu r1, -0x20(r1)
	mflr r0
	stw r0, 0x24(r1)
	stw r31, 0x1c(r1)
	mr r31, r6
	stw r30, 0x18(r1)
	mr r30, r5
	stw r29, 0x14(r1)
	mr r29, r4
	stw r28, 0x10(r1)
	mr r28, r3
	bl fn_801D536C
	rlwinm. r0, r3, 0, 2, 2
	bne .L_803FC944
	lwz r0, lbl_805A12E8@sda21(r0)
	li r3, 0x0
	cmpwi r0, 0x0
	bne .L_803FC910
	lis r3, 0x1
	subi r3, r3, 0x1f00
	bl fn_802285C0
	cmpwi r3, 0x0
	bne .L_803FC910
	li r0, 0x1
	stw r0, lbl_805A12E8@sda21(r0)
.L_803FC910:
	cmpwi r3, 0x0
	beq .L_803FC920
	li r3, 0x1
	b .L_803FC95C
.L_803FC920:
	lwz r4, 0x0(r30)
	mr r3, r29
	bl fn_80228608
	cmpwi r3, 0x0
	beq .L_803FC944
	li r0, 0x0
	li r3, 0x1
	stw r0, 0x0(r30)
	b .L_803FC95C
.L_803FC944:
	mr r3, r28
	mr r4, r29
	mr r5, r30
	mr r6, r31
	bl fn_80405520
	li r3, 0x0
.L_803FC95C:
	lwz r0, 0x24(r1)
	lwz r31, 0x1c(r1)
	lwz r30, 0x18(r1)
	lwz r29, 0x14(r1)
	lwz r28, 0x10(r1)
	mtlr r0
	addi r1, r1, 0x20
	blr
.endfn fn_803FC8AC
