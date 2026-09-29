.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x90080000
	.4byte 0x00000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803FC0AC
	.4byte 0x000004C4
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803FC0AC, global
	stwu r1, -0x60(r1)
	mflr r0
	cmpwi r3, 0x0
	stw r0, 0x64(r1)
	stmw r14, 0x18(r1)
	li r27, 0x0
	mr r15, r3
	mr r16, r4
	stw r7, 0x8(r1)
	mr r17, r5
	mr r18, r6
	mr r19, r8
	mr r20, r9
	li r28, 0x1
	li r26, 0x0
	li r24, 0x0
	li r25, 0x0
	li r22, 0x0
	li r23, 0x0
	stw r27, 0x0(r9)
	stw r27, 0x0(r8)
	blt .L_803FC11C
	cmpwi r3, 0x1
	beq .L_803FC11C
	cmpwi r3, 0x24
	bgt .L_803FC11C
	cmpwi r4, 0x1
	bge .L_803FC124
.L_803FC11C:
	li r28, 0x40
	b .L_803FC144
.L_803FC124:
	mr r12, r17
	mr r3, r18
	li r4, 0x0
	li r5, 0x0
	mtctr r12
	li r27, 0x1
	bctrl
	mr r21, r3
.L_803FC144:
	cmpwi r15, 0x0
	beq .L_803FC168
	mr r6, r15
	srawi r5, r15, 31
	li r3, -0x1
	li r4, -0x1
	bl __div2u
	mr r22, r4
	mr r23, r3
.L_803FC168:
	lis r3, lbl_804942B8@ha
	li r30, 0x1
	li r31, -0x1
	lis r14, jumptable_804946B4@ha
	addi r29, r3, lbl_804942B8@l
	b .L_803FC4F8
.L_803FC180:
	cmplwi r28, 0x10
	bgt .L_803FC4F8
	addi r3, r14, jumptable_804946B4@l
	slwi r0, r28, 2
	lwzx r3, r3, r0
	mtctr r3
	bctr
	cmpwi r21, 0x0
	li r0, 0x0
	blt .L_803FC1B0
	cmpwi r21, 0x100
	blt .L_803FC1B4
.L_803FC1B0:
	li r0, 0x1
.L_803FC1B4:
	cmpwi r0, 0x0
	beq .L_803FC1C4
	li r0, 0x0
	b .L_803FC1D8
.L_803FC1C4:
	lwz r3, 0x38(r29)
	slwi r0, r21, 1
	lwz r3, 0x8(r3)
	lhzx r0, r3, r0
	rlwinm r0, r0, 0, 23, 23
.L_803FC1D8:
	cmpwi r0, 0x0
	beq .L_803FC204
	mr r12, r17
	mr r3, r18
	li r4, 0x0
	li r5, 0x0
	mtctr r12
	bctrl
	mr r21, r3
	addi r26, r26, 0x1
	b .L_803FC4F8
.L_803FC204:
	cmpwi r21, 0x2b
	bne .L_803FC230
	mr r12, r17
	mr r3, r18
	li r4, 0x0
	li r5, 0x0
	mtctr r12
	addi r27, r27, 0x1
	bctrl
	mr r21, r3
	b .L_803FC25C
.L_803FC230:
	cmpwi r21, 0x2d
	bne .L_803FC25C
	mr r12, r17
	mr r3, r18
	li r4, 0x0
	li r5, 0x0
	mtctr r12
	addi r27, r27, 0x1
	bctrl
	mr r21, r3
	stw r30, 0x0(r19)
.L_803FC25C:
	li r28, 0x2
	b .L_803FC4F8
	cmpwi r15, 0x0
	beq .L_803FC274
	cmpwi r15, 0x10
	bne .L_803FC2A4
.L_803FC274:
	cmpwi r21, 0x30
	bne .L_803FC2A4
	mr r12, r17
	mr r3, r18
	li r28, 0x4
	li r4, 0x0
	li r5, 0x0
	mtctr r12
	addi r27, r27, 0x1
	bctrl
	mr r21, r3
	b .L_803FC4F8
.L_803FC2A4:
	li r28, 0x8
	b .L_803FC4F8
	cmpwi r21, 0x58
	beq .L_803FC2BC
	cmpwi r21, 0x78
	bne .L_803FC2E8
.L_803FC2BC:
	mr r12, r17
	mr r3, r18
	li r15, 0x10
	li r28, 0x8
	li r4, 0x0
	li r5, 0x0
	mtctr r12
	addi r27, r27, 0x1
	bctrl
	mr r21, r3
	b .L_803FC4F8
.L_803FC2E8:
	cmpwi r15, 0x0
	bne .L_803FC2F4
	li r15, 0x8
.L_803FC2F4:
	li r28, 0x10
	b .L_803FC4F8
	cmpwi r15, 0x0
	bne .L_803FC308
	li r15, 0xa
.L_803FC308:
	li r0, 0x0
	srawi r0, r0, 31
	xor r0, r23, r0
	or. r0, r22, r0
	bne .L_803FC338
	mr r6, r15
	srawi r5, r15, 31
	li r3, -0x1
	li r4, -0x1
	bl __div2u
	mr r22, r4
	mr r23, r3
.L_803FC338:
	cmpwi r21, 0x0
	li r0, 0x0
	blt .L_803FC34C
	cmpwi r21, 0x100
	blt .L_803FC350
.L_803FC34C:
	li r0, 0x1
.L_803FC350:
	cmpwi r0, 0x0
	beq .L_803FC360
	li r0, 0x0
	b .L_803FC374
.L_803FC360:
	lwz r3, 0x38(r29)
	slwi r0, r21, 1
	lwz r3, 0x8(r3)
	lhzx r0, r3, r0
	rlwinm r0, r0, 0, 28, 28
.L_803FC374:
	cmpwi r0, 0x0
	beq .L_803FC3A0
	subi r21, r21, 0x30
	cmpw r21, r15
	blt .L_803FC470
	cmpwi r28, 0x10
	li r28, 0x40
	bne .L_803FC398
	li r28, 0x20
.L_803FC398:
	addi r21, r21, 0x30
	b .L_803FC4F8
.L_803FC3A0:
	cmpwi r21, 0x0
	li r0, 0x0
	blt .L_803FC3B4
	cmpwi r21, 0x100
	blt .L_803FC3B8
.L_803FC3B4:
	li r0, 0x1
.L_803FC3B8:
	cmpwi r0, 0x0
	beq .L_803FC3C8
	li r0, 0x0
	b .L_803FC3DC
.L_803FC3C8:
	lwz r3, 0x38(r29)
	slwi r0, r21, 1
	lwz r3, 0x8(r3)
	lhzx r0, r3, r0
	clrlwi r0, r0, 31
.L_803FC3DC:
	cmpwi r0, 0x0
	beq .L_803FC424
	cmpwi r21, 0x0
	li r0, 0x0
	blt .L_803FC3F8
	cmpwi r21, 0x100
	blt .L_803FC3FC
.L_803FC3F8:
	li r0, 0x1
.L_803FC3FC:
	cmpwi r0, 0x0
	beq .L_803FC40C
	mr r3, r21
	b .L_803FC418
.L_803FC40C:
	lwz r3, 0x38(r29)
	lwz r3, 0xc(r3)
	lbzx r3, r3, r21
.L_803FC418:
	subi r0, r3, 0x37
	cmpw r0, r15
	blt .L_803FC43C
.L_803FC424:
	cmpwi r28, 0x10
	bne .L_803FC434
	li r28, 0x20
	b .L_803FC4F8
.L_803FC434:
	li r28, 0x40
	b .L_803FC4F8
.L_803FC43C:
	cmpwi r21, 0x0
	li r0, 0x0
	blt .L_803FC450
	cmpwi r21, 0x100
	blt .L_803FC454
.L_803FC450:
	li r0, 0x1
.L_803FC454:
	cmpwi r0, 0x0
	beq .L_803FC460
	b .L_803FC46C
.L_803FC460:
	lwz r3, 0x38(r29)
	lwz r3, 0xc(r3)
	lbzx r21, r3, r21
.L_803FC46C:
	subi r21, r21, 0x37
.L_803FC470:
	subfc r0, r24, r22
	subfe r0, r25, r23
	subfe r0, r22, r22
	neg. r0, r0
	beq .L_803FC488
	stw r30, 0x0(r20)
.L_803FC488:
	mulhwu r3, r24, r15
	srawi r5, r15, 31
	srawi r6, r21, 31
	mullw r4, r25, r15
	add r4, r3, r4
	mullw r3, r24, r5
	mullw r0, r24, r15
	add r7, r4, r3
	subfc r5, r0, r31
	subfe r4, r7, r31
	subfc r3, r21, r5
	subfe r3, r6, r4
	subfe r3, r5, r5
	neg. r3, r3
	beq .L_803FC4C8
	stw r30, 0x0(r20)
.L_803FC4C8:
	srawi r4, r21, 31
	mr r12, r17
	addc r24, r0, r21
	mr r3, r18
	adde r25, r7, r4
	li r28, 0x10
	li r4, 0x0
	li r5, 0x0
	mtctr r12
	addi r27, r27, 0x1
	bctrl
	mr r21, r3
.L_803FC4F8:
	cmpw r27, r16
	bgt .L_803FC510
	cmpwi r21, -0x1
	beq .L_803FC510
	rlwinm. r0, r28, 0, 25, 26
	beq .L_803FC180
.L_803FC510:
	andi. r0, r28, 0x34
	bne .L_803FC52C
	lwz r3, 0x8(r1)
	li r24, 0x0
	li r25, 0x0
	stw r24, 0x0(r3)
	b .L_803FC53C
.L_803FC52C:
	add r3, r27, r26
	subi r0, r3, 0x1
	lwz r3, 0x8(r1)
	stw r0, 0x0(r3)
.L_803FC53C:
	mr r12, r17
	mr r3, r18
	mr r4, r21
	li r5, 0x1
	mtctr r12
	bctrl
	mr r4, r24
	mr r3, r25
	lmw r14, 0x18(r1)
	lwz r0, 0x64(r1)
	mtlr r0
	addi r1, r1, 0x60
	blr
.endfn fn_803FC0AC
