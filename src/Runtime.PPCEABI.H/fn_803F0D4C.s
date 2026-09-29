.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x30080000
	.4byte 0x00000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803F0D4C
	.4byte 0x00000080
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F0D4C, global
	stwu r1, -0x20(r1)
	mflr r0
	cmpwi r3, 0x0
	stw r0, 0x24(r1)
	stmw r26, 0x8(r1)
	mr r26, r3
	mr r27, r4
	beq .L_803F0DB8
	cmpwi r4, 0x0
	beq .L_803F0DB0
	lwz r29, -0x10(r3)
	li r31, 0x0
	lwz r30, -0xc(r3)
	mullw r0, r29, r30
	add r28, r3, r0
	b .L_803F0DA8
.L_803F0D8C:
	subf r28, r29, r28
	mr r12, r27
	mr r3, r28
	li r4, -0x1
	mtctr r12
	bctrl
	addi r31, r31, 0x1
.L_803F0DA8:
	cmplw r31, r30
	blt .L_803F0D8C
.L_803F0DB0:
	subi r3, r26, 0x10
	bl __dla__FPv
.L_803F0DB8:
	lmw r26, 0x8(r1)
	lwz r0, 0x24(r1)
	mtlr r0
	addi r1, r1, 0x20
	blr
.endfn fn_803F0D4C
