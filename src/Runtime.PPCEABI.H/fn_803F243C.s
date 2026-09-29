# Runtime.PPCEABI.H/fn_803F243C.s (auto_fn_803F243C_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_fn_803F243C_text.s), following the fn_803F1B64.s precedent.
# References jumptable_80493DD4 (external data, resolved at link).

.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x50080000
	.4byte 0x00000054
	.4byte 0x01250010
	.4byte 0x00000000
	.4byte 0x8E000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803F243C
	.4byte 0x0000050C
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F243C, global
	stwu r1, -0x30(r1)
	mflr r0
	stw r0, 0x34(r1)
	stmw r22, 0x8(r1)
	li r31, 0x0
	mr r25, r3
	mr r26, r4
	mr r27, r5
	lis r30, jumptable_80493DD4@ha
.L_803F2460:
	lwz r29, 0x8(r26)
	cmpwi r29, 0x0
	bne .L_803F24B4
	mr r3, r25
	mr r4, r26
	bl fn_803F1EC4
	mr r4, r26
	bl fn_803F1B64
	lwz r0, 0x0(r26)
	cmpwi r0, 0x0
	bne .L_803F2490
	bl fn_803F07D4
.L_803F2490:
	lwz r3, 0x0(r26)
	lhz r0, 0x0(r3)
	extrwi. r0, r0, 1, 27
	beq .L_803F24A8
	lwz r0, 0x27c(r25)
	b .L_803F24AC
.L_803F24A8:
	lwz r0, 0x284(r25)
.L_803F24AC:
	stw r0, 0x288(r25)
	b .L_803F2460
.L_803F24B4:
	lbz r28, 0x0(r29)
	clrlwi r0, r28, 25
	cmplwi r0, 0x10
	bgt .L_803F2920
	addi r3, r30, jumptable_80493DD4@l
	slwi r0, r0, 2
	lwzx r3, r3, r0
	mtctr r3
	bctr
	lwz r3, 0x0(r26)
	lhz r0, 0x2(r29)
	add r0, r3, r0
	stw r0, 0x8(r26)
	b .L_803F2924
	lwz r3, 0x288(r25)
	li r4, -0x1
	lha r0, 0x2(r29)
	lwz r12, 0x4(r29)
	add r3, r3, r0
	mtctr r12
	bctrl
	lwz r3, 0x8(r26)
	addi r0, r3, 0x8
	stw r0, 0x8(r26)
	b .L_803F2924
	lbz r0, 0x1(r29)
	srawi. r0, r0, 7
	beq .L_803F253C
	lha r0, 0x2(r29)
	slwi r0, r0, 2
	add r3, r25, r0
	lwz r0, 0x200(r3)
	extsb r0, r0
	b .L_803F2548
.L_803F253C:
	lwz r3, 0x288(r25)
	lha r0, 0x2(r29)
	lbzx r0, r3, r0
.L_803F2548:
	extsb. r0, r0
	beq .L_803F256C
	lwz r3, 0x288(r25)
	li r4, -0x1
	lha r0, 0x4(r29)
	lwz r12, 0x8(r29)
	add r3, r3, r0
	mtctr r12
	bctrl
.L_803F256C:
	lwz r3, 0x8(r26)
	addi r0, r3, 0xc
	stw r0, 0x8(r26)
	b .L_803F2924
	lbz r0, 0x1(r29)
	srawi. r0, r0, 7
	beq .L_803F259C
	lha r0, 0x2(r29)
	slwi r0, r0, 2
	add r3, r25, r0
	lwz r3, 0x200(r3)
	b .L_803F25A8
.L_803F259C:
	lwz r3, 0x288(r25)
	lha r0, 0x2(r29)
	lwzx r3, r3, r0
.L_803F25A8:
	lwz r12, 0x4(r29)
	li r4, -0x1
	mtctr r12
	bctrl
	lwz r3, 0x8(r26)
	addi r0, r3, 0x8
	stw r0, 0x8(r26)
	b .L_803F2924
	lhz r23, 0x4(r29)
	lhz r24, 0x6(r29)
	lwz r4, 0x288(r25)
	mullw r0, r24, r23
	lha r3, 0x2(r29)
	add r22, r4, r3
	add r22, r22, r0
	b .L_803F2604
.L_803F25E8:
	lwz r12, 0x8(r29)
	subf r22, r24, r22
	mr r3, r22
	li r4, -0x1
	mtctr r12
	bctrl
	subi r23, r23, 0x1
.L_803F2604:
	cmpwi r23, 0x0
	bgt .L_803F25E8
	lwz r3, 0x8(r26)
	addi r0, r3, 0xc
	stw r0, 0x8(r26)
	b .L_803F2924
	lbz r0, 0x1(r29)
	srawi. r0, r0, 7
	beq .L_803F263C
	lha r0, 0x2(r29)
	slwi r0, r0, 2
	add r3, r25, r0
	lwz r3, 0x200(r3)
	b .L_803F2648
.L_803F263C:
	lwz r3, 0x288(r25)
	lha r0, 0x2(r29)
	lwzx r3, r3, r0
.L_803F2648:
	lwz r0, 0x4(r29)
	li r4, 0x0
	lwz r12, 0x8(r29)
	add r3, r3, r0
	mtctr r12
	bctrl
	lwz r3, 0x8(r26)
	addi r0, r3, 0xc
	stw r0, 0x8(r26)
	b .L_803F2924
	lbz r0, 0x1(r29)
	srawi. r0, r0, 7
	beq .L_803F2690
	lha r0, 0x2(r29)
	slwi r0, r0, 2
	add r3, r25, r0
	lwz r3, 0x200(r3)
	b .L_803F269C
.L_803F2690:
	lwz r3, 0x288(r25)
	lha r0, 0x2(r29)
	lwzx r3, r3, r0
.L_803F269C:
	lwz r0, 0x4(r29)
	li r4, -0x1
	lwz r12, 0x8(r29)
	add r3, r3, r0
	mtctr r12
	bctrl
	lwz r3, 0x8(r26)
	addi r0, r3, 0xc
	stw r0, 0x8(r26)
	b .L_803F2924
	lbz r4, 0x1(r29)
	extrwi. r0, r4, 1, 25
	beq .L_803F26E4
	lha r0, 0x4(r29)
	slwi r0, r0, 2
	add r3, r25, r0
	lwz r5, 0x200(r3)
	b .L_803F26F0
.L_803F26E4:
	lwz r3, 0x288(r25)
	lha r0, 0x4(r29)
	lwzx r5, r3, r0
.L_803F26F0:
	extrwi. r0, r4, 1, 24
	beq .L_803F2710
	lha r0, 0x2(r29)
	slwi r0, r0, 2
	add r3, r25, r0
	lwz r0, 0x200(r3)
	extsh r0, r0
	b .L_803F271C
.L_803F2710:
	lwz r3, 0x288(r25)
	lha r0, 0x2(r29)
	lhax r0, r3, r0
.L_803F271C:
	cmpwi r0, 0x0
	beq .L_803F273C
	lwz r0, 0x8(r29)
	li r4, 0x0
	lwz r12, 0xc(r29)
	add r3, r5, r0
	mtctr r12
	bctrl
.L_803F273C:
	lwz r3, 0x8(r26)
	addi r0, r3, 0x10
	stw r0, 0x8(r26)
	b .L_803F2924
	lbz r0, 0x1(r29)
	srawi. r0, r0, 7
	beq .L_803F276C
	lha r0, 0x2(r29)
	slwi r0, r0, 2
	add r3, r25, r0
	lwz r24, 0x200(r3)
	b .L_803F2778
.L_803F276C:
	lwz r3, 0x288(r25)
	lha r0, 0x2(r29)
	lwzx r24, r3, r0
.L_803F2778:
	lwz r23, 0x8(r29)
	lwz r22, 0xc(r29)
	lwz r3, 0x4(r29)
	mullw r0, r22, r23
	add r24, r24, r3
	add r24, r24, r0
	b .L_803F27B0
.L_803F2794:
	lwz r12, 0x10(r29)
	subf r24, r22, r24
	mr r3, r24
	li r4, -0x1
	mtctr r12
	bctrl
	subi r23, r23, 0x1
.L_803F27B0:
	cmpwi r23, 0x0
	bgt .L_803F2794
	lwz r3, 0x8(r26)
	addi r0, r3, 0x14
	stw r0, 0x8(r26)
	b .L_803F2924
	lbz r0, 0x1(r29)
	srawi. r0, r0, 7
	beq .L_803F27E8
	lha r0, 0x2(r29)
	slwi r0, r0, 2
	add r3, r25, r0
	lwz r3, 0x200(r3)
	b .L_803F27F4
.L_803F27E8:
	lwz r3, 0x288(r25)
	lha r0, 0x2(r29)
	lwzx r3, r3, r0
.L_803F27F4:
	lwz r12, 0x4(r29)
	mtctr r12
	bctrl
	lwz r3, 0x8(r26)
	addi r0, r3, 0x8
	stw r0, 0x8(r26)
	b .L_803F2924
	lbz r4, 0x1(r29)
	extrwi. r0, r4, 1, 25
	beq .L_803F2830
	lha r0, 0x4(r29)
	slwi r0, r0, 2
	add r3, r25, r0
	lwz r3, 0x200(r3)
	b .L_803F283C
.L_803F2830:
	lwz r3, 0x288(r25)
	lha r0, 0x4(r29)
	lwzx r3, r3, r0
.L_803F283C:
	extrwi. r0, r4, 1, 24
	beq .L_803F285C
	lha r0, 0x2(r29)
	slwi r0, r0, 2
	add r4, r25, r0
	lwz r0, 0x200(r4)
	extsb r0, r0
	b .L_803F2868
.L_803F285C:
	lwz r4, 0x288(r25)
	lha r0, 0x2(r29)
	lbzx r0, r4, r0
.L_803F2868:
	extsb. r0, r0
	beq .L_803F287C
	lwz r12, 0x8(r29)
	mtctr r12
	bctrl
.L_803F287C:
	lwz r3, 0x8(r26)
	addi r0, r3, 0xc
	stw r0, 0x8(r26)
	b .L_803F2924
	cmplw r27, r29
	beq .L_803F2934
	addi r0, r29, 0xc
	stw r0, 0x8(r26)
	b .L_803F2924
	cmplw r27, r29
	beq .L_803F2934
	addi r0, r29, 0x10
	stw r0, 0x8(r26)
	b .L_803F2924
	lwz r3, 0x288(r25)
	lha r0, 0x2(r29)
	add r3, r3, r0
	lwz r12, 0x8(r3)
	cmpwi r12, 0x0
	beq .L_803F28F0
	lwz r3, 0x0(r3)
	lwz r0, 0x298(r25)
	cmplw r0, r3
	bne .L_803F28E4
	stw r12, 0x29c(r25)
	b .L_803F28F0
.L_803F28E4:
	li r4, -0x1
	mtctr r12
	bctrl
.L_803F28F0:
	lwz r3, 0x8(r26)
	addi r0, r3, 0x4
	stw r0, 0x8(r26)
	b .L_803F2924
	cmplw r27, r29
	beq .L_803F2934
	lhz r0, 0x2(r29)
	slwi r0, r0, 2
	add r3, r0, r29
	addi r0, r3, 0xc
	stw r0, 0x8(r26)
	b .L_803F2924
.L_803F2920:
	bl fn_803F07D4
.L_803F2924:
	rlwinm. r0, r28, 0, 24, 24
	beq .L_803F2460
	stw r31, 0x8(r26)
	b .L_803F2460
.L_803F2934:
	lmw r22, 0x8(r1)
	lwz r0, 0x34(r1)
	mtlr r0
	addi r1, r1, 0x30
	blr
