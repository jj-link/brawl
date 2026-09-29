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
	.4byte fn_803F5B48
	.4byte 0x000000F0
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F5B48, global
	stwu r1, -0x10(r1)
	mflr r0
	cmpwi r3, 0x0
	li r7, 0x0
	stw r0, 0x14(r1)
	li r8, 0x0
	stw r31, 0xc(r1)
	stw r30, 0x8(r1)
	mr r30, r4
	bge .L_803F5B78
	neg r3, r3
	li r7, 0x1
.L_803F5B78:
	mr r6, r4
.L_803F5B7C:
	divwu r0, r3, r5
	mullw r0, r0, r5
	subf r9, r0, r3
	cmpwi r9, 0x9
	ble .L_803F5BA4
	addi r0, r9, 0x37
	addi r8, r8, 0x1
	stb r0, 0x0(r6)
	addi r6, r6, 0x1
	b .L_803F5BB4
.L_803F5BA4:
	addi r0, r9, 0x30
	addi r8, r8, 0x1
	stb r0, 0x0(r6)
	addi r6, r6, 0x1
.L_803F5BB4:
	divwu. r3, r3, r5
	bne .L_803F5B7C
	cmpwi r7, 0x0
	beq .L_803F5BD0
	li r0, 0x2d
	stbx r0, r4, r8
	addi r8, r8, 0x1
.L_803F5BD0:
	li r0, 0x0
	mr r3, r30
	stbx r0, r4, r8
	li r31, 0x0
	bl strlen
	subi r6, r3, 0x1
	mr r3, r30
	add r4, r30, r6
	b .L_803F5C14
.L_803F5BF4:
	lbz r5, 0x0(r3)
	addi r31, r31, 0x1
	lbz r0, 0x0(r4)
	subi r6, r6, 0x1
	stb r0, 0x0(r3)
	addi r3, r3, 0x1
	stb r5, 0x0(r4)
	subi r4, r4, 0x1
.L_803F5C14:
	cmpw r31, r6
	blt .L_803F5BF4
	mr r3, r30
	lwz r31, 0xc(r1)
	lwz r30, 0x8(r1)
	lwz r0, 0x14(r1)
	mtlr r0
	addi r1, r1, 0x10
	blr
.endfn fn_803F5B48
