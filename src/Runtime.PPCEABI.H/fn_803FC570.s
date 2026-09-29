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
	.4byte fn_803FC570
	.4byte 0x000000A8
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803FC570, global
	stwu r1, -0x30(r1)
	mflr r0
	lis r7, 0x8000
	lis r6, fn_803FA078@ha
	stw r0, 0x34(r1)
	li r0, 0x0
	addi r8, r1, 0xc
	addi r9, r1, 0x8
	stw r31, 0x2c(r1)
	mr r31, r4
	subi r4, r7, 0x1
	addi r7, r1, 0x10
	stw r30, 0x28(r1)
	mr r30, r3
	mr r3, r5
	addi r5, r6, fn_803FA078@l
	stw r30, 0x18(r1)
	addi r6, r1, 0x18
	stw r0, 0x1c(r1)
	bl fn_803FBC7C
	cmpwi r31, 0x0
	beq .L_803FC5D4
	lwz r0, 0x10(r1)
	add r0, r30, r0
	stw r0, 0x0(r31)
.L_803FC5D4:
	lwz r0, 0x8(r1)
	cmpwi r0, 0x0
	beq .L_803FC5F0
	li r0, 0x22
	li r3, -0x1
	stw r0, lbl_805A12E0@sda21(r0)
	b .L_803FC600
.L_803FC5F0:
	lwz r0, 0xc(r1)
	cmpwi r0, 0x0
	beq .L_803FC600
	neg r3, r3
.L_803FC600:
	lwz r0, 0x34(r1)
	lwz r31, 0x2c(r1)
	lwz r30, 0x28(r1)
	mtlr r0
	addi r1, r1, 0x30
	blr
.endfn fn_803FC570
