.include "macros.inc"
.section extab, "a"
.balign 4
.obj Letb, local
	.4byte 0x68080000
	.4byte 0x00000000
.endobj Letb
.section extabindex, "a"
.balign 4
.obj Leti, local
	.4byte fn_803F8ACC
	.4byte 0x00000170
	.4byte Letb
.endobj Leti
.text
.balign 4
.fn fn_803F8ACC, global
	stwu r1, -0x40(r1)
	mflr r0
	cmplwi r4, 0x2
	stw r0, 0x44(r1)
	stmw r19, 0xc(r1)
	mr r27, r3
	mr r28, r5
	mr r29, r6
	blt .L_803F8C28
	srwi r7, r4, 1
	slwi r0, r5, 1
	addi r31, r7, 0x1
	subi r6, r4, 0x1
	subi r7, r31, 0x1
	mr r30, r4
	mullw r4, r5, r7
	subf r25, r0, r5
	mullw r0, r5, r6
	add r23, r3, r4
	mullw r26, r31, r5
	add r22, r3, r0
.L_803F8B20:
	cmplwi r31, 0x1
	ble .L_803F8B38
	subf r26, r28, r26
	subf r23, r28, r23
	subi r31, r31, 0x1
	b .L_803F8B74
.L_803F8B38:
	subi r3, r22, 0x1
	subi r4, r23, 0x1
	addi r5, r28, 0x1
	b .L_803F8B5C
.L_803F8B48:
	lbz r6, 0x1(r4)
	lbz r0, 0x1(r3)
	extsb r6, r6
	stbu r0, 0x1(r4)
	stbu r6, 0x1(r3)
.L_803F8B5C:
	subic. r5, r5, 0x1
	bne .L_803F8B48
	subi r30, r30, 0x1
	cmplwi r30, 0x1
	beq .L_803F8C28
	subf r22, r28, r22
.L_803F8B74:
	add r0, r26, r25
	mr r24, r31
	add r20, r27, r0
	b .L_803F8C18
.L_803F8B84:
	slwi r24, r24, 1
	mr r21, r20
	subi r0, r24, 0x1
	mullw r0, r28, r0
	cmplw r24, r30
	add r20, r27, r0
	bge .L_803F8BC8
	add r19, r20, r28
	mr r12, r29
	mr r3, r20
	mr r4, r19
	mtctr r12
	bctrl
	cmpwi r3, 0x0
	bge .L_803F8BC8
	mr r20, r19
	addi r24, r24, 0x1
.L_803F8BC8:
	mr r12, r29
	mr r3, r21
	mr r4, r20
	mtctr r12
	bctrl
	cmpwi r3, 0x0
	bge .L_803F8B20
	subi r3, r20, 0x1
	subi r4, r21, 0x1
	addi r5, r28, 0x1
	b .L_803F8C10
.L_803F8BF4:
	lbz r6, 0x1(r4)
	lbz r0, 0x1(r3)
	extsb r6, r6
	stb r0, 0x1(r4)
	addi r4, r4, 0x1
	stb r6, 0x1(r3)
	addi r3, r3, 0x1
.L_803F8C10:
	subic. r5, r5, 0x1
	bne .L_803F8BF4
.L_803F8C18:
	slwi r0, r24, 1
	cmplw r0, r30
	ble .L_803F8B84
	b .L_803F8B20
.L_803F8C28:
	lmw r19, 0xc(r1)
	lwz r0, 0x44(r1)
	mtlr r0
	addi r1, r1, 0x40
	blr
.endfn fn_803F8ACC
