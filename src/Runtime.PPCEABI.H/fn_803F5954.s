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
	.4byte fn_803F5954
	.4byte 0x00000134
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F5954, global
	stwu r1, -0x10(r1)
	mflr r0
	cmpwi r3, 0x0
	stw r0, 0x14(r1)
	stw r31, 0xc(r1)
	mr r31, r3
	stw r30, 0x8(r1)
	bne .L_803F597C
	bl fn_803F3684
	b .L_803F5A70
.L_803F597C:
	lbz r0, 0xa(r3)
	cmpwi r0, 0x0
	bne .L_803F5994
	lwz r4, 0x4(r3)
	extrwi. r0, r4, 3, 7
	bne .L_803F599C
.L_803F5994:
	li r3, -0x1
	b .L_803F5A70
.L_803F599C:
	extrwi r0, r4, 3, 2
	cmplwi r0, 0x1
	bne .L_803F59B0
	li r3, 0x0
	b .L_803F5A70
.L_803F59B0:
	lwz r4, 0x8(r3)
	srwi r0, r4, 29
	cmplwi r0, 0x3
	blt .L_803F59CC
	li r0, 0x2
	rlwimi r4, r0, 29, 0, 2
	stw r4, 0x8(r3)
.L_803F59CC:
	lwz r0, 0x8(r3)
	srwi r0, r0, 29
	cmplwi r0, 0x2
	bne .L_803F59E4
	li r0, 0x0
	stw r0, 0x28(r3)
.L_803F59E4:
	lwz r4, 0x8(r3)
	srwi r0, r4, 29
	cmplwi r0, 0x1
	beq .L_803F5A04
	clrlwi r0, r4, 3
	stw r0, 0x8(r3)
	li r3, 0x0
	b .L_803F5A70
.L_803F5A04:
	lwz r0, 0x4(r3)
	extrwi r0, r0, 3, 7
	cmplwi r0, 0x1
	beq .L_803F5A1C
	li r30, 0x0
	b .L_803F5A28
.L_803F5A1C:
	mr r3, r31
	bl fn_803F5CE0
	mr r30, r3
.L_803F5A28:
	mr r3, r31
	li r4, 0x0
	bl __flush_buffer
	cmpwi r3, 0x0
	beq .L_803F5A54
	li r3, 0x1
	li r0, 0x0
	stb r3, 0xa(r31)
	li r3, -0x1
	stw r0, 0x28(r31)
	b .L_803F5A70
.L_803F5A54:
	lwz r0, 0x8(r31)
	li r4, 0x0
	stw r30, 0x18(r31)
	li r3, 0x0
	clrlwi r0, r0, 3
	stw r0, 0x8(r31)
	stw r4, 0x28(r31)
.L_803F5A70:
	lwz r0, 0x14(r1)
	lwz r31, 0xc(r1)
	lwz r30, 0x8(r1)
	mtlr r0
	addi r1, r1, 0x10
	blr
.endfn fn_803F5954
